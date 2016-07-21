#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QCloseEvent>
#include <QFileSystemModel>
#include <QStringListModel>
#include <QInputDialog>
#include <QFileDialog>

#include "ui_mainwindow.h"
#include <opencv2\opencv.hpp>
#include "_Twain.h"
#include "segment_lib.h"
#include "phidget21.h"

#include <winnetwk.h>
#include <LM.h>
#include <tchar.h>
#include <string>

#pragma comment(lib, "mpr.lib")
#pragma comment(lib,"Netapi32.lib")

using namespace std;
using namespace cv;
using namespace ACUONG;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);


private:
	// For Webcamera
	VideoCapture webcamera1;
	QTimer *webcameraTimer;
	Mat upperView;

	// For Scanners
	CTwain leftScanner, rightScanner;
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

private:
	void refreshGUI();

	void initializeScanners();
	void fixScanError(QString scannerName, Mat &scannerImage);
	void loadScannerSetting();
	void leftMeasuring(vector<QPoint> &points);
	void rightMeasuring(vector<QPoint> &points);


	void findSharedItems(LPWSTR lpIpAddress);
	void defineTreeView();
	void showServerEntries();
	void showSysFiles();

	//For loadcells
	void openBridge();
	void setBridge();
	void loadBridgeSetting();
	void bridgeCalibration();

private slots:

	void on_actionNewCustomer_triggered();
	void on_actionExit_triggered();
	void on_actionAbout_triggered();

	void on_pbBodyMeasurement_clicked();
	void on_pbFootAnalysis_clicked();
	void on_pbUpload_clicked();
	void on_pbSettings_clicked();

	void on_updateSettings();
	void on_pbSelectUpperCamera_clicked();
	void on_pbSelectBodyCamera_clicked();
	void on_pbUpperCapture_clicked();
	void on_webcamera();

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

private:
	Ui::MainWindowClass ui;

protected:
	LPWSTR convertQstring2LPWSTR(QString qString);
	QString convertLPWSTR2QString(LPWSTR lpString);
	void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
