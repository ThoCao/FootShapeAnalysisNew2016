#ifndef IBACKGROUNDWORKER_H
#define IBACKGROUNDWORKER_H
#include "precomp.h"	

class IBackgroundWorker: public QObject{
	Q_OBJECT

public slots:
	virtual void do_work() = 0;
	virtual void on_scanner_id_changed(int idx) = 0;
	virtual void test_slot()=0;
signals:
	void sig_status_changed(QString msg);
	void sig_error(QString msg);
	void sig_progress_changed(int val);
	void sig_image_captured(cv::Mat img);
};

#endif