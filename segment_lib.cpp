#include "segment_lib.h"


Painter::Painter(QWidget *parent) :
modified(false)
{

}

Painter::~Painter()
{
}

bool Painter::openImage(const QString &fileName){
	QImage image;
	if (!image.load(fileName)) return false;
	setImage(image);
	return true;
}

void Painter::setImage(const QImage &image, int scaleDirection){
	switch (scaleDirection){
	case WIDTH_DIR:
		//	if (image.width() > width())  {
	{	resizeFactor = (float)image.width() / width();
	QSize newSize(image.width() / resizeFactor, image.height() / resizeFactor);
	QImage sImage = image.scaled(newSize, Qt::KeepAspectRatio);
	theImage = sImage.convertToFormat(QImage::Format_RGB32);
	break;
	}
		//theImage = image.convertToFormat(QImage::Format_RGB32);
		//resizeFactor = 1.0;
		break;
	case HEIGHT_DIR:
		//	if (image.height() > height())  {
	{	resizeFactor = (float)image.height() / height();
	QSize newSize(image.width() / resizeFactor, image.height() / resizeFactor);
	QImage sImage = image.scaled(newSize, Qt::KeepAspectRatio);
	theImage = sImage.convertToFormat(QImage::Format_RGB32);
	break;
	}
		//theImage = image.convertToFormat(QImage::Format_RGB32);
		//resizeFactor = 1.0;
		//break;
	case NONE:
		theImage = image.convertToFormat(QImage::Format_RGB32);
		//		resizeFactor = 1.0;
		break;
	default:
		break;
	}
	setPixmap(QPixmap::fromImage(theImage));
}

void Painter::mousePressEvent(QMouseEvent *event){
	if (event->button() == Qt::LeftButton){
		switch (paintMode){
		case PAINT_POINT:
			firstPos = event->pos();
			drawPoint(firstPos);
			points.push_back(firstPos);
			modified = false;
			break;
		case PAINT_CURVE:
			firstPos = event->pos();
			curvePoints.push_back(firstPos);
			nextPos = firstPos;
			break;
		case PAINT_ROI:
			firstPos = event->pos();
			//		drawPoint(firstPos, Qt::red, 3);
			points.push_back(firstPos);
			break;
		case PAINT_NONE:
		default:
			break;
		}
	}
}

void Painter::mouseMoveEvent(QMouseEvent *event){
	if (event->buttons() == Qt::LeftButton){
		QImage image;
		QPoint currPos;
		switch (paintMode){
		case PAINT_ROI:
			image = theImage;
			currPos = event->pos();
			drawRectangle(image, firstPos, currPos);
			break;
		case PAINT_CURVE:
			drawLine(nextPos, event->pos(), Qt::green, 2);
			nextPos = event->pos();
			curvePoints.push_back(nextPos);
			break;
		case PAINT_NONE:
		default:
			break;
		}
	}
}

void Painter::mouseReleaseEvent(QMouseEvent *event){
	if (event->button() == Qt::LeftButton){
		QPoint currPos;
		switch (paintMode){
		case PAINT_ROI:
			currPos = event->pos();
			drawRectangle(theImage, firstPos, currPos);
			points.push_back(currPos);
			paintMode = PAINT_NONE;
			break;
		case PAINT_CURVE:
			drawLine(nextPos, firstPos, Qt::green, 2);
			paintMode = PAINT_NONE;
			break;
		case PAINT_NONE:
		default:
			break;
		}
	}
}

void Painter::drawPoint(const QPoint &p, const QColor &cl, const int sz){
	
	QPainter painter(&theImage);
	painter.setPen(QPen(cl, sz, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter.drawPoint(p);
	setPixmap(QPixmap::fromImage(theImage));
}

void Painter::drawPoint_temp(const QPoint &p, const QColor &cl, const int sz){

	//theImage_temp = theImage;

	theImage_temp = theImage.copy();

	QPainter painter(&theImage_temp);
	painter.setPen(QPen(cl, sz, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter.drawPoint(p);
	setPixmap(QPixmap::fromImage(theImage_temp));
}

void Painter::drawPoint_temp2(const QPoint &p, const QColor &cl, const int sz){

	QPainter painter(&theImage_temp);
	painter.setPen(QPen(cl, sz, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter.drawPoint(p);
	setPixmap(QPixmap::fromImage(theImage_temp));
}

void Painter::drawLine(const QPoint &point1, const QPoint &point2, const QColor &color, const int size){
	QPainter painter(&theImage);
	painter.setPen(QPen(color, size, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter.drawLine(point1, point2);
	setPixmap(QPixmap::fromImage(theImage));
}

void Painter::drawLine_temp(const QPoint &point1, const QPoint &point2, const QColor &color, const int size){
	QPainter painter(&theImage_temp);
	painter.setPen(QPen(color, size, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter.drawLine(point1, point2);
	setPixmap(QPixmap::fromImage(theImage_temp));
}

void Painter::drawExtenLine(const QPoint &p1, const QPoint &p2, const int exten, const QColor &color, const int size){
	float anpha = atan2(p2.y() - p1.y(), p2.x() - p1.x());
	QPoint A_, B_;
	A_.setX(p1.x() - exten*cos(anpha));
	A_.setY(p1.y() - exten*sin(anpha));
	B_.setX(p2.x() + exten*cos(anpha));
	B_.setY(p2.y() + exten*sin(anpha));
	drawLine(A_, B_, color, size);
}

void Painter::drawRectangle(QImage &image, const QPoint &point1, const QPoint &point2, const QColor &color, const int size){
	QPainter painter(&image);
	painter.setPen(QPen(color, size, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	int width = point2.x() - point1.x();
	int height = point2.y() - point1.y();
	painter.drawRect(point1.x(), point1.y(), width, height);
	setPixmap(QPixmap::fromImage(image));
}

void Painter::saveImage(const QString &fileName){
	theImage.save(fileName);
}

QPoint Painter::centroidPolygon(vector<QPoint> &v){
	v.push_back(v[0]);
	double A = 0, Cx = 0, Cy = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		A += (v[i].x()*v[i + 1].y() - v[i + 1].x()*v[i].y());
		Cx += (v[i].x() + v[i + 1].x())*(v[i].x()*v[i + 1].y() - v[i + 1].x()*v[i].y());
		Cy += (v[i].y() + v[i + 1].y())*(v[i].x()*v[i + 1].y() - v[i + 1].x()*v[i].y());
	}
	float x = Cx / A / 3, y = Cy / A / 3;
	return QPoint(x, y);
}


Line::Line(const float a_, const float b_) :a(a_), b(b_){}

Line::Line(const QPointF &p1, const QPointF &p2){
	float dx = p1.x() - p2.x();
	float dy = p1.y() - p2.y();
	a = dy / dx;
	b = p1.y() - a*p1.x();
}

Line::~Line()
{
}

Line Line::setLine(const QPointF &p1, const QPointF &p2){
	return Line(p1, p2);
}

float Line::lengthSegment(const QPointF &p1, const QPointF &p2){
	return sqrt((p1.x() - p2.x())*(p1.x() - p2.x()) + (p1.y() - p2.y())*(p1.y() - p2.y()));
}

QPointF Line::intersect2Lines(const Line &l1, const Line &l2){
	float x = (l2.b - l1.b) / (l1.a - l2.a);
	float y = (l1.a*l2.b - l2.a*l1.b) / (l1.a - l2.a);
	return QPointF(x, y);
}

vector<QPoint> Line::divideSegment(const QPoint &p1, const QPoint &p2, int n){
	vector<QPoint> pts;
	for (int i = 1; i < n; i++){
		float t = float(i) / n;
		QPoint pt;
		pt.setX(p1.x()*(1 - t) + p2.x()*t);
		pt.setY(p1.y()*(1 - t) + p2.y()*t);
		pts.push_back(pt);
	}
	return pts;
}

float Line::Angle2Lines(const Line &line1, const Line &line2){
	return atan((line1.a - line2.a) / (1 + line1.a*line2.a))*(180 / PI);
}
