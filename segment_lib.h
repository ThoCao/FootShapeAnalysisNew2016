#pragma once

#include <QtCore/qglobal.h>
#include <QColor>
#include <QImage>
#include <QPoint>
#include <QPainter>
#include <QMouseEvent>
#include <QLabel>
#include <vector>

using namespace std;
#define PI 3.1415926535897932384626433832795

enum ScaleDirection { NONE, WIDTH_DIR, HEIGHT_DIR };
enum { PAINT_NONE, PAINT_POINT, PAINT_ROI, PAINT_CURVE };

class Painter :
	public QLabel
{
public:
	Painter(QWidget *parent = 0);
	~Painter();

	bool openImage(const QString &filename);

	// put image on painter
	void setImage(const QImage &image, int scaleDirection = HEIGHT_DIR);

	// image of painter
	QImage theImage;

	QImage theImage_temp;

	// collected points from mouse tasking
	vector<QPoint> points, curvePoints;

	// image resize factor
	float resizeFactor;

	// choose for drawing or setting roi
	int paintMode;

	// is image modified ?
	bool modified;

public:
	void drawPoint(const QPoint &point, const QColor &color = Qt::white, const int size = 8);
	void drawPoint_temp(const QPoint &point, const QColor &color = Qt::white, const int size = 8);
	void drawPoint_temp2(const QPoint &point, const QColor &color = Qt::white, const int size = 8);
	void drawLine(const QPoint &point1, const QPoint &point2, const QColor &color = Qt::red, const int size = 1);
	void drawLine_temp(const QPoint &point1, const QPoint &point2, const QColor &color = Qt::red, const int size = 1);
	void drawExtenLine(const QPoint &point1, const QPoint &point2, const int exten = 0, const QColor &color = Qt::red, const int size = 1);
	void drawRectangle(QImage &image, const QPoint &point1, const QPoint &point2, const QColor &color = Qt::white, const int size = 1);
	QPoint centroidPolygon(vector<QPoint> &polyPoints);
	void saveImage(const QString &fileName);
protected:
	void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
private:
	QPoint firstPos, nextPos;
};

class  Line
{
public:
	Line(const float a_, const float b_);
	Line(const QPointF &point1, const QPointF &point2);

	~Line();

	// angle between two lines
	static float Angle2Lines(const Line &line1, const Line &line2);

	// set line from two points
	static Line setLine(const QPointF &point1, const QPointF &point2);

	// length of segment between two points
	static float lengthSegment(const QPointF &point1, const QPointF &point2);

	// intersect point by two lines
	static QPointF intersect2Lines(const Line &line1, const Line &line2);

	// divide a segment between two points into many segments
	static vector<QPoint> divideSegment(const QPoint &point1, const QPoint &point2, int numSegments = 2);
public:
	float a, b;
};


