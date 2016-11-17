#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTimer>
#include <QCloseEvent>
#include <QFileSystemModel>
#include <QStringListModel>
#include <QInputDialog>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
//#include <qeuckrcodec.h>  // adding by k2y
#include <qstring.h>         // adding by k2y
#include <qtextcodec.h>      // adding by k2y



#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>  // adding by k2y
#include "_Twain.h"
#include "segment_lib.h"
#include "phidget21.h"
#include <iostream>
#include <fstream>

#include <winnetwk.h>
#include <LM.h>
#include <tchar.h>
#include <string>

/*Dr.Phu*/
//#include "ImageScanner.h"
#include <qthread.h>
/*Tho*/
#include "ListWebcam.h"
#include "LoadCellKalmanFilter.h"

//#include <direct.h>   // Edited by k2y
//#include <atlstr.h>   // Edited by k2y

#pragma comment(lib, "mpr.lib")
#pragma comment(lib,"Netapi32.lib")

#define THOCAO 1
#define factor_scale_patter 30.0

using namespace std;
using namespace cv;
//using namespace ACUONG;

enum statusProcess{None, Scan, Analysis, Detect};


//class MyThread : public QThread{
//	Q_OBJECT
//public:
//	void do_scan(){
//		emit scan();
//	}
//signals:
//	void scan();
//};

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);

signals:
	void sig_left_scanner_id_changed(int idx);
	void sig_right_scanner_id_changed(int idx);
	void test_signal();

private:
	// For Webcamera
	VideoCapture webcamera;
	QTimer *webcameraTimer;
	int webcamUpperIndex = -1;
	int webcamSideIndex=-1;
	Mat webcamFrame_grid;
	Mat webcamFrame;
	bool bodyView = false;

	Mat upperView;
	//MyThread *_threadLeft;


	// For Scanners
	CTwain leftScanner, rightScanner;
	int leftScannerIndexBuf[2], rightScannerIndexBuf[2];
	int leftScannerIndex, rightScannerIndex;
	QString leftScannerName, rightScannerName;
	Mat leftScanImage, rightScanImage;
	Mat footImage;
	Painter *leftPainter, *rightPainter;
	QTimer *leftDraw, *rightDraw;
	float leftImageScale, rightImageScale;
	float leftScannerScale, rightScannerScale;

	float leftFootLength, rightFootLength;
	float leftFootAngle, rightFootAngle;
	bool isLeftScannerConnect, isRightScannerConnect;

	// For network
	NETRESOURCE netResource;
	QList<QString> sharedDriveList;
	// For data processing
	QFileSystemModel *dirModel, *fileModel;
	QStringList listSysFiles;
	QString serverPath;
	QString sysPath;
	QModelIndex treeIndex;

	// For loadcells
	CPhidgetBridgeHandle bridge;
	QString bridgeName;
	float calibBridgeParameters[4][3];
	QTimer *bridgeTimer, *bridgeCalibTimer;
	int selectedBridgeIndex;
	int selectedGainIndex;
	int bridgeRate;
	bool bridgeIsSet;
	double bridgeValue, realValue, calibValues[4][2];
	/*
	Edited by Tho
	Date: 7/25/2016
	*/
	LoadCellKalmanFilter kalman_fillter_leftFoot;
	LoadCellKalmanFilter kalman_fillter_rightFoot;
	std::vector<double> calibValue_sensor[4];
	std::vector<double> calibVaue_real;
	std::vector<double> re_Real_Value_sensor[4];
	bool flag_calibValue_save = 0;
	int number_calibValue_save = 0;
	double real_offset[4];

	/*Modifief Pr.Kim: Dont show image before choose camera*/
	bool flag_dont_show_image_before_camera_chossed = 0;

	// initial connect loadcel flag;
	bool flag_loadcell_connection_status = 0;


	QTimer *leftDetect, *rightDetect;
	int leftAreaDetected, rightAreaDetected;
	int leftProcess, rightProcess;
	int leftDone, rightDone;
	QPoint leftCenters[2], rightCenters[2];



private:
	void refreshGUI();
	void WebcameraConnect();

	void initializeScanners();
	void fixScanError(QString scannerName, Mat &scannerImage);
	void loadScannerSetting();
	void leftMeasuring(vector<QPoint> &points);
	void rightMeasuring(vector<QPoint> &points);

	/*9/20/2016*/
	void findSharedItems(LPWSTR lpIpAddress);
	void defineTreeView();
	void showServerEntries();
	void showSysFiles();

	void saveImage(QString tailName, Mat &image);

	//For loadcells
	void openBridge();
	void setBridge();
	void loadBridgeSetting();
	/*9/20/2016*/
	//void bridgeCalibration();
	// Edited by tho: Applied center of mass to determine the value of each loadcell from total force
	bool re_calculate_value_each_sensor(std::vector<double> *calib_Sensor,
		std::vector<double> &calib_Real_Value);
	void re_bridgeCalibration(std::vector<double> *calibValue_Sensor,
		std::vector<double> *calibVaue_real_each_sensor,
		float(*calibBridgeParameters)[3]);
	std::vector<cv::Point2f> orderTargets(std::vector<cv::Point2f> allTargets);
	bool ScaleFactor_Scanner(cv::Mat &image_side, float &scale_factor, float &ImageScale);
private slots:

	void on_toolButton_clicked(){ ui.tabWidget->setCurrentIndex(0); }
	void on_toolButton_2_clicked(){ ui.tabWidget->setCurrentIndex(1); }
	void on_toolButton_3_clicked(){ ui.tabWidget->setCurrentIndex(2); }
	void on_toolButton_4_clicked(){ ui.tabWidget->setCurrentIndex(3); }
	void on_toolButton_5_clicked(){ ui.tabWidget->setCurrentIndex(4); }

	void on_scanner_status_changed(QString msg);
	void on_scanner_error(QString msg);
	void on_scanner_image_captured(cv::Mat msg);

	void on_actionNewCustomer_triggered();
	void on_actionExit_triggered();
	void on_actionAbout_triggered();
	void on_actionCalib_Scale_triggered();

	void on_pbBodyMeasurement_clicked();
	void on_pbFootAnalysis_clicked();
	void on_pbUpload_clicked();
	void on_pbSettings_clicked();

	void on_updateSettings();
	void on_pbSelectUpperCamera_clicked();
	void on_pbSelectBodyCamera_clicked();
	void on_pbUpperCapture_clicked();
	void on_pbFrontCapture_clicked();
	void on_pbBackCapture_clicked();
	void on_pbSideCapture_clicked();
	void on_webcamera();

	void on_cbWebcamSelect_activated();
	void on_pbSetUpperWebcam_clicked();
	void on_pbSetSideWebcam_clicked();
	void on_pbReSetWebcam_clicked();

// For scanner
	void on_pbReloadScannerDrivers_clicked();
	void on_pbLeftScan_clicked();
	void on_pbRightScan_clicked();
	void on_tbLeftFootMeasure_clicked();
	void on_tbRightFootMeasure_clicked();
	void on_leftDraw();
	void on_rightDraw();

	void on_pbSelectFootScanner_clicked();
	void on_pbFootPrintCapture_clicked();

	void on_cbLeftScanner_activated();
	void on_cbRightScanner_activated();

	void on_leLeftScannerScale_editingFinished();
	void on_leRightScannerScale_editingFinished();

	void on_pbSaveScannerSetting_clicked();

	void on_tbLeftFootReload_clicked();
	void on_tbRightFootReload_clicked();
	void on_tbLeftFootDetect_clicked();
	void on_tbRightFootDetect_clicked();
	void on_tbLeftFootSave_clicked();
	void on_tbRightFootSave_clicked();
	void on_leftDetect();
	void on_rightDetect();

	void on_pbSaveAnalysisResults_clicked();

// For network
	void on_pbConnectServer_clicked();
	void on_treeView_clicked(const QModelIndex &index);
	void on_pbMakeFolder_clicked();
	void on_pbUploadFiles_clicked();
	void on_pbSetSystemFolder_clicked();
	void on_ckShowPassword_stateChanged();

// For loadcells
	void on_bridge();
	void on_bridgeCalib();
	void on_cbBridges_activated();
	void on_cbBridgeGains_activated();
	void on_ckEnabled_stateChanged();
	void on_slRate_valueChanged();
	void on_leRate_editingFinished();
	void on_pbBridgeCalib_clicked();
	void on_pbSet_1_clicked();
	void on_pbSet_2_clicked();
	void on_pbSet_3_clicked();
	void on_pbSet_4_clicked();
	void on_pbSaveBridgeSetting_clicked();
	void on_pbReloadBridge_clicked();
	void on_pbMeasureWeight_clicked();
	// Tho >>
	void on_pbSet_5_clicked();
	void on_pbSet_6_clicked();

	cv::Mat comBineImages(cv::Mat &image1, cv::Mat &image2);
	// Old Customer remodify
	void on_pbOldCustomer_clicked();

	void on_leCustomerHeight_returnPressed();
	void on_leCustomerWeight_returnPressed();

private: /*9/20/2016*/ 
	void SaveDataLoadCell();
	void LoadDtaLoadCell();
	QString system_path_original;

private:
	Ui::MainWindowClass ui;

protected:
	LPWSTR convertQstring2LPWSTR(QString qString);
	QString convertLPWSTR2QString(LPWSTR lpString);
	void closeEvent(QCloseEvent *event);
	/*9/20/2016*/ // THO
	/*ImageScanner* _scannerLeft;
	ImageScanner* _scannerRight;
*/
	char* MyMakeFolder(QString t_str2);    // Edited by k2y

	/*
	Last modify: 27/10/2016
	*/

signals:
	void measuring_left();
	void measuring_right();
	void distance_left();
	void distance_right();

public:
	void leftFootMeasured(){
		emit measuring_left();
	};

	void rightFootMeasured(){
		emit measuring_right();
	};

	void distance_left_go(){
		emit distance_left();
	}

	void distance_right_go(){
		emit distance_right();
	}
	float AngleFrom3Point(QPoint &First_ptr, QPoint &Middle_ptr, QPoint &Last_ptr);
	float AngleFrom3Point_2(QPoint &First_ptr, QPoint &Middle_ptr, QPoint &Last_ptr);

	QPoint NornalPtFrom3Point(QPoint &First_ptr, QPoint &Last_ptr, QPoint &Criter_ptr);

	// 5 section
	void leftMeasuring_2(vector<QPoint> &points);
	void rightMeasuring_2(vector<QPoint> &points);

	public slots:

	void processing_leftFoot();
	void processing_rightFoot();
	void on_radioButton_left_toggled();
	void on_radioButton_right_toggled();

	void measureDistance_left();
	void measureDistance_right();

protected:
	bool eventFilter(QObject *obj, QEvent *ev);

public: // parameter
	std::vector<QPoint> point_leftFoot;
	std::vector<QPoint> point_rightFoot;

	std::vector<QPoint> distance_left_point;
	std::vector<QPoint> distance_right_point;
};

#endif // MAINWINDOW_H
