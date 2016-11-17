#ifndef IMGSCANNER_H
#define IMGSCANNER_H
#include "IBackgroundWorker.h"
#include "_Twain.h"
#include <AQString.h>
#include <opencv2/opencv.hpp>
#include <qmutex.h>

//using namespace ACUONG;


class ImageScanner : public IBackgroundWorker{
	Q_OBJECT
	//Enumeration
public:
	enum WorkingState{
		stateNone = 0,
		stateScan,

	};
	//constructor
public:
	ImageScanner(std::string& fileName, int idx):_fileName(fileName)
	{
		try{
			if (_scanner.twInitialize(idx) != TWRC_SUCCESS){
				throw exception("Unable to load scanner driver!");
			}
			if (_scanner.twListDevices() == TWRC_FAILURE) {
				throw exception("No Image Acquisitiion Device on system!");
			}
			on_scanner_id_changed(5);
		}
		catch (exception& ex){
			emit sig_error(ex.what());
		}
	}
	~ImageScanner(){}
public:
	void scan(){
		_state = stateScan;
	}

	void on_scanner_id_changed(int idx){
		emit sig_error("We got here!");
		try{
			_scanner.twCloseSource();
			if (_scanner.twSelectDevice(idx) != TWRC_SUCCESS){
				emit sig_error("Could not connect to scanner!");
				return;
			}
			else{
				_scanner.twSetCapability(CAP_XFERCOUNT, TWTY_INT16, 1);
				emit sig_status_changed("Success!");
			}
		}
		catch (exception& ex){
			emit sig_error(ex.what());
		}
	}

	void test_slot(){
		emit sig_error("Test ");
	}

public:
	void do_work(){
		cv::Mat img(100, 100, CV_8UC3);
		emit sig_status_changed("Thread is running...");
		_state = stateScan;
		while (1){
			switch (_state){
			case stateNone:
				_sleep(10);
				//_idx++;
				//emit sig_status_changed(AQString("Current index=") + _idx);
				//img = cv::Scalar(0, 0, 0);
				//cv::line(img, cv::Point(0, 0), cv::Point(100, 100), cv::Scalar(255, 0, 0));
				//emit sig_image_captured(img);
				//emit sig_error(AQString("Current index=") + _idx);
				break;
			case stateScan:
				_scan();
				_state = stateNone;
				break;
			}
		}
	}
	//Fields
protected:
	void _scan(){
		//DO scan stuff
		emit sig_status_changed(tr("Scanning..."));
		if (_scanner.twScan(_fileName.c_str()) == TWRC_FAILURE) {
			emit sig_error("Could not complete scanning process!");
			return;
		}
		cv::Mat img=cv::imread(_fileName);
		emit sig_image_captured(img);
		emit sig_status_changed("Left image captured successfully!");
	}

public:
	WorkingState _state = stateNone;
	int _idx = 0;
	CTwain _scanner;
	int _scanner_idx=-1;
	std::string _fileName;
};
#endif