#pragma once
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QtWidgets/QLabel>
#include <opencv2\opencv.hpp>
#include <QtWidgets/QApplication>
using namespace cv;

class ImgView:public QLabel
{
	Q_OBJECT
public:
	explicit ImgView(QWidget* parent=0):QLabel(parent){}
	~ImgView(void){}

public: 
	void SetImage(Mat& img){
		//if(img.rows>512||img.cols>512);
		Mat image;
		if(width()<30)return;
		float r=min(width()/(float)img.cols,height()/(float)img.rows)*0.95;
		cv::resize(img,image,Size(),r,r);
		//pyrDown(img,image,Size(image.cols/2,image.rows/2));
		if(image.type()==CV_8UC1){
			QImage qimg(image.data, image.cols,image.rows,image.step,QImage::Format_Indexed8);
			setPixmap(QPixmap::fromImage(qimg));			
		}
		else {
			cvtColor(image, image, CV_BGR2RGB);
			QImage qimg(image.data, image.cols,image.rows,image.step,QImage::Format_RGB888);
			setPixmap(QPixmap::fromImage(qimg));
		}	
	}
	void SetImage(QImage& image){
		setPixmap(QPixmap::fromImage(image));
	}
	void UpdateView(){
		qApp->processEvents();	
	}
protected:
	//virtual void enterEvent ( QEvent * ev );
   // virtual void leaveEvent ( QEvent * ev );
	virtual void mouseMoveEvent ( QMouseEvent * ev ){
		emit mouseMove(ev);
	}
    virtual void mousePressEvent ( QMouseEvent * ev ){
		emit mousePressed(ev);
	}
	virtual void mouseReleaseEvent ( QMouseEvent * ev ){
		emit mouseReleased(ev);
	}

private:
	bool firstClick;
public:
	int firstX;
	int firstY;

signals:
		void mousePressed(QMouseEvent* ev);
		void mouseReleased(QMouseEvent* ev);
		void mouseMove(QMouseEvent* ev);
};

