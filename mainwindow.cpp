#include "mainwindow.h"
#include <qthread.h>
#include <ImageScanner.h>
#include <QtCore/QTextCodec>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent),
	leftScannerIndex(0),
	rightScannerIndex(0),
	leftPainter(new Painter),
	rightPainter(new Painter)
	
{
	ui.setupUi(this);

	leftDraw = new(QTimer);
	connect(leftDraw, SIGNAL(timeout()), this, SLOT(on_leftDraw()));
	leftDraw->setInterval(200);
	rightDraw = new(QTimer);
	connect(rightDraw, SIGNAL(timeout()), this, SLOT(on_rightDraw()));
	rightDraw->setInterval(200);
	isLeftScannerConnect = isRightScannerConnect = false;
	loadScannerSetting();

	QStringList customer_sex;                            // Edited by k2y
	customer_sex << "male" << "female";                  // Edited by k2y
	ui.comboBox->addItems(customer_sex);                 // Edited by k2y
	
	ui.dateEdit->setDate(QDate::currentDate());          // Added by K2Y

	float t_valuef1, t_valuef2, t_valuef3;
	int   t_valuei;
	
	QString t_stringbuf1 = ui.leCustomerWeight->text();
	QString t_stringbuf2 = ui.leCustomerHeight->text();

	t_valuef1 = t_stringbuf1.toFloat();
	t_valuef2 = (t_stringbuf2.toFloat())/100.f;

	if (t_valuef2 == 0.f){

		t_valuef3 = 0.f;
	}
	else{
		t_valuei = (int)(10.f*t_valuef1 / (t_valuef2*t_valuef2));

		t_valuef3 = ((float)t_valuei) / 10.f;
	}
	
	ui.leBodyMass->setText(QString::number(t_valuef3));

	sysPath = "C:/GoodBodySchool/Data";                  // Added by K2Y

	String t_syspath1 = "C:/GoodBodySchool";             // Added by K2Y
	String t_syspath2 = "C:/GoodBodySchool/Data";        // Added by K2Y
	//_mkdir(t_syspath1);                                // Added by K2Y
	//_mkdir(t_syspath2);                                // Added by K2Y

	dirModel = new QFileSystemModel(this);
	//dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
	fileModel = new QFileSystemModel(this);
	fileModel->setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);


	bridgeTimer = new QTimer();
	connect(bridgeTimer, SIGNAL(timeout()), this, SLOT(on_bridge()));
	bridgeTimer->setInterval(50);
	bridgeCalibTimer = new QTimer();
	connect(bridgeCalibTimer, SIGNAL(timeout()), this, SLOT(on_bridgeCalib()));
	bridgeCalibTimer->setInterval(50);
	openBridge();

	leftDetect = new QTimer();
	connect(leftDetect, SIGNAL(timeout()), this, SLOT(on_leftDetect()));
	leftDetect->setInterval(200);
	rightDetect = new QTimer();
	connect(rightDetect, SIGNAL(timeout()), this, SLOT(on_rightDetect()));
	rightDetect->setInterval(200);

	// initialize webcamera

	webcameraTimer = new QTimer();
	connect(webcameraTimer, SIGNAL(timeout()), this, SLOT(on_webcamera()));
	webcameraTimer->setInterval(100);
	
	//QStringList webcams;
	//webcams << "Webcamera 0" << "Webcamera 1";
	/*Edited by Tho: 7/23/2016*/
	ListWebcam _name_webcam;
	ui.cbWebcamSelect->addItems(_name_webcam.List_of_Webcam_QT);
	on_pbBodyMeasurement_clicked();

	// load-cell offset
	real_offset[0] = 0;
	real_offset[1] = 0;
	real_offset[2] = 0;
	real_offset[3] = 0;
	// treeView
	dirModel->setRootPath(sysPath);
	ui.treeView->setModel(dirModel);
	ui.treeView->setRootIndex(dirModel->index("C:\\GoodBodySchool\\Data"));

	// listView
	QString list_view_path = sysPath +"//" + ui.dateEdit->text() +"//" + ui.leCustomerName->text();
	QDir sys_Dir(list_view_path);
	listSysFiles = sys_Dir.entryList(QDir::NoDotAndDotDot | QDir::Files);
	QStringListModel *sysFilesModel = new QStringListModel(this);
	sysFilesModel->setStringList(listSysFiles);
	ui.listView2->setModel(sysFilesModel);


	ui.tabWidget->tabBar()->hide();
	ui.menuBar->hide();
	// system path
	system_path_original = QDir::currentPath();


	/*
	Last modyfi: 27-10-2016
	*/
	// Painter fillter
	leftPainter->installEventFilter(this);
	rightPainter->installEventFilter(this);

	connect(this, SIGNAL(measuring_left()), this, SLOT(processing_leftFoot()));
	connect(this, SIGNAL(measuring_right()), this, SLOT(processing_rightFoot()));

	connect(this, SIGNAL(distance_left()), this, SLOT(measureDistance_left()));
	connect(this, SIGNAL(distance_right()), this, SLOT(measureDistance_right()));
}

void MainWindow::on_actionNewCustomer_triggered(){

}

void MainWindow::on_actionExit_triggered(){
	close();
}

void MainWindow::on_actionAbout_triggered(){
	QMessageBox::about(this, "Foot Measurement", "This software was developed by .... in 2016, Ulsan, Korea");
}

void MainWindow::on_actionCalib_Scale_triggered(){

	bool found_right = 0;
	bool found_left = 0;
	cv::Mat img_left = leftScanImage;
	if (img_left.empty()){
		QMessageBox::about(this, "Foot Measurement", "Can't load left image for calibration scale factor!");
	}
	else{
		float left_factor_scale = 1;
		found_left = ScaleFactor_Scanner(img_left, left_factor_scale, leftImageScale);

		if (found_left){

			leftScannerScale = left_factor_scale;
			ui.leLeftScannerScale->setText(QString::number(leftScannerScale, 'g', 4));
			on_pbSaveScannerSetting_clicked();

			/*std::cout << "successful " << std::endl;
			std::cout << "Left scale factor: " << leftScannerScale << std::endl;*/
		}
		//else QMessageBox::about(this, "Foot Measurement", " Faile to left calibration scale factor!");
	}
	/***************/
	cv::Mat img_right = rightScanImage;
	if (img_right.empty()){
		QMessageBox::about(this, "Foot Measurement", "Can't load right image for calibration scale factor!");
	}
	else{
		float right_factor_scale = 1;
		found_right = ScaleFactor_Scanner(img_right, right_factor_scale, rightImageScale);
		if (found_right){
			rightScannerScale = right_factor_scale;
			ui.leRightScannerScale->setText(QString::number(rightScannerScale, 'g', 4));
			on_pbSaveScannerSetting_clicked();
		}

	}

	if (found_left == 0 || found_right == 0){
		QMessageBox::about(this, "Calibration Scale", "Faile To Calib!");
	}

}

void MainWindow::refreshGUI(){
	//ui.pbBodyMeasurement->setStyleSheet("color:black; background:#E5E8E8");                // Edited by K2Y
	//ui.pbFootAnalysis->setStyleSheet("color:black; background:#E5E8E8");                // Edited by K2Y
	//ui.pbUpload->setStyleSheet("color:black; background:#E5E8E8");                // Edited by K2Y
	//ui.pbTransferStatus->setStyleSheet("color:black; background:#E5E8E8");                // Edited by K2Y
	//ui.pbSettings->setStyleSheet("color:black; background:#E5E8E8");                // Edited by K2Y
	//ui.frameMain->hide();                                                      // Edited by K2Y
	//ui.frameFootAnalysis->hide();                                                 // Edited by K2Y
	//ui.frameUpload->hide();                                                    // Edited by K2Y
	//ui.frameSettings->hide();                                              // Edited by K2Y
}

void MainWindow::on_pbBodyMeasurement_clicked(){
	//refreshGUI();                                                 // Edited by K2Y
	//ui.pbBodyMeasurement->setStyleSheet("color:red");                // Edited by K2Y
	//ui.frameMain->show();                                      // Edited by K2Y
	//webcameraTimer->stop();                                    // Edited by K2Y
}

void MainWindow::on_pbFootAnalysis_clicked(){
	//refreshGUI();                                          // Edited by K2Y
	//ui.pbFootAnalysis->setStyleSheet("color:red");                // Edited by K2Y
	//ui.frameFootAnalysis->show();                                 // Edited by K2Y
}

void MainWindow::on_pbUpload_clicked(){
	//refreshGUI();                                             // Edited by K2Y
	//ui.pbUpload->setStyleSheet("color:red");                // Edited by K2Y
	//showSysFiles();                                    // Edited by K2Y
	//ui.frameUpload->show();                                   // Edited by K2Y
	//on_ckShowPassword_stateChanged();                 // Edited by K2Y
}

void MainWindow::on_pbSettings_clicked(){
	//refreshGUI();                                     // Edited by K2Y
	//ui.pbSettings->setStyleSheet("color:red");                // Edited by K2Y
	//ui.frameSettings->show();                           // Edited by K2Y
	//ui.pbSetUpperWebcam->setEnabled(true);                // Edited by K2Y
	//ui.pbSetSideWebcam->setEnabled(true);                // Edited by K2Y
}

void MainWindow::on_updateSettings(){

}

/* Edited by Tho*/
void MainWindow::initializeScanners(){
		
	leftScannerIndex = 0;
	rightScannerIndex = 0;

	leftScannerIndexBuf[0] = 0;
	leftScannerIndexBuf[1] = 0;
	
	rightScannerIndexBuf[0] = 0;
	rightScannerIndexBuf[1] = 0;

	std::string epsonSannerName_1 = "EPSON Perfection V37/V370";
	std::string epsonSannerName_2 = "WIA-EPSON Perfection V37/V370";
	//return;

	if (leftScanner.twInitialize(0) != TWRC_SUCCESS){
		QMessageBox::critical(this, tr("Scanners Initialization"), tr("Unable load Scanner Drivers"));
		return;
	}
	///////////////////
	if (leftScanner.twListDevices() == TWRC_FAILURE) {
		QMessageBox::critical(this, tr("Scanners Finding"), tr("No Image Acquisitiion Device on system"));
		return;
	}

	int   t_index = 0;
	bool *t_buffer = NULL;

	t_buffer = new bool[leftScanner.twList.size()];

	for (int i = 0; i < leftScanner.twList.size(); i++){

		t_buffer[i] = false;

		if (epsonSannerName_1.compare(leftScanner.twList[i]) == 0 || leftScanner.twList[i].compare(0, 29, epsonSannerName_2) == 0)
			t_buffer[i] = true;
        
		for (int j = i+1; j < leftScanner.twList.size(); j++){
			
			if (leftScanner.twList[i].compare(0, 29, epsonSannerName_2) == 0 && leftScanner.twList[j].compare(0, 29, epsonSannerName_2) == 0){

					t_buffer[i] = false;
			}
		}
			
		if (t_buffer[i]){
			leftScannerIndexBuf[t_index] = i + 1;  // just trick
			ui.cbLeftScanner->addItem(QString::fromStdString(leftScanner.twList[i]));
			t_index++;
		}
	}

	delete[] t_buffer;
	/////////////////////



	if (rightScanner.twInitialize(1) != TWRC_SUCCESS){
		QMessageBox::critical(this, tr("Scanners Initialization"), tr("Unable load Scanner Drivers"));
		return;
	}
	if (rightScanner.twListDevices() == TWRC_FAILURE) {
		QMessageBox::critical(this, tr("Scanners Finding"), tr("No Image Acquisitiion Device on system"));
		return;
	}

	t_index = 0;
	t_buffer = new bool[rightScanner.twList.size()];

	for (int i = 0; i < rightScanner.twList.size(); i++){

		t_buffer[i] = false;

		if (epsonSannerName_1.compare(rightScanner.twList[i]) == 0 || rightScanner.twList[i].compare(0, 29, epsonSannerName_2) == 0)
			t_buffer[i] = true;

		for (int j = i + 1; j < rightScanner.twList.size(); j++){

			if (rightScanner.twList[i].compare(0, 29, epsonSannerName_2) == 0 && rightScanner.twList[j].compare(0, 29, epsonSannerName_2) == 0){

				t_buffer[i] = false;
			}
		}

		if (t_buffer[i]){
			rightScannerIndexBuf[t_index] = i+1;  // just trick
			ui.cbRightScanner->addItem(QString::fromStdString(leftScanner.twList[i]));
			t_index++;
		}
	} 

	delete[] t_buffer;
}

void MainWindow::on_cbLeftScanner_activated(){

	if(isLeftScannerConnect) leftScanner.twCloseSource();

	leftScannerIndex = ui.cbLeftScanner->currentIndex();
	leftScannerIndex = leftScannerIndexBuf[leftScannerIndex - 1];

	if (leftScannerIndex == 0 || leftScannerIndex == rightScannerIndex){
		ui.cbLeftScanner->setCurrentIndex(0);
		leftScannerIndex = 0;
		isLeftScannerConnect = false;
		return;
	}

	emit sig_left_scanner_id_changed(leftScannerIndex -1);

	if (leftScanner.twSelectDevice(leftScannerIndex -1) != TWRC_SUCCESS){
		QMessageBox::critical(this, tr("Left Scanner"), tr("Unable to establish connection with device"));
		ui.cbLeftScanner->setCurrentIndex(0);
		leftScannerIndex = 0;
		isLeftScannerConnect = false;
		return;
	}

	isLeftScannerConnect = true;
	leftScannerName = ui.cbLeftScanner->currentText();
	leftScanner.twSetCapability(CAP_XFERCOUNT, TWTY_INT16, 1);
}

void MainWindow::on_cbRightScanner_activated(){

	if(isRightScannerConnect) rightScanner.twCloseSource();

	rightScannerIndex = ui.cbRightScanner->currentIndex();
	rightScannerIndex = rightScannerIndexBuf[rightScannerIndex - 1];

	if (rightScannerIndex == 0 || leftScannerIndex == rightScannerIndex){
		ui.cbRightScanner->setCurrentIndex(0);
		rightScannerIndex = 0;
		isRightScannerConnect = false;
		return;
	}

	emit sig_right_scanner_id_changed(rightScannerIndex-1);

	if (rightScanner.twSelectDevice(rightScannerIndex-1) != TWRC_SUCCESS){

		QMessageBox::critical(this, tr("Right Scanner"), tr("Unable to establish connection with device"));
		ui.cbRightScanner->setCurrentIndex(0);
		rightScannerIndex = 0;
		isRightScannerConnect = false;
		return;
	}
	rightScannerName = ui.cbRightScanner->currentText();
	rightScanner.twSetCapability(CAP_XFERCOUNT, TWTY_INT16, 1);
}

void MainWindow::on_pbLeftScan_clicked(){
	/* Modified on 8/3/2016: Read Loadcell before scanning*/

	// reset
	ui.ivLeftAnalysisImage->clear();   //->SetImage(qImage);
	ui.ivLeftDetectImage->clear();
	ui.log->clear();   //Log("... done!");
	leftProcess = None;
	ui.commandPicture->clear();

	point_leftFoot.clear();
	ui.radioButton_left->setAutoExclusive(false);
	ui.radioButton_left->setChecked(false);
	ui.radioButton_left->setAutoExclusive(true);

	distance_left_point.clear();
	ui.radioButton_left_foot_mearsure->setAutoExclusive(false);
	ui.radioButton_left_foot_mearsure->setChecked(false);
	ui.radioButton_left_foot_mearsure->setAutoExclusive(true);


	if (flag_loadcell_connection_status == 0){
		openBridge();
	}
	for (int sample = 0; sample != 100; sample++){
		on_bridge();
	}
	// save data loadcell
	SaveDataLoadCell();
	/*end*/
	if (leftScannerIndex == 0)
	{
		QMessageBox::critical(this, tr("Left Scanner"), tr("Please Choose The Scanner at The Setting Section!"));
		return;
	}

	try{
		
		if (leftScanner.twScan("leftScan.jpg") == TWRC_FAILURE){
			QMessageBox::critical(this, tr("Left Scanner"), tr("Scanning error"));
			return;
		}
	}
	catch (exception& e){

		QMessageBox::critical(this, tr("Left Scanner"), tr("Scanning error"));
		return;
	}
	// Rotation image 
	rightScanImage = imread("leftScan.jpg");//leftScanImage -> rightScanImage  
	if (rightScanImage.empty()) return;
	fixScanError(leftScannerName, rightScanImage);
	// rotation 
	Point2f src_center(rightScanImage.cols / 2.0F, rightScanImage.rows / 2.0F);
	Mat rot_mat = getRotationMatrix2D(src_center, 180, 1.0);
	warpAffine(rightScanImage, rightScanImage, rot_mat, rightScanImage.size());

	Mat image;
	cvtColor(rightScanImage, image, CV_RGB2BGR);
	QImage qimg(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
	rightPainter->setImage(qimg);// leftPainter - > rightPainter
	rightImageScale = 1.0 / rightPainter->resizeFactor; //  leftImageScale = 1.0 / leftPainter->resizeFactor; -> rightImageScale = 1.0 / rightPainter->resizeFactor;
	ui.lbRightImageScale->setText(QString::number(rightImageScale));// ui.lbLeftImageScale->setText(QString::number(leftImageScale)); -> ui.lbRightImageScale->setText(QString::number(rightImageScale));
	rightProcess = Scan; // leftProcess = Scan; -> rightProcess = Scan;
	on_pbRightScan_clicked();
}

void MainWindow::on_pbRightScan_clicked(){

	// reset
	ui.ivRightAnalysisImage->clear();
	ui.ivRightDetectImage->clear();
	ui.log->clear();
	rightProcess = None;

	point_rightFoot.clear();
	ui.radioButton_right->setAutoExclusive(false);
	ui.radioButton_right->setChecked(false);
	ui.radioButton_right->setAutoExclusive(true);

	distance_right_point.clear();
	ui.radioButton_right_foot_mearsure->setAutoExclusive(false);
	ui.radioButton_right_foot_mearsure->setChecked(false);
	ui.radioButton_right_foot_mearsure->setAutoExclusive(true);


	if (rightScannerIndex == 0)
	{
		QMessageBox::critical(this, tr("Right Scanner"), tr("Please Choose The Scanner at The Setting Section!"));
		return;
	}
	try{
		if (rightScanner.twScan("rightScan.jpg") == TWRC_FAILURE){
			QMessageBox::critical(this, tr("Right Scanner"), tr("Scanning error"));
			return;
		}
	}
	catch (exception& e){
		QMessageBox::critical(this, tr("Right Scanner"), tr("Scanning error"));
		return;
	}

	// Rotation image 

	leftScanImage = imread("rightScan.jpg"); // rightScanImage -> leftScanImage
	if (leftScanImage.empty()) return;
	fixScanError(rightScannerName, leftScanImage);//rightScannerName
	// rotation 
	Point2f src_center(leftScanImage.cols / 2.0F, leftScanImage.rows / 2.0F);
	Mat rot_mat = getRotationMatrix2D(src_center, 180, 1.0);
	warpAffine(leftScanImage, leftScanImage, rot_mat, leftScanImage.size());

	Mat image;
	cvtColor(leftScanImage, image, CV_RGB2BGR);// rightScanImage -> leftScanImage 
	QImage qimg(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
	leftPainter->setImage(qimg); // rightPainter->setImage(qimg); -> leftPainter
	leftImageScale = 1.0 / leftPainter->resizeFactor; // rightImageScale = 1.0 / rightPainter->resizeFactor; - > 
	ui.lbLeftImageScale->setText(QString::number(leftImageScale)); //  ui.lbRightImageScale->setText(QString::number(rightImageScale)); - > ui.lbLeftImageScale->setText(QString::number(leftImageScale));
	rightProcess = Scan;

	/*Tho Cao: stiched image*/
	cv::Mat totalFootShape = comBineImages(leftScanImage, rightScanImage);
	saveImage("_TotalFoot.jpg", totalFootShape);
	//
}

void MainWindow::on_tbLeftFootReload_clicked(){
	if (leftScanImage.empty()){
		leftScanImage = imread("test_left.jpg");
	}
	Mat image;
	cvtColor(leftScanImage, image, CV_RGB2BGR);
	QImage qimg(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
	leftDetect->stop();
	leftDraw->stop();
	leftPainter->setImage(qimg);
	leftPainter->points.clear();
	leftPainter->paintMode = PAINT_NONE;
	leftImageScale = 1.0 / leftPainter->resizeFactor;
	ui.lbLeftImageScale->setText(QString::number(leftImageScale));
	leftProcess = Scan;

	// reset
	point_leftFoot.clear();
	ui.radioButton_left->setAutoExclusive(false);
	ui.radioButton_left->setChecked(false);
	ui.radioButton_left->setAutoExclusive(true);

	distance_left_point.clear();
	ui.radioButton_left_foot_mearsure->setAutoExclusive(false);
	ui.radioButton_left_foot_mearsure->setChecked(false);
	ui.radioButton_left_foot_mearsure->setAutoExclusive(true);
}

void MainWindow::on_tbRightFootReload_clicked(){
	if (rightScanImage.empty()){
		rightScanImage=imread("test_right.jpg");
	}
	Mat image;
	cvtColor(rightScanImage, image, CV_RGB2BGR);
	QImage qimg(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
	rightDetect->stop();
	rightDraw->stop();
	rightPainter->setImage(qimg);
	rightPainter->points.clear();
	rightPainter->paintMode = PAINT_NONE;
	rightImageScale = 1.0 / rightPainter->resizeFactor;
	ui.lbRightImageScale->setText(QString::number(rightImageScale));
	rightProcess = Scan;

	// reset
	point_rightFoot.clear();
	ui.radioButton_right->setAutoExclusive(false);
	ui.radioButton_right->setChecked(false);
	ui.radioButton_right->setAutoExclusive(true);

	distance_right_point.clear();
	ui.radioButton_right_foot_mearsure->setAutoExclusive(false);
	ui.radioButton_right_foot_mearsure->setChecked(false);
	ui.radioButton_right_foot_mearsure->setAutoExclusive(true);

}

void MainWindow::on_tbLeftFootDetect_clicked(){
	leftPainter->curvePoints.clear();
	leftPainter->paintMode = PAINT_CURVE;
	leftAreaDetected = 0;
	QImage commandPictureLeft = QImage("leftDetectCommand.png");
	ui.commandPicture->SetImage(commandPictureLeft);
	leftDetect->start();
	leftProcess = statusProcess::Detect;
	ui.log->Log("Left foot");
}

void MainWindow::on_leftDetect(){
	if (leftPainter->paintMode == PAINT_NONE){
		QPoint center = leftPainter->centroidPolygon(leftPainter->curvePoints);
		leftCenters[leftAreaDetected] = center;
		leftPainter->drawPoint(center, Qt::red, 10);
		if (leftAreaDetected == 0) {
			leftAreaDetected++;
			leftPainter->curvePoints.clear();
			leftPainter->paintMode = PAINT_CURVE;
			//ui.log->Log("select");
		}
		else {
			leftDetect->stop();
			leftProcess = None;
			ui.ivLeftDetectImage->SetImage(leftPainter->theImage);
			ui.log->Log("done!");
		}
	}
}


void MainWindow::on_tbRightFootDetect_clicked(){
	rightPainter->curvePoints.clear();
	rightPainter->paintMode = PAINT_CURVE;
	rightAreaDetected = 0;
	/*Modyfied by Tho*/
	QImage commandPictureLeft = QImage("rightDetectCommand.png");
	ui.commandPicture->SetImage(commandPictureLeft);
	rightDetect->start();
	rightProcess = statusProcess::Detect;
	ui.log->Log("Right foot");
}

void MainWindow::on_rightDetect(){
	if (rightPainter->paintMode == PAINT_NONE){
		QPoint center = rightPainter->centroidPolygon(rightPainter->curvePoints);
		rightCenters[rightAreaDetected] = center;
		rightPainter->drawPoint(center, Qt::red, 10);
		if (rightAreaDetected == 0) {
			rightAreaDetected++;
			rightPainter->curvePoints.clear();
			rightPainter->paintMode = PAINT_CURVE;
			//ui.log->Log("... select another part ...");
		}
		else {
			rightDetect->stop();
			rightProcess = None;
			ui.ivRightDetectImage->SetImage(rightPainter->theImage);
			ui.log->Log("done!");
		}
	}
}


void MainWindow::on_tbLeftFootSave_clicked(){
	QImage qImage = leftPainter->theImage;
	// qImage's format is Format_RGB32 (4 channel - 8 bit)
	Mat mImage = Mat(qImage.height(), qImage.width(), CV_8UC4, const_cast<uchar*>(qImage.bits()), qImage.bytesPerLine());
	switch (leftProcess){
	case Analysis:
		saveImage("_Left_Analysis.jpg", mImage);
		break;
	case Detect:
		saveImage("_Left_Detect.jpg", mImage);
		break;
	case Scan:
		saveImage("_Left_Scan.jpg", mImage);
		break;
	case None:
	default:
		break;

	}
}

void MainWindow::on_tbRightFootSave_clicked(){
	QImage qImage = rightPainter->theImage;
	// qImage's format is Format_RGB32 (4 channel - 8 bit)
	Mat mImage = Mat(qImage.height(), qImage.width(), CV_8UC4, const_cast<uchar*>(qImage.bits()), qImage.bytesPerLine());
	switch (leftProcess){
	case Analysis:
		saveImage("_Right_Analysis.jpg", mImage);
		break;
	case Detect:
		saveImage("_Right_Detect.jpg", mImage);
		break;
	case Scan:
		saveImage("_Right_Scan.jpg", mImage);
		break;
	case None:
	default:
		break;

	}
}


void MainWindow::on_pbSelectFootScanner_clicked(){
	if (leftScanImage.empty() || rightScanImage.empty()) return;
	Mat leftImage = leftScanImage.clone();
	Mat rightImage = rightScanImage.clone();
	Size sizeLeft = leftImage.size();
	Size sizeRight = rightImage.size();
	if (sizeLeft.height < sizeRight.height){
		cv::resize(rightImage, rightImage, sizeLeft);
		sizeRight = rightImage.size();
	}
	else{
		cv::resize(leftImage, leftImage, sizeRight);
		sizeLeft = leftImage.size();
	}
	int height = sizeLeft.height;
	footImage = Mat::zeros(height, sizeLeft.width + sizeRight.width, CV_8UC3);
	leftImage.copyTo(footImage(Rect(0, 0, sizeLeft.width, sizeLeft.height)));
	rightImage.copyTo(footImage(Rect(sizeLeft.width, 0, sizeRight.width, sizeRight.height)));
	//ui.ivFootPrintView->SetImage(footImage);                   // Edited by K2Y
}

void MainWindow::on_pbFootPrintCapture_clicked(){
	if (footImage.empty())return;
	//ui.ivFootView->SetImage(footImage);                           // Edited by K2Y
	saveImage("_Footprint.jpg", footImage);
}

void MainWindow::on_pbSelectUpperCamera_clicked(){
	webcamera.open(webcamUpperIndex);
	if (webcamera.isOpened()){
		webcamera.set(CV_CAP_PROP_FRAME_WIDTH, 1280);        
		webcamera.set(CV_CAP_PROP_FRAME_HEIGHT, 720);
		webcameraTimer->start();
		bodyView = false;
		// flag
		flag_dont_show_image_before_camera_chossed = 1;
	}
	else{
		QMessageBox::critical(this, "Select Webcamera", "Plese Choose The WebCam at The Settings !");
	}
}

void MainWindow::on_pbSelectBodyCamera_clicked(){
	webcamera.open(webcamSideIndex);
	if (webcamera.isOpened()){
		webcamera.set(CV_CAP_PROP_FRAME_WIDTH, 1280);        
		webcamera.set(CV_CAP_PROP_FRAME_HEIGHT, 720);
		webcameraTimer->start();
		bodyView = true;
		// flag
		flag_dont_show_image_before_camera_chossed = 1;
	}
	else{
		QMessageBox::critical(this, "Select Webcamera", "Plese Choose The WebCam at The Settings !");
	}
}

void MainWindow::on_cbWebcamSelect_activated(){
	webcamera.open(ui.cbWebcamSelect->currentIndex());
	if (webcamera.isOpened()) webcameraTimer->start();
	// flag
	flag_dont_show_image_before_camera_chossed = 0;
	cv::Mat whiteframe = cv::Mat(1280, 720, CV_8U);
	whiteframe = cv::Scalar(255);
	ui.ivBodyCameraViews->SetImage(whiteframe);
}

void MainWindow::on_webcamera(){
	webcamera >> webcamFrame;

	if (webcamFrame.empty()){
		QMessageBox::critical(this, "Select Webcamera", "This webcamera can't open !");
		webcameraTimer->stop();
	}
	else{

		ui.ivWebcamera->SetImage(webcamFrame);

		if (bodyView){
			transpose(webcamFrame, webcamFrame);
			flip(webcamFrame, webcamFrame, 0);

			webcamFrame.copyTo(webcamFrame_grid);
		}
		/* Modified on 8/3/2016 : Don't show the image before the camera clicked*/
		if (flag_dont_show_image_before_camera_chossed == 1){

			if (bodyView){
				// Drawing lines
				int t_thickness = 1;
				int t_lineType = 8;

				Point t_start = Point(0, 200);
				Point t_end = Point(720, 200);

				for (int t_i = 0; t_i < 6; t_i++){

					line(webcamFrame_grid, t_start, t_end, Scalar(200, 0, 0), t_thickness, t_lineType);

					t_start.y += 200;
					t_end.y += 200;
				}

				t_start.x = 144;
				t_start.y = 0;

				t_end.x = 144;
				t_end.y = 1280;

				for (int t_i = 0; t_i < 4; t_i++){

					line(webcamFrame_grid, t_start, t_end, Scalar(200, 0, 0), t_thickness, t_lineType);

					t_start.x += 144;
					t_end.x += 144;
				}

				ui.ivBodyCameraViews->SetImage(webcamFrame_grid);

			}else{
			
				ui.ivBodyCameraViews->SetImage(webcamFrame);
			}

		}

	}
}

void MainWindow::on_pbSetUpperWebcam_clicked(){
	if (webcamSideIndex == ui.cbWebcamSelect->currentIndex()){
		QMessageBox::critical(this, "Select Webcamera", "This webcamera has been chosen !");
		return;
	}
	webcamUpperIndex = ui.cbWebcamSelect->currentIndex();
	ui.pbSetUpperWebcam->setText("Upper View Done!");
	ui.pbSetUpperWebcam->setEnabled(false);
}

void MainWindow::on_pbSetSideWebcam_clicked(){
	if (webcamUpperIndex == ui.cbWebcamSelect->currentIndex()){
		QMessageBox::critical(this, "Select Webcamera", "This webcamera has been chosen !");
		return;
	}
	webcamSideIndex = ui.cbWebcamSelect->currentIndex();
	ui.pbSetSideWebcam->setText("Side View Done!");
	ui.pbSetSideWebcam->setEnabled(false);
}
/*Edited: Tho ______________ Reset Webcam*/
void MainWindow::on_pbReSetWebcam_clicked(){
	webcamUpperIndex = -1;
	webcamSideIndex = -1;

	ui.pbSetUpperWebcam->setText("Upper View");
	ui.pbSetUpperWebcam->setEnabled(true);

	ui.pbSetSideWebcam->setText("Side View");
	ui.pbSetSideWebcam->setEnabled(true);
}

void MainWindow::on_pbUpperCapture_clicked(){
	if (webcamFrame.empty()) return;
	ui.ivBodyTopView->SetImage(webcamFrame);
	saveImage("_UpperView.jpg", webcamFrame);
}

void MainWindow::on_pbFrontCapture_clicked(){
	if (webcamFrame.empty()) return;
	ui.ivBodyFrontView->SetImage(webcamFrame);
	saveImage("_FrontView.jpg", webcamFrame);
}

void MainWindow::on_pbBackCapture_clicked(){
	if (webcamFrame.empty()) return;
	ui.ivBodyBackView->SetImage(webcamFrame);                       // Edited by K2Y
	saveImage("_BackView.jpg", webcamFrame);
}

void MainWindow::on_pbSideCapture_clicked(){
	if (webcamFrame.empty()) return;
	ui.ivBodySideView->SetImage(webcamFrame);
	saveImage("_SideView.jpg", webcamFrame);
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// This function is edited by K2Y
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void MainWindow::saveImage(QString tailName, Mat &image){   
	
	//QString t_foldername1 = "/" + ui.leMeasureDate->text();
	QString t_foldername1 = "/" + ui.dateEdit->text();
	QString t_foldername2 = "/" + ui.leCustomerName->text();
	
	t_foldername1.remove(" ");
	t_foldername2.remove(" ");

	t_foldername1 = sysPath + t_foldername1;
	t_foldername2 = t_foldername1 + t_foldername2;
	
	MyMakeFolder(t_foldername1);
	MyMakeFolder(t_foldername2);

	QString fileName = ui.dateEdit->text() + "_" + ui.leCenterName->text() + "_" + ui.leCustomerName->text() + tailName;
	fileName.remove(" ");
	fileName = t_foldername2 + "/" + fileName;
	/*QByteArray l_byteName = fileName.toLocal8Bit();
	string fn = l_byteName.data();
	imwrite(fn, image);*/
	/*Edited by Tho*/
	imwrite(tailName.toStdString(), image);
	QPixmap pixmap(tailName);
	pixmap.save(fileName);
	QFile file(tailName);
	file.remove();
}


void MainWindow::fixScanError(QString scannerName, Mat &scanImage){
	if (scannerName.contains("WIA")){
		cv::resize(scanImage, scanImage, Size(612, 842));
		int height = scanImage.rows;
		int width = scanImage.cols;
		Mat temp1, temp2;
		Rect roi1, roi2;
		roi1 = Rect(0, 0, 65, height);
		temp1 = scanImage(roi1).clone();
		Mat channel[3];
		split(temp1, channel);
		Mat temp = channel[2];
		channel[2] = channel[0];
		channel[0] = channel[1];
		channel[1] = temp;
		merge(channel, 3, temp1);
		roi2 = Rect(roi1.width, 0, width - roi1.width, height);
		temp2 = scanImage(roi2).clone();
		temp2.copyTo(scanImage(Rect(0, 0, roi2.width, height)));
		temp1.copyTo(scanImage(Rect(roi2.width, 0, roi1.width, height)));
	}
	else{
		Mat channel[3];
		split(scanImage, channel);
		Mat temp = channel[2];
		channel[2] = channel[1];
		channel[1] = channel[0];
		channel[0] = temp;
		merge(channel, 3, scanImage);
	}
	flip(scanImage, scanImage, 1);
}

void MainWindow::on_tbLeftFootMeasure_clicked(){
	leftPainter->paintMode = PAINT_POINT;
	leftDraw->start();
	QImage commandPictureLeft = QImage("leftCommand.png");
	ui.commandPicture->SetImage(commandPictureLeft);
	leftProcess = statusProcess::Analysis;
	ui.log->Log("Left foot is being analyzed ...");
}

void MainWindow::on_radioButton_left_toggled(){
	QImage commandPictureLeft = QImage("leftCommand_ver2.png");
	ui.commandPicture->SetImage(commandPictureLeft);
}

void MainWindow::on_leftDraw(){
	if (leftPainter->points.empty()) return;
	if (leftPainter->points.size() == 2){
		leftPainter->drawLine(leftPainter->points[0], leftPainter->points[1], Qt::blue, 2);
	}
	if (leftPainter->points.size() == 4){
		QPoint A = leftPainter->points[2];
		QPoint B = leftPainter->points[3];
		if (A.y() < B.y()){
			leftPainter->points[2] = B;
			leftPainter->points[3] = A;
			A = leftPainter->points[2];
			B = leftPainter->points[3];
		}
		leftPainter->drawExtenLine(A, B, 50, Qt::green);
	}
	if (leftPainter->points.size() == 5){
		int exten = abs(leftPainter->points[2].y() - leftPainter->points[3].y());
		leftPainter->drawExtenLine(leftPainter->points[2], leftPainter->points[4], exten);
	}
	if (leftPainter->points.size() == 7){
		leftPainter->drawExtenLine(leftPainter->points[5], leftPainter->points[6], 100);
		leftPainter->paintMode=PAINT_NONE;
		leftDraw->stop();
		leftMeasuring(leftPainter->points);
		leftPainter->points.clear();

		QImage qImage = leftPainter->theImage;
		Mat mImage = Mat(qImage.height(), qImage.width(), CV_8UC4, const_cast<uchar*>(qImage.bits()), qImage.bytesPerLine());
		saveImage("_Left_Analysis.jpg", mImage);

		ui.ivLeftAnalysisImage->SetImage(qImage);
		ui.log->Log("... done!");
		leftProcess = None;
	}
}

void MainWindow::leftMeasuring(vector<QPoint> &points){
	leftFootLength = Line::lengthSegment(points[0], points[1]);
	leftFootLength *= leftImageScale*leftScannerScale;
	/*ui.lbLeftFootLength->setText(QString::number(leftFootLength,'f',2));*/

	Line line1(points[2], points[3]);
	Line line2(points[2], points[4]);
	leftFootAngle = AngleFrom3Point_2(points[3], points[2], points[4]);
	/*ui.lbLeftFootAngle->setText(QString::number(leftFootAngle, 'f', 2));*/

	leftPainter->drawLine(points[2], points[5]);
	Line line3(points[2], points[5]);
	float b4 = points[6].y() - line3.a*points[6].x();
	Line line4(line3.a, b4);
	QPointF it = Line::intersect2Lines(line2, line4);
	QPoint inter(it.x(), it.y());
	leftPainter->drawPoint(inter, Qt::green);
	leftPainter->drawLine(points[6], inter, Qt::magenta);

	vector<QPoint> topPoints = Line::divideSegment(points[2], points[5], 5);
	vector<QPoint> bottomPoints = Line::divideSegment(inter, points[6], 5);
	for (int i = 0; i < 4; i++){
		leftPainter->drawPoint(topPoints[i], Qt::cyan);
		leftPainter->drawPoint(bottomPoints[i], Qt::cyan);
		leftPainter->drawLine(topPoints[i], bottomPoints[i], Qt::red);
	}
	leftDone = Analysis;
}

void MainWindow::on_leLeftScannerScale_editingFinished(){
	leftScannerScale = ui.leLeftScannerScale->text().toFloat();
}

void MainWindow::on_leRightScannerScale_editingFinished(){
	rightScannerScale = ui.leRightScannerScale->text().toFloat();
}

void MainWindow::on_pbSaveScannerSetting_clicked(){
	FILE *f = fopen("calibScanner.dat", "wb");
	if (!f){
		QMessageBox::critical(this, tr("Scanner Calibration"), QString("Can not save calibration data !"));
		return;
	}
		fwrite(&leftScannerScale, sizeof(float), 1, f);
		fwrite(&rightScannerScale, sizeof(float), 1, f);
	fclose(f);
}
void MainWindow::on_tbRightFootMeasure_clicked(){
	rightPainter->paintMode=PAINT_POINT;
	rightDraw->start();
	QImage commandPicture = QImage("rightCommand.png");
	ui.commandPicture->SetImage(commandPicture);
	rightProcess = statusProcess::Analysis;
	ui.log->Log("Right foot is being analyzed ...");
}

void MainWindow::on_radioButton_right_toggled(){
	QImage commandPicture = QImage("rightCommand_ver2.png");
	ui.commandPicture->SetImage(commandPicture);
}

void MainWindow::on_rightDraw(){
	if (rightPainter->points.empty()) return;
	if (rightPainter->points.size() == 2){
		rightPainter->drawLine(rightPainter->points[0], rightPainter->points[1], Qt::blue, 2);
	}
	if (rightPainter->points.size() == 4){
		QPoint A = rightPainter->points[2];
		QPoint B = rightPainter->points[3];
		if (A.y() < B.y()){
			rightPainter->points[2] = B;
			rightPainter->points[3] = A;
			A = rightPainter->points[2];
			B = rightPainter->points[3];
		}
		rightPainter->drawExtenLine(A, B, 50, Qt::green);
	}
	if (rightPainter->points.size() == 5){
		int exten = abs(rightPainter->points[2].y() - rightPainter->points[3].y());
		rightPainter->drawExtenLine(rightPainter->points[2], rightPainter->points[4], exten);
	}
	if (rightPainter->points.size() == 7){
		rightPainter->drawExtenLine(rightPainter->points[5], rightPainter->points[6], 100);
		rightPainter->paintMode=PAINT_NONE;
		rightDraw->stop();
		rightMeasuring(rightPainter->points);
		rightPainter->points.clear();

		QImage qImage = rightPainter->theImage;
		Mat mImage = Mat(qImage.height(), qImage.width(), CV_8UC4, const_cast<uchar*>(qImage.bits()), qImage.bytesPerLine());
		saveImage("_Right_Analysis.jpg", mImage);

		ui.ivRightAnalysisImage->SetImage(qImage);
		ui.log->Log("... done!");
		rightProcess = None;
	}
}

void MainWindow::rightMeasuring(vector<QPoint> &points){
	rightFootLength = Line::lengthSegment(points[0], points[1]);
	rightFootLength *= rightImageScale*rightScannerScale;
	/*ui.lbRightFootLength->setText(QString::number(rightFootLength, 'f', 2));*/

	Line line1(points[2], points[3]);
	Line line2(points[2], points[4]);
	/*Tho Cao: rightAngle is nagative*/
	rightFootAngle = AngleFrom3Point_2(points[3], points[2], points[4]);
	/*ui.lbRightFootAngle->setText(QString::number(rightFootAngle, 'f', 2));*/

	rightPainter->drawLine(points[2], points[5]);
	Line line3(points[2], points[5]);
	float b4 = points[6].y() - line3.a*points[6].x();
	Line line4(line3.a, b4);
	QPointF it = Line::intersect2Lines(line2, line4);
	QPoint inter(it.x(), it.y());
	rightPainter->drawPoint(inter, Qt::green);
	rightPainter->drawLine(points[6], inter, Qt::magenta);

	vector<QPoint> topPoints = Line::divideSegment(points[2], points[5], 5);
	vector<QPoint> bottomPoints = Line::divideSegment(inter, points[6], 5);
	for (int i = 0; i < 4; i++){
		rightPainter->drawPoint(topPoints[i], Qt::cyan);
		rightPainter->drawPoint(bottomPoints[i], Qt::cyan);
		rightPainter->drawLine(topPoints[i], bottomPoints[i], Qt::red);
	}
}

void MainWindow::on_ckShowPassword_stateChanged(){
	if (ui.ckShowPassword->isChecked())
		ui.lePassword->setEchoMode(QLineEdit::Normal);
	else
		ui.lePassword->setEchoMode(QLineEdit::Password);
}

void MainWindow::on_pbConnectServer_clicked(){
	
	// Edited by K2Y

	/*
	DWORD dwReturnValue;
	DWORD dwFlags = CONNECT_UPDATE_PROFILE;
	QString ipAddress = "\\\\" + ui.leIPAddress->text();
	wstring wsIpAddress = ipAddress.utf16();
	wstring wsUserName = ui.leUserName->text().utf16();
	LPWSTR lpUserName = (LPWSTR)wsUserName.c_str();
	wstring wsPassword = ui.lePassword->text().utf16();
	LPWSTR lpPassword = (LPWSTR)wsPassword.c_str();
	memset(&netResource, 0, sizeof(NETRESOURCE));
	netResource.dwType = RESOURCETYPE_DISK;
	netResource.lpLocalName = NULL;
	netResource.lpRemoteName = (LPWSTR)wsIpAddress.c_str();
	dwReturnValue = WNetAddConnection2(&netResource, lpPassword, lpUserName, dwFlags);
	if (!dwReturnValue == NO_ERROR){
		QMessageBox::critical(this, "Connect to Server", "Connection failed with error !");
		return;
	}
	//else{
	//	QMessageBox::information(this, "Connect to Server", "Connection added to server !");
	//}
//	findSharedItems(netResource.lpRemoteName);
	defineTreeView();
	*/
}

/*9/20/106*/
void MainWindow::findSharedItems(LPWSTR lpIpAddress){
	PSHARE_INFO_1 BufPtr, p;
	DWORD er = 0, tr = 0, resume = 0, i;
	sharedDriveList.clear();
	NET_API_STATUS res;
	res = NetShareEnum(lpIpAddress, 1, (LPBYTE*)&BufPtr, MAX_PREFERRED_LENGTH, &er, &tr, &resume);

	if (res == ERROR_SUCCESS || res == ERROR_MORE_DATA){
		p = BufPtr;
		for (i = 1; i <= er; i++){
			wstring temp = p->shi1_netname;
			if ((temp[temp.size() - 1] != '$') && p->shi1_type == STYPE_DISKTREE){
				//sharedDriveList << QString::fromUtf16(temp.c_str());
			}
			p++;
		}
	}
}

void MainWindow::on_pbReloadScannerDrivers_clicked(){
	if (isLeftScannerConnect) leftScanner.twRelease();
	if (isRightScannerConnect) rightScanner.twRelease();
	ui.cbLeftScanner->clear();
	ui.cbRightScanner->clear();
	loadScannerSetting();
}

void MainWindow::loadScannerSetting(){
	ui.cbLeftScanner->addItem("< Select Left Scanner Driver >");
	ui.cbRightScanner->addItem("< Select Right Scanner Driver >");
	initializeScanners();
	ui.scrollAreaLeftFoot->setWidget(leftPainter);
	ui.scrollAreaRightFoot->setWidget(rightPainter);

	FILE *f = fopen("calibScanner.dat", "rb");
	if (!f){
		QMessageBox::critical(this, tr("Scanner Calibration"), QString("Can not load calibration data !"));
		return;
	}
	fread(&leftScannerScale, sizeof(float), 1, f);
	fread(&rightScannerScale, sizeof(float), 1, f);
	fclose(f);
	ui.leLeftScannerScale->setText(QString::number(leftScannerScale));
	ui.leRightScannerScale->setText(QString::number(rightScannerScale));
}

void MainWindow::on_pbSetSystemFolder_clicked(){
	sysPath = QFileDialog::getExistingDirectory(this, "Set System Folder", QString());
	showSysFiles();
}


void MainWindow::defineTreeView(){

	// Edited by K2Y

	// QString mPath = "\\\\" + ui.leIPAddress->text();
	// dirModel->setRootPath(mPath);
	// ui.treeView->setModel(dirModel);
	// showServerEntries();
}

void MainWindow::showServerEntries(){
	
	// Edited by K2Y

	//QString mPath = "\\\\" + ui.leIPAddress->text();
	//fileModel->setRootPath(mPath);
	//ui.listView->setModel(fileModel);
}

void MainWindow::showSysFiles(){
	QDir sysDir(sysPath);
	listSysFiles = sysDir.entryList(QDir::NoDotAndDotDot | QDir::Files);
	QStringListModel *sysFilesModel = new QStringListModel(this);
	sysFilesModel->setStringList(listSysFiles);
}

void MainWindow::on_treeView_clicked(const QModelIndex &index){
	
	// Edited by K2Y

	treeIndex = index;
	serverPath = dirModel->fileInfo(index).absoluteFilePath();
	//ui.listView->setRootIndex(fileModel->setRootPath(serverPath));
}

void MainWindow::on_pbUploadFiles_clicked(){
	/*Modified on 8/4/2016 : Asking for upload folder*/
	QMessageBox::StandardButton reply_person;
	reply_person = QMessageBox::question(this, "Upload File!", "Do you want to upload the selected folder?");
	if (reply_person == QMessageBox::Yes){

		QModelIndexList indexes = ui.listView2->selectionModel()->selectedIndexes();
		if (indexes.isEmpty()){
			QMessageBox::critical(this, "Uppload Files", "No file is selected!!!");
			return;
		}
		for (int i = 0; i < indexes.size(); i++){
			QString fileName = "/" + listSysFiles.at(indexes[i].row());
			QString sourceFullName = sysPath + fileName; std::cout << sourceFullName.toStdString() << std::endl;
			QString destFullName = serverPath + fileName; std::cout << destFullName.toStdString() << std::endl;
			//	if (!CopyFile(sourceFullName.utf16(), destFullName.utf16(), true)){
			if (!QFile::copy(sourceFullName, destFullName)){
				QMessageBox::critical(this, "Upload Files.. ", "Cannot upload file: " + fileName);
			}
		}
		defineTreeView();
	}
}

void MainWindow::on_pbMakeFolder_clicked(){
	QString folderName = QInputDialog::getText(this, "Make Folder", "Folder name:");
	if (folderName.isEmpty()) return;
	dirModel->mkdir(treeIndex, folderName);
	defineTreeView();
}

void MainWindow::on_pbMeasureWeight_clicked(){
	bridgeTimer->start();
}

void MainWindow::on_pbReloadBridge_clicked(){
	const char *deviceName;
	if (CPhidget_getDeviceName((CPhidgetHandle)bridge, &deviceName) != 0) {
		QMessageBox::critical(this, "Open Load Cells", "No Load Cell is detected!");
		ui.groupBox_LoadCell->setTitle("No Load Cell");
		return;
	}
	bridgeName = QString::fromUtf8(deviceName);
	ui.groupBox_LoadCell->setTitle(bridgeName);
	loadBridgeSetting();
}

void MainWindow::openBridge(){
	QStringList bridges, gains;
	bridges << "Bridge 0" << "Bridge 1" << "Bridge 2" << "Bridge 3";
	//ui.cbBridges->addItems(bridges);
	gains << "1" << "8" << "16" << "32" << "64" << "128";
	ui.cbBridgeGains->addItems(gains);
	bridgeRate = 200;
	selectedBridgeIndex = selectedGainIndex = 0;

	ui.leValue_1->setEnabled(false);
	ui.leValue_2->setEnabled(false);
	ui.leValue_3->setEnabled(false);
	ui.leValue_4->setEnabled(false);

	//ui.pbSet_1->setEnabled(false);
	//ui.pbSet_2->setEnabled(false);
	//ui.pbSet_3->setEnabled(false);
	//ui.pbSet_4->setEnabled(false);

	CPhidgetBridge_create(&bridge);
	CPhidget_open((CPhidgetHandle)bridge, -1);
	_sleep(100);
	const char *deviceName;
	if (CPhidget_getDeviceName((CPhidgetHandle)bridge, &deviceName) != 0) {
		QMessageBox::critical(this, "Open Load Cells", "No Load Cell is detected!");
		ui.groupBox_LoadCell->setTitle("No Load Cell");
		// add  flag bridge
		flag_loadcell_connection_status = 0;
		/*return;*/
	}
	else {
		flag_loadcell_connection_status = 1;
		bridgeName = QString::fromUtf8(deviceName);
		ui.groupBox_LoadCell->setTitle(bridgeName);
		loadBridgeSetting();
	}
}

void MainWindow::setBridge(){
	if (selectedGainIndex == 0) CPhidgetBridge_setGain(bridge, selectedBridgeIndex, PHIDGET_BRIDGE_GAIN_1);
	if (selectedGainIndex == 1) CPhidgetBridge_setGain(bridge, selectedBridgeIndex, PHIDGET_BRIDGE_GAIN_8);
	if (selectedGainIndex == 2) CPhidgetBridge_setGain(bridge, selectedBridgeIndex, PHIDGET_BRIDGE_GAIN_16);
	if (selectedGainIndex == 3) CPhidgetBridge_setGain(bridge, selectedBridgeIndex, PHIDGET_BRIDGE_GAIN_32);
	if (selectedGainIndex == 4) CPhidgetBridge_setGain(bridge, selectedBridgeIndex, PHIDGET_BRIDGE_GAIN_64);
	if (selectedGainIndex == 5) CPhidgetBridge_setGain(bridge, selectedBridgeIndex, PHIDGET_BRIDGE_GAIN_128);
	CPhidgetBridge_setDataRate(bridge, bridgeRate);
	bridgeCalibTimer->setInterval(bridgeRate);
	if (ui.ckEnabled->isChecked())
		CPhidgetBridge_setEnabled(bridge, selectedBridgeIndex, true);
	else
		CPhidgetBridge_setEnabled(bridge, selectedBridgeIndex, false);
	QString formula = QString("y = " + QString::number(calibBridgeParameters[selectedBridgeIndex][2]) + "*x^2 + " +
		QString::number(calibBridgeParameters[selectedBridgeIndex][1]) + "*x + " + 
		QString::number(calibBridgeParameters[selectedBridgeIndex][0]));
	ui.leFormula->setText(formula);
	bridgeIsSet = true;
}

void MainWindow::on_bridge(){

	double  real[4];
	real[0] = 0;
	real[1] = 0;
	real[2] = 0;
	real[3] = 0;
	// loop
	int sampling_number_fillter = 10;

	for (int j = 0; j != sampling_number_fillter; j++){

		double value_show[4];
		double value_tho;
		for (int i = 0; i < 4; i++){
			CPhidgetBridge_getBridgeValue(bridge, i, &value_tho);
			value_show[i] = value_tho;
		}

		// kalman filter
		float up_left_value = value_show[0];  float up_right_value = value_show[2];
		float dow_left_value = value_show[1]; float dow_right_value = value_show[3];



		if (kalman_fillter_leftFoot.flag_set_intial_value_for_loadCells == 0 && kalman_fillter_rightFoot.flag_set_intial_value_for_loadCells == 0){
			kalman_fillter_leftFoot.setInitialValueForLoadCells(up_left_value, dow_left_value);
			kalman_fillter_rightFoot.setInitialValueForLoadCells(up_right_value, dow_right_value);
		}
		else{
			float up_output_left = 0;  float up_output_right = 0;
			float dow_output_left = 0; float dow_output_right = 0;

			kalman_fillter_leftFoot.calCulateValueOfLoadCells(up_left_value, dow_left_value, up_output_left, dow_output_left);
			kalman_fillter_rightFoot.calCulateValueOfLoadCells(up_right_value, dow_right_value, up_output_right, dow_output_right);

			value_show[0] = up_output_left;
			value_show[1] = dow_output_left;

			value_show[2] = up_output_right;
			value_show[3] = dow_output_right;
		}
		// recalculate real value
		double load_cell1 = value_show[0]; double load_cell3 = value_show[2];
		double load_cell2 = value_show[1]; double load_cell4 = value_show[3];

		real[0] += calibBridgeParameters[0][2] * load_cell1*load_cell1 + calibBridgeParameters[0][1] * load_cell1 + calibBridgeParameters[0][0];

		real[1] += calibBridgeParameters[1][2] * load_cell2*load_cell2 + calibBridgeParameters[1][1] * load_cell2 + calibBridgeParameters[1][0];

		real[2] += calibBridgeParameters[2][2] * load_cell3*load_cell3 + calibBridgeParameters[2][1] * load_cell3 + calibBridgeParameters[2][0];

		real[3] += calibBridgeParameters[3][2] * load_cell4*load_cell4 + calibBridgeParameters[3][1] * load_cell4 + calibBridgeParameters[3][0];

	}

	real[0] /= sampling_number_fillter;
	real[1] /= sampling_number_fillter;
	real[2] /= sampling_number_fillter;
	real[3] /= sampling_number_fillter;

	real[0] -= real_offset[0];  real[0] /= 10; if (real[0] < 0)  real[0] = 0;
	real[1] -= real_offset[1];  real[1] /= 10; if (real[1] < 0)  real[1] = 0;
	real[2] -= real_offset[2];  real[2] /= 10; if (real[2] < 0)  real[2] = 0;
	real[3] -= real_offset[3];  real[3] /= 10; if (real[3] < 0)  real[3] = 0;

	/*Update: 9/20/2016*/
	/* inverse cnvention */
	//ui.lbFrontLeftFootWeight->setText(QString::number(real[0], 'f', 2));  // front Left -> back right
	//ui.lbBackLeftFootWeight->setText(QString::number(real[1], 'f', 2));   // back left  -> front right
	//ui.lbFrontRightFootWeight->setText(QString::number(real[2], 'f', 2)); // front right -> back left
	//ui.lbBackRightFootWeight->setText(QString::number(real[3], 'f', 2));  // back right -> front left

	// inverse convertion
	ui.lbFrontRightFootWeight->setText(QString::number(real[1], 'f', 2));
	ui.lbBackRightFootWeight->setText(QString::number(real[0], 'f', 2));
	ui.lbFrontLeftFootWeight->setText(QString::number(real[3], 'f', 2));
	ui.lbBackLeftFootWeight->setText(QString::number(real[2], 'f', 2));
	

	// show total weight
	double total_weight = real[0] + real[1] + real[2] + real[3];
	//if (THOCAO) total_weight /= 10;
	ui.statusBar->showMessage("Total Foot Weight:            " + QString::number(total_weight,'f',2));
}

void MainWindow::on_bridgeCalib(){
	if (!bridgeIsSet) setBridge();

	/*
	Edited by Tho
	Date: 7/25/2016
	Decription: take 4 value of load cell at the same time
	*/

	double value_tho, value_show[4];
	for (int i = 0; i != 4; i++){
		CPhidgetBridge_getBridgeValue(bridge, i, &value_tho);
		value_show[i] = value_tho;
	}
	// kalman filter
	float up_left_value = value_show[0];  float up_right_value = value_show[2];
	float dow_left_value = value_show[1]; float dow_right_value = value_show[3];



	if (kalman_fillter_leftFoot.flag_set_intial_value_for_loadCells == 0 && kalman_fillter_rightFoot.flag_set_intial_value_for_loadCells == 0){
		kalman_fillter_leftFoot.setInitialValueForLoadCells(up_left_value, dow_left_value);
		kalman_fillter_rightFoot.setInitialValueForLoadCells(up_right_value, dow_right_value);
	}
	else{
		float up_output_left = 0;  float up_output_right = 0;
		float dow_output_left = 0; float dow_output_right = 0;

		kalman_fillter_leftFoot.calCulateValueOfLoadCells(up_left_value, dow_left_value, up_output_left, dow_output_left);
		kalman_fillter_rightFoot.calCulateValueOfLoadCells(up_right_value, dow_right_value, up_output_right, dow_output_right);

		value_show[0] = up_output_left;
		value_show[1] = dow_output_left;

		value_show[2] = up_output_right;
		value_show[3] = dow_output_right;
	}
	// flag saving
	if (flag_calibValue_save == 1){
		if (!ui.leValue_5->text().isEmpty()){

			calibValue_sensor[0].push_back(value_show[0]);
			calibValue_sensor[1].push_back(value_show[1]);
			calibValue_sensor[2].push_back(value_show[2]);
			calibValue_sensor[3].push_back(value_show[3]);


			double real_kg = ui.leValue_5->text().toDouble();
			calibVaue_real.push_back(real_kg);

			flag_calibValue_save = 0;
			std::cout << "Sensor Value Saved " << std::endl;
		}
		else{
			std::cout << "Please fill in the value" << std::endl;
			flag_calibValue_save = 0;
		}
	}

	ui.leValue_1->setText(QString::number(value_show[0]));
	ui.leValue_2->setText(QString::number(value_show[1]));
	ui.leValue_3->setText(QString::number(value_show[2]));
	ui.leValue_4->setText(QString::number(value_show[3]));

}

void MainWindow::on_cbBridges_activated(){
	//selectedBridgeIndex = ui.cbBridges->currentIndex();
	bridgeIsSet = false;
}

void MainWindow::on_cbBridgeGains_activated(){
	selectedGainIndex = ui.cbBridgeGains->currentIndex();
	bridgeIsSet = false;
}

void MainWindow::on_ckEnabled_stateChanged(){
	if (ui.ckEnabled->isChecked()){
		CPhidgetBridge_setEnabled(bridge, selectedBridgeIndex, true);
		bridgeCalibTimer->start();
	}
	else{
		bridgeCalibTimer->stop();
		CPhidgetBridge_setEnabled(bridge, selectedBridgeIndex, false);
	}
}

void MainWindow::on_slRate_valueChanged(){
	bridgeRate = ui.slRate->value();
	ui.leRate->setText(QString::number(bridgeRate));
	bridgeIsSet = false;
}

void MainWindow::on_leRate_editingFinished(){
	bridgeRate = ui.leRate->text().toInt();
	ui.slRate->setValue(bridgeRate);
	bridgeIsSet = false;
}

void MainWindow::on_pbBridgeCalib_clicked(){
	// a Cuong 
	//ui.leValue_1->setEnabled(true);
	//ui.pbSet_1->setEnabled(true);
	
	// Edited by Tho
	ui.leValue_5->setEnabled(true);
	ui.pbSet_5->setEnabled(true);
	ui.pbSet_6->setEnabled(true);

	ui.pbBridgeCalib->setEnabled(false);
}

void MainWindow::on_pbSet_1_clicked(){
	//bridgeValue = ui.leBridgeValue->text().toDouble();
	realValue = ui.leValue_1->text().toDouble();
	calibValues[0][0] = bridgeValue;
	calibValues[0][1] = realValue;
	ui.leValue_1->setEnabled(false);
	//ui.pbSet_1->setEnabled(false);
	ui.leValue_2->setEnabled(true);
	//ui.pbSet_2->setEnabled(true);
}

void MainWindow::on_pbSet_2_clicked(){
	//bridgeValue = ui.leBridgeValue->text().toDouble();
	realValue = ui.leValue_2->text().toDouble();
	calibValues[1][0] = bridgeValue;
	calibValues[1][1] = realValue;
	ui.leValue_2->setEnabled(false);
	//ui.pbSet_2->setEnabled(false);
	ui.leValue_3->setEnabled(true);
	//ui.pbSet_3->setEnabled(true);
}

void MainWindow::on_pbSet_3_clicked(){
	//bridgeValue = ui.leBridgeValue->text().toDouble();
	realValue = ui.leValue_3->text().toDouble();
	calibValues[2][0] = bridgeValue;
	calibValues[2][1] = realValue;
	ui.leValue_3->setEnabled(false);
	//ui.pbSet_3->setEnabled(false);
	ui.leValue_4->setEnabled(true);
	//ui.pbSet_4->setEnabled(true);
}

void MainWindow::on_pbSet_4_clicked(){
	//bridgeValue = ui.leBridgeValue->text().toDouble();
	realValue = ui.leValue_4->text().toDouble();
	calibValues[3][0] = bridgeValue;
	calibValues[3][1] = realValue;
	ui.leValue_4->setEnabled(false);
	//ui.pbSet_4->setEnabled(false);
	ui.pbBridgeCalib->setEnabled(true);
	/*9/20/2016*/
	//bridgeCalibration();
}

// Tho
void MainWindow::on_pbSet_5_clicked(){

	number_calibValue_save += 1;
	ui.label_32->setText("Times Saved " + QString::number(number_calibValue_save));

	if (flag_calibValue_save == 0){
		flag_calibValue_save = 1;
		std::cout << "save" << std::endl;
	}
	else {
		flag_calibValue_save = 0;
		std::cout << "not save" << std::endl;
	}
}

void MainWindow::on_pbSet_6_clicked(){

	if (calibVaue_real.size() > 0){
		number_calibValue_save -= 1;
		ui.label_32->setText("Times Saved " + QString::number(number_calibValue_save));

		calibValue_sensor[0].pop_back();
		calibValue_sensor[1].pop_back();
		calibValue_sensor[2].pop_back();
		calibValue_sensor[3].pop_back();

		calibVaue_real.pop_back();

		std::cout << " removed one data" << std::endl;
	}
	else{
		std::cout << "data < 0 " << std::endl;
	}
	
}

//void MainWindow::bridgeCalibration(){
//	Mat bridge(4, 1, CV_32F);
//	Mat real(4, 1, CV_32F);
//	for (int i = 0; i < 4; i++){
//		bridge.at<float>(i, 0) = calibValues[i][0];
//		real.at<float>(i, 0) = calibValues[i][1];
//	}
//	Mat result(3, 1, CV_32F);
//	polyfit(bridge, real, result, 2);
//	for (int i = 0; i < 3; i++){
//		float temp = result.at<float>(i, 0);
//		calibBridgeParameters[selectedBridgeIndex][i] = temp;
//	}
//	bridgeIsSet = false;
//}

bool MainWindow::re_calculate_value_each_sensor(std::vector<double> *calib_Sensor,
	std::vector<double> &calib_Real_Value){
	// checking size of data

	if (calib_Real_Value.size() >= 3)
	{
		for (int i = 0; i != calib_Real_Value.size(); i++){
			double total_value = calib_Real_Value[i];

			double gate_1 = calib_Sensor[0][i] - calib_Sensor[0][0]; if (gate_1 < 0) gate_1 = 0;
			double gate_2 = calib_Sensor[1][i] - calib_Sensor[1][0]; if (gate_2 < 0) gate_2 = 0;
			double gate_3 = calib_Sensor[2][i] - calib_Sensor[2][0]; if (gate_3 < 0) gate_3 = 0;
			double gate_4 = calib_Sensor[3][i] - calib_Sensor[3][0]; if (gate_4 < 0) gate_4 = 0;

			double total_gate = gate_1 + gate_2 + gate_3 + gate_4; if (total_gate < 0) total_gate = 1;

			double real_load_cell_1 = gate_1*total_value / total_gate;
			if (gate_1 == 0){
				re_Real_Value_sensor[0].push_back(0);
			}
			else re_Real_Value_sensor[0].push_back(real_load_cell_1);

			double real_load_cell_2 = gate_2*total_value / total_gate;
			if (gate_2 == 0){
				re_Real_Value_sensor[1].push_back(0);
			}
			else re_Real_Value_sensor[1].push_back(real_load_cell_2);

			double real_load_cell_3 = gate_3*total_value / total_gate;
			if (gate_3 == 0){
				re_Real_Value_sensor[2].push_back(0);
			}
			else re_Real_Value_sensor[2].push_back(real_load_cell_3);

			double real_load_cell_4 = gate_4*total_value / total_gate;
			if (gate_4 == 0){
				re_Real_Value_sensor[3].push_back(0);
			}
			else re_Real_Value_sensor[3].push_back(real_load_cell_4);

		}

		return 1;
	}
	else return 0;

}

void MainWindow::re_bridgeCalibration(std::vector<double> *calibValue_Sensor,
	std::vector<double> *calibVaue_real_each_sensor,
	float(*calibBridgeParameters)[3]){

	// from here adding 4 value:

	for (int index = 0; index != 4; index++){

		Mat Tu(calibValue_Sensor[index].size(), 3, CV_64F);
		Mat Mau(calibVaue_real_each_sensor[index].size(), 1, CV_64F);
		for (int i = 0; i != calibVaue_real_each_sensor[index].size(); i++){
			double sensor_1 = calibValue_Sensor[index][i];
			double A1 = sensor_1*sensor_1;
			double B1 = sensor_1;
			double C1 = 1;
			Tu.at<double>(i, 0) = A1; Tu.at<double>(i, 1) = B1; Tu.at<double>(i, 2) = C1;

			Mau.at<double>(i) = calibVaue_real_each_sensor[index][i];

		}

		cv::Mat result; cv::solve(Tu, Mau, result, cv::DECOMP_NORMAL);

		// luu vao mang: calibBridgeParameters
		calibBridgeParameters[index][0] = result.at<double>(2);
		calibBridgeParameters[index][1] = result.at<double>(1);
		calibBridgeParameters[index][2] = result.at<double>(0);
	}



}
std::vector<cv::Point2f> MainWindow::orderTargets(std::vector<cv::Point2f> allTargets){
	std::vector<cv::Point2f> orderedTargets;
	unsigned int i1, i2, i3, i4, i5;
	unsigned int nCCC = allTargets.size();

	// Find 3 CCCs that are in a line
	double dMin = 1e9;
	for (unsigned int i = 0; i<nCCC; i++)	{
		for (unsigned int j = i + 1; j<nCCC; j++)	{
			// Get the mid point between i,j
			cv::Point2f midPt = (allTargets[i] + allTargets[j]) * 0.5;

			// Find the CCC that is closest to this midpoint
			for (unsigned int k = 0; k<nCCC; k++)	{
				if (k == i || k == j)	continue;
				float d = norm(allTargets[k] - midPt);
				if (d < dMin)	{
					dMin = d;
					i1 = i;
					i2 = k;
					i3 = j;
				}
			}
		}
	}
	if (dMin > 15.0)	return orderedTargets;	// return an empty list

	// We have found 3 colinear targets:  p1 -- p2 -- p3.
	// Now find the one closest to p1; call it p4.
	dMin = 1e9;
	for (unsigned int i = 0; i<nCCC; i++)	{
		if (i != i1 && i != i2 && i != i3)	{
			double d = norm(allTargets[i] - allTargets[i1]);
			if (d < dMin)	{
				dMin = d;
				i4 = i;
			}
		}
	}
	if (dMin > 1e7)	return orderedTargets;	// return an empty list

	// Now find the one closest to p3; call it p5.
	dMin = 1e9;
	for (unsigned int i = 0; i<nCCC; i++)	{
		if (i != i1 && i != i2 && i != i3 && i != i4)	{
			double d = norm(allTargets[i] - allTargets[i3]);
			if (d < dMin)	{
				dMin = d;
				i5 = i;
			}
		}
	}
	if (dMin > 1e7)	return orderedTargets;	// return an empty list

	// Now, check to see where p4 is with respect to p1,p2,p3.  If the
	// signed area of the triangle p1-p3-p4 is negative, then we have
	// the correct order; ie
	//		1   2   3
	//		4		5
	// Otherwise we need to switch the order; ie
	//		3	2	1
	//		5		4

	// Signed area is the determinant of the 2x2 matrix [ p4-p1, p3-p1 ]
	cv::Vec2f p41 = allTargets[i4] - allTargets[i1];
	cv::Vec2f p31 = allTargets[i3] - allTargets[i1];
	double m[2][2] = { { p41[0], p31[0] }, { p41[1], p31[1] } };
	double det = m[0][0] * m[1][1] - m[0][1] * m[1][0];

	// Put the targets into the output list.
	if (det < 0)	{
		orderedTargets.push_back(allTargets[i1]);
		orderedTargets.push_back(allTargets[i2]);
		orderedTargets.push_back(allTargets[i3]);
		orderedTargets.push_back(allTargets[i4]);
		orderedTargets.push_back(allTargets[i5]);
	}
	else	{
		orderedTargets.push_back(allTargets[i3]);
		orderedTargets.push_back(allTargets[i2]);
		orderedTargets.push_back(allTargets[i1]);
		orderedTargets.push_back(allTargets[i5]);
		orderedTargets.push_back(allTargets[i4]);
	}

	return orderedTargets;
}
bool MainWindow::ScaleFactor_Scanner(cv::Mat &image_side, float &scale_factor, float &ImageScale){

	cv::Mat img_process;
    std:vector<cv::Point2f> allPointCircle;


	if (image_side.channels() == 3) cv::cvtColor(image_side, img_process, cv::COLOR_BGR2GRAY);
	else  image_side.copyTo(img_process);

	cv::Mat img_thresh;
	cv::adaptiveThreshold(img_process, img_thresh, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY_INV, 91, 0);

	cv::Mat structuringElmt = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3, 3));
	cv::Mat img_Open;
	cv::morphologyEx(img_thresh, img_Open, cv::MORPH_OPEN, structuringElmt);
	cv::Mat img_Close;
	cv::morphologyEx(img_Open, img_Close, cv::MORPH_CLOSE, structuringElmt);

	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierachy;

	if (img_Close.empty()) return 0;

	cv::findContours(img_Close, contours, hierachy, cv::RETR_CCOMP, cv::CHAIN_APPROX_TC89_L1);

	for (unsigned int i1 = 0; i1 != contours.size(); i1++){
		int i2 = hierachy[i1][2];

		if (i2 > 0){
			cv::Mat pointsf;
			cv::Mat(contours[i1]).convertTo(pointsf, CV_32F);

			cv::RotatedRect temp = cv::fitEllipse(pointsf);

			cv::Point2f x1(temp.center.x, temp.center.y);
			cv::Moments mu2 = cv::moments(contours[i2]);
			cv::Point2f x2(mu2.m10 / mu2.m00, mu2.m01 / mu2.m00);

			// Check if centroids coincide
			if (norm(x1 - x2) > 3) continue;

			double P1 = arcLength(contours[i1], true);
			double A1 = contourArea(contours[i1]);
			if (4 * 3.1415*A1 / (P1*P1) < 3.1415 / 4)
				// Let's say that we want our region to be at least as
				// round as a square.
				continue;

			// This must be a valid target; add it to the output list.
			allPointCircle.push_back(x1);
		}
	}

	if (allPointCircle.size() == 5){
		std::vector<cv::Point2f> order_allCirle = orderTargets(allPointCircle);

		float distance_pixel = cv::norm(order_allCirle[0] - order_allCirle[1]);
		scale_factor = factor_scale_patter / (distance_pixel*ImageScale*ImageScale);

		return 1;
	}
	else{
		return 0;
	}
}
void MainWindow::on_pbSaveBridgeSetting_clicked(){


	// Edited by Tho
	bool found = re_calculate_value_each_sensor(calibValue_sensor, calibVaue_real);
	if (found){
		re_bridgeCalibration(calibValue_sensor, re_Real_Value_sensor, calibBridgeParameters);
		for (int i = 0; i != 4; i++){
			std::cout << " " << calibBridgeParameters[i][0] << " " << calibBridgeParameters[i][1] << " " << calibBridgeParameters[i][2] << endl;;
		}
	}

	FILE *caliBridgef = fopen("calibBridge.dat", "wb");
	if (!caliBridgef){
		QMessageBox::critical(this, tr("Load Cell Calibration"), QString("Can not save calibration data !"));
		return;
	}
	for (int i = 0; i < 4; i++){
		fwrite(&calibBridgeParameters[i][0], sizeof(float), 1, caliBridgef);
		fwrite(&calibBridgeParameters[i][1], sizeof(float), 1, caliBridgef);
		fwrite(&calibBridgeParameters[i][2], sizeof(float), 1, caliBridgef);
	}
	fclose(caliBridgef);
	// load data
	const char *deviceName;
	if (CPhidget_getDeviceName((CPhidgetHandle)bridge, &deviceName) != 0) {
		QMessageBox::critical(this, "Open Load Cells", "No Load Cell is detected!");
		ui.groupBox_LoadCell->setTitle("No Load Cell");
		return;
	}
	bridgeName = QString::fromUtf8(deviceName);
	ui.groupBox_LoadCell->setTitle(bridgeName);
	loadBridgeSetting();
}

void MainWindow::loadBridgeSetting(){
	FILE *caliBridgef = fopen("calibBridge.dat", "rb");
	if (!caliBridgef){
		QMessageBox::critical(this, tr("Load Cell Calibration"), QString("Cannot load calibration data !"));
		return;
	}
	for (int i = 0; i < 4; i++){
		
		fread(&calibBridgeParameters[i][0], sizeof(float), 1, caliBridgef);
		fread(&calibBridgeParameters[i][1], sizeof(float), 1, caliBridgef);
		fread(&calibBridgeParameters[i][2], sizeof(float), 1, caliBridgef);
		CPhidgetBridge_setEnabled(bridge, i, true);
		CPhidgetBridge_setDataRate(bridge, bridgeRate);
	}
	fclose(caliBridgef);
}

void MainWindow::on_pbSaveAnalysisResults_clicked(){

	/*Tho Cao*/   /* Pr.Kim*/
	double front_Left_Weight =  ui.lbFrontLeftFootWeight->text().toDouble();
	double back_Left_Weight =   ui.lbBackLeftFootWeight->text().toDouble();
	double front_Right_Weight = ui.lbFrontRightFootWeight->text().toDouble();
	double back_Right_Weight =  ui.lbBackRightFootWeight->text().toDouble();
	
	double total_Weight = front_Left_Weight + back_Left_Weight + front_Right_Weight + back_Right_Weight;

	front_Left_Weight  = 100 * front_Left_Weight / (total_Weight);

	back_Left_Weight   = 100 * back_Left_Weight /  (total_Weight);

	front_Right_Weight = 100 * front_Right_Weight / (total_Weight);

	back_Right_Weight  = 100 * back_Right_Weight / (total_Weight);

	double distance_glass_a1 = leftImageScale*leftScannerScale*leftCenters[0].y() + 42.0;
	double distance_glass_b1 = leftImageScale*leftScannerScale*leftCenters[1].y() + 42.0;
	double distance_glass_a2 = rightImageScale*rightScannerScale*rightCenters[0].y() + 42.0;
	double distance_glass_b2 = rightImageScale*rightScannerScale*rightCenters[1].y() + 42.0;
	double distance_glass_c = 450.0;

	double t_front_Left_Weight  = front_Left_Weight;
	double t_back_Left_Weight   = back_Left_Weight;
	double t_front_Right_Weight = front_Right_Weight;
	double t_back_Right_Weight =  back_Right_Weight;

	//double t_front_Left_Weight = front_Left_Weight;
	//double t_back_Left_Weight = back_Left_Weight;
	//double t_front_Right_Weight = back_Right_Weight;
	//double t_back_Right_Weight = front_Right_Weight;

	front_Left_Weight  = (distance_glass_b1*t_front_Left_Weight + (distance_glass_b1 - distance_glass_c)*t_back_Left_Weight) / (distance_glass_b1 - distance_glass_a1);
	back_Left_Weight   = (-1.0*distance_glass_a1*t_front_Left_Weight + (distance_glass_c - distance_glass_a1)*back_Left_Weight) / (distance_glass_b1 - distance_glass_a1);
	front_Right_Weight = (distance_glass_b2*t_front_Right_Weight + (distance_glass_b2 - distance_glass_c)*t_back_Right_Weight) / (distance_glass_b2 - distance_glass_a2);
	back_Right_Weight  = (-1.0*distance_glass_a2*t_front_Right_Weight + (distance_glass_c - distance_glass_a2)*back_Right_Weight) / (distance_glass_b2 - distance_glass_a2);

	total_Weight = front_Left_Weight + back_Left_Weight + front_Right_Weight + back_Right_Weight;

	front_Left_Weight = 100 * front_Left_Weight / (total_Weight);
	back_Left_Weight = 100 * back_Left_Weight / (total_Weight);
	front_Right_Weight = 100 * front_Right_Weight / (total_Weight);
	back_Right_Weight = 100 * back_Right_Weight / (total_Weight);

	QString t_TempQstring;
	ui.lbFrontLeftFootWeight->setText(t_TempQstring.number(front_Left_Weight));
	ui.lbBackLeftFootWeight->setText(t_TempQstring.number(back_Left_Weight));
	ui.lbFrontRightFootWeight->setText(t_TempQstring.number(front_Right_Weight));
	ui.lbBackRightFootWeight->setText(t_TempQstring.number(back_Right_Weight));

	/* Pr.Kim*/
	QString t_foldername1 = "/" + ui.dateEdit->text();
	QString t_foldername2 = "/" + ui.leCustomerName->text();

	t_foldername1.remove(" ");
	t_foldername2.remove(" ");

	t_foldername1 = sysPath + t_foldername1;
	t_foldername2 = t_foldername1 + t_foldername2;

	MyMakeFolder(t_foldername1);
	MyMakeFolder(t_foldername2);

	QString fileName = ui.dateEdit->text() + "_" + ui.leCenterName->text() + "_" + ui.leCustomerName->text()  +"_Results.txt";
	fileName.remove(" ");
	fileName = t_foldername2 + "/" + fileName;

	QFile file(fileName);
	file.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream outStream(&file);
	outStream << "@@@@@ 왼발 @@@@@ \n";
	outStream << QString(" 발앞쪽 하중점: [").append(QString::number(leftCenters[0].x()).append(", ").append(QString::number(leftCenters[0].y()).append("] - ").append(QString::number(front_Left_Weight).append(" %\n"))));
	outStream << QString(" 발뒷굼치 하중점: [").append(QString::number(leftCenters[1].x()).append(", ").append(QString::number(leftCenters[1].y()).append("] - ").append(QString::number(back_Left_Weight).append(" %\n"))));

	outStream << QString(" 발 길이         : ").append(ui.lbLeft_Lenght_Line4->text()).append(" cm\n");
	outStream << QString(" 발 나비         : ").append(ui.lbLeft_Lenght_Line3->text()).append(" cm\n");
	outStream << QString(" 발 뒷꿈치 나비  : ").append(ui.lbLeft_Lenght_Line5->text()).append(" cm\n");
	outStream << QString(" Shell 길이      : ").append(ui.lbLeft_Lenght_Vertical->text()).append(" cm\n");
	outStream << QString(" 엄지발가락 각도 : ").append(ui.lbLeft_Angle_L1_L2->text()).append(" deg\n");
	outStream << QString(" 조인트 각도     : ").append(ui.lbLeft_Angle_Upper->text()).append(" deg\n");
	outStream << QString(" 추가 길이       : ").append(ui.lbLeft_Distance->text()).append(" cm\n");


	outStream << "\n@@@@@ 오른발 @@@@@ \n";
	outStream << QString(" 발앞쪽 하중점: [").append(QString::number(rightCenters[0].x()).append(", ").append(QString::number(rightCenters[0].y()).append("] - ").append(QString::number(front_Right_Weight).append(" %\n"))));
	outStream << QString(" 발뒷굼치 하중점: [").append(QString::number(rightCenters[1].x()).append(", ").append(QString::number(rightCenters[1].y()).append("] - ").append(QString::number(back_Right_Weight).append(" %\n"))));

	outStream << QString(" 발 길이         : ").append(ui.lbRight_Lenght_Line4->text()).append(" cm\n");
	outStream << QString(" 발 나비         : ").append(ui.lbRight_Lenght_Line3->text()).append(" cm\n");
	outStream << QString(" 발 뒷꿈치 나비  : ").append(ui.lbRight_Lenght_Line5->text()).append(" cm\n");
	outStream << QString(" Shell 길이      : ").append(ui.lbRight_Lenght_Vertical->text()).append(" cm\n");
	outStream << QString(" 엄지발가락 각도 : ").append(ui.lbRight_Angle_L1_L2->text()).append(" deg\n");
	outStream << QString(" 조인트 각도     : ").append(ui.lbRight_Angle_Upper->text()).append(" deg\n");
	outStream << QString(" 추가 길이: ").append(ui.lbRight_Distance->text()).append(" cm\n");

	file.close();
}

void MainWindow::closeEvent(QCloseEvent *event){
	if(isLeftScannerConnect) leftScanner.twRelease();
	if(isRightScannerConnect) rightScanner.twRelease();
	event->accept();
}




void MainWindow::on_scanner_status_changed(QString msg){
}

void MainWindow::on_scanner_error(QString msg){
	QMessageBox::critical(this, "ERROR", msg);
}
void MainWindow::on_scanner_image_captured(cv::Mat msg){
	cv::imshow("img", msg);
	waitKey();
}

char* MainWindow::MyMakeFolder(QString t_str2){

	QByteArray l_byteName = t_str2.toLocal8Bit();

	char *l_pathname = l_byteName.data();

	//_mkdir(l_pathname);

	// Edited by Tho
	QDir makeFolder(t_str2);
	if (!makeFolder.exists()){
		makeFolder.mkpath(".");
	}
	//else QMessageBox::critical(this, "Create Folder ", "This Folder Already Avalible: ");

	return l_pathname;
}

cv::Mat MainWindow::comBineImages(cv::Mat &image1, cv::Mat &image2){

	int channels = image1.channels();
	cv::Mat totalImage = cv::Mat(image1.rows , image1.cols + image2.cols, image1.type());
	if (image1.cols != image2.cols || image1.rows != image2.rows) return totalImage;
	else{
		for (unsigned int i = 0; i != totalImage.rows; i++){
			uchar *iM1 = image1.ptr<uchar>(i);
			uchar *iM2 = image2.ptr<uchar>(i);
			uchar *iM3 = totalImage.ptr<uchar>(i);
			for (unsigned int j = 0; j != image1.cols*channels; j += channels){
				// left
				iM3[j] = iM1[j];
				iM3[j + 1] = iM1[j + 1];
				iM3[j + 2] = iM1[j + 2];
				// right
				iM3[image1.cols*channels + j] = iM2[j];
				iM3[image1.cols*channels + j + 1] = iM2[j + 1];
				iM3[image1.cols*channels + j + 2] = iM2[j + 2];

			}

		}
		return totalImage;
	}

}

/*
  Date: 9/20/2016
  Decription: Old Customer Remodify
*/
void MainWindow::on_pbOldCustomer_clicked(){
	// read customer image
	QString fileName = QFileDialog::getOpenFileName(this, tr("TIFF (*.tif);; All files (*.*)"));
	QImage mainImg = QImage(fileName);
	if (mainImg.isNull()) return;
	cv::Mat customer_img = cv::Mat(mainImg.height(), mainImg.width(),CV_8UC4 ,
		const_cast<uchar*>(mainImg.bits()),
		mainImg.bytesPerLine()).clone();
	// for the left measurement

	cv::Mat left_img = customer_img(cv::Rect(0, 0, customer_img.cols / 2, customer_img.rows));
	cv::Mat right_img = customer_img(cv::Rect(customer_img.cols / 2,0, customer_img.cols / 2, customer_img.rows));

	// show to monitor

	// Left Foot
	leftScanImage = left_img;
	cv::Mat image_left;
	cvtColor(leftScanImage, image_left, CV_RGB2BGR);
	QImage qimg_left(image_left.data, image_left.cols, image_left.rows, image_left.step, QImage::Format_RGB888);
	leftPainter->setImage(qimg_left);
	leftImageScale = 1.0 / leftPainter->resizeFactor;
	ui.lbLeftImageScale->setText(QString::number(leftImageScale));
	leftProcess = Scan;
	// Right Foot
	rightScanImage = right_img;
	Mat image_right;
	cvtColor(rightScanImage, image_right, CV_RGB2BGR);
	QImage qimg_right(image_right.data, image_right.cols, image_right.rows, image_right.step, QImage::Format_RGB888);
	rightPainter->setImage(qimg_right);
	rightImageScale = 1.0 / rightPainter->resizeFactor;
	ui.lbRightImageScale->setText(QString::number(rightImageScale));
	rightProcess = Scan;

	// loadcell reload value
	QString systemPath_loadcel = QFileInfo(fileName).path();

	
	QDir::setCurrent(systemPath_loadcel);

	QStringList nameCustomer = systemPath_loadcel.split("/");
	// reload date and name of customer
	QDate customer_date = QDate::fromString(nameCustomer[nameCustomer.size() - 2],"yyyy-MM-dd");
	ui.dateEdit->setDate(customer_date);
	ui.leCustomerName->setText(nameCustomer[nameCustomer.size() - 1]);


	// read value of the original load cell
	LoadDtaLoadCell();

	ui.statusBar->showMessage(nameCustomer[nameCustomer.size()-2]);
	// return the current folder
	QDir::setCurrent(system_path_original);
}

void MainWindow::SaveDataLoadCell(){
	/*Tho Cao*/
	double front_Left_Weight = ui.lbFrontLeftFootWeight->text().toDouble();
	double back_Left_Weight = ui.lbBackLeftFootWeight->text().toDouble();
	double front_Right_Weight = ui.lbFrontRightFootWeight->text().toDouble();
	double back_Right_Weight = ui.lbBackRightFootWeight->text().toDouble();
	std::string fileName_loadcel = "loadcell.xml";
	cv::FileStorage fs(fileName_loadcel, cv::FileStorage::WRITE);
	fs << "UpLeft" << front_Left_Weight;
	fs << "DownLeft" << back_Left_Weight;
	fs << "UpRight" << front_Right_Weight;
	fs << "DownRight" << back_Right_Weight;

	fs.release();
	QString t_foldername1 = "/" + ui.dateEdit->text();
	QString t_foldername2 = "/" + ui.leCustomerName->text();

	t_foldername1.remove(" ");
	t_foldername2.remove(" ");

	t_foldername1 = sysPath + t_foldername1;
	t_foldername2 = t_foldername1 + t_foldername2;

	MyMakeFolder(t_foldername1);
	MyMakeFolder(t_foldername2);

	QString fileName = "loadcell.xml";
	fileName.remove(" ");
	fileName = t_foldername2 + "/" + fileName;

	QFile::copy("loadcell.xml", fileName);

	// delete the current file
	QFile load_cell("loadcell.xml");
	load_cell.remove();

}

void MainWindow::LoadDtaLoadCell(){
	std::string fileName_loadcel = "loadcell.xml";
	cv::FileStorage fs(fileName_loadcel, cv::FileStorage::READ);

	double front_Left_Weight = 0;
	double back_Left_Weight = 0;
	double front_Right_Weight = 0;
	double back_Right_Weight = 0;

	fs["UpLeft"] >> front_Left_Weight;
	fs["DownLeft"] >> back_Left_Weight;
	fs["UpRight"] >> front_Right_Weight;
	fs["DownRight"]>> back_Right_Weight;

	ui.lbFrontLeftFootWeight->setText(QString::number(front_Left_Weight, 'f', 2));  // front Left -> back right
	ui.lbBackLeftFootWeight->setText(QString::number(back_Left_Weight, 'f', 2));   // back left  -> front right
	ui.lbFrontRightFootWeight->setText(QString::number(front_Right_Weight, 'f', 2)); // front right -> back left
	ui.lbBackRightFootWeight->setText(QString::number(back_Right_Weight, 'f', 2));  // back right -> front left

	fs.release();
}

/*
  last modify: 28-10-2016
*/

bool MainWindow::eventFilter(QObject *obj, QEvent *event){

	if (obj == leftPainter){
		if (event->type() == QEvent::MouseButtonPress){
			if (ui.radioButton_left->isChecked()){
				/*flag_draw_point_left = 1;
				flag_draw_point_right = 0;*/
				const QMouseEvent* const me_ptr = static_cast<const QMouseEvent*>(event);
				QPoint click_point = me_ptr->pos();
				leftPainter->drawPoint(click_point, Qt::red, 10);

				// save point
				point_leftFoot.push_back(click_point);
				// emiting signal;
				leftFootMeasured();
			}
			else if (ui.radioButton_left_foot_mearsure->isChecked()){
				const QMouseEvent* const me_ptr = static_cast<const QMouseEvent*>(event);
				QPoint click_point = me_ptr->pos();

				switch (distance_left_point.size()){


					case 0: leftPainter->drawPoint_temp(click_point, Qt::blue, 10);
						    break;

					case 1: leftPainter->drawPoint_temp2(click_point, Qt::blue, 10);
						    break;

					default: break;
				
				}
				
				// save point
				distance_left_point.push_back(click_point);
				// emiting signal;
				distance_left_go();
			}

		}
		return 0;
	}
	else if (obj == rightPainter){
		if (event->type() == QEvent::MouseButtonPress){
			if (ui.radioButton_right->isChecked()){
				const QMouseEvent* const me_ptr = static_cast<const QMouseEvent*>(event);
				QPoint click_point = me_ptr->pos();
				rightPainter->drawPoint(click_point, Qt::red, 10);
				// save point
				point_rightFoot.push_back(click_point);
				// emiting signal;
				rightFootMeasured();
			}
			else if (ui.radioButton_right_foot_mearsure->isChecked()){
				const QMouseEvent* const me_ptr = static_cast<const QMouseEvent*>(event);
				QPoint click_point = me_ptr->pos();

				switch (distance_right_point.size()){


				case 0: rightPainter->drawPoint_temp(click_point, Qt::blue, 10);
					break;

				case 1: rightPainter->drawPoint_temp2(click_point, Qt::blue, 10);
					break;


				default: break;

				}
				// save point
				distance_right_point.push_back(click_point);
				// emiting signal;
				distance_right_go();
			}

		}
		
		return 0;
	}
	else return QMainWindow::eventFilter(obj, event);
}


void MainWindow::processing_leftFoot(){
	std::cout << "left click " << std::endl;
	/*std::cout << "size: " << point_leftFoot.size() << std::endl;*/
	// selection done
	if (point_leftFoot.size() == 7){
		// line 1
		Line line1(point_leftFoot[2], point_leftFoot[3]);

		leftPainter->drawExtenLine(point_leftFoot[2], point_leftFoot[3], 100, Qt::red, 1);
		// line 2

		Line line2(point_leftFoot[1], point_leftFoot[2]);
		leftPainter->drawExtenLine(point_leftFoot[1], point_leftFoot[2], 100, Qt::red, 1);
		// line 3
		Line line3(point_leftFoot[2], point_leftFoot[6]);
		leftPainter->drawLine(point_leftFoot[2], point_leftFoot[6]);

		// line 4
		Line line4(point_leftFoot[0], point_leftFoot[4]);
		leftPainter->drawLine(point_leftFoot[0], point_leftFoot[4] , Qt::green);

		// line 5
		Line line5(point_leftFoot[3], point_leftFoot[5]);
		leftPainter->drawLine(point_leftFoot[3], point_leftFoot[5]);

		// extension line
		leftPainter->drawExtenLine(point_leftFoot[5], point_leftFoot[6], 100, Qt::red, 1);

		// center point
		leftPainter->drawPoint((point_leftFoot[2] + point_leftFoot[6]) / 2, Qt::green, 8);
		leftPainter->drawLine((point_leftFoot[2] + point_leftFoot[6]) / 2, point_leftFoot[4]);
		float lenght_vertical_foot = Line::lengthSegment((point_leftFoot[2] + point_leftFoot[6]) / 2, point_leftFoot[4]);
		lenght_vertical_foot *= leftImageScale*leftScannerScale;

		// caculation angle
		float angle_line1_line2 = AngleFrom3Point(point_leftFoot[0], point_leftFoot[2], point_leftFoot[1]);
		float angle_line1_line3_lower = AngleFrom3Point(point_leftFoot[3], point_leftFoot[2], point_leftFoot[6]);
		float angle_line1_line3_upper = 180 - angle_line1_line3_lower;

		////lenght line 3
		float lenght_line3 = Line::lengthSegment(point_leftFoot[2], point_leftFoot[6]);
		lenght_line3 *= leftImageScale*leftScannerScale;

		//lenght line 4
		float lenght_line4 = Line::lengthSegment(point_leftFoot[0], point_leftFoot[4]);
		lenght_line4 *= leftImageScale*leftScannerScale;

		// lenght line 5
		float lenght_line5 = Line::lengthSegment(point_leftFoot[3], point_leftFoot[5]);
		lenght_line5 *= leftImageScale*leftScannerScale;

		// Last additiolnal line
		leftPainter->drawPoint((point_leftFoot[2] + point_leftFoot[3]) / 2, Qt::green, 8);
		leftPainter->drawLine((point_leftFoot[2] + point_leftFoot[3]) / 2, NornalPtFrom3Point(point_leftFoot[2], point_leftFoot[3], point_leftFoot[6]), Qt::green, 1);
		

		//leftPainter->drawLine((point_leftFoot[2] + point_leftFoot[6]) / 2, point_leftFoot[4]);
		//float lenght_vertical_foot = Line::lengthSegment((point_leftFoot[2] + point_leftFoot[6]) / 2, point_leftFoot[4]);
		//lenght_vertical_foot *= leftImageScale*leftScannerScale;

		// 
		leftMeasuring_2(point_leftFoot);
		
		// display
		ui.lbLeft_Angle_L1_L2->setText(QString::number(angle_line1_line2, 'f', 2));
		ui.lbLeft_Lenght_Line3->setText(QString::number(lenght_line3, 'f', 2));
		ui.lbLeft_Lenght_Line4->setText(QString::number(lenght_line4, 'f', 2));
		ui.lbLeft_Lenght_Line5->setText(QString::number(lenght_line5, 'f', 2));
		ui.lbLeft_Angle_Upper->setText(QString::number(angle_line1_line3_upper, 'f', 2));
		ui.lbLeft_Lenght_Vertical->setText(QString::number(lenght_vertical_foot, 'f', 2));
		
		// show and clear data
		leftPainter->points.clear();

		QImage qImage = leftPainter->theImage;
		Mat mImage = Mat(qImage.height(), qImage.width(), CV_8UC4, const_cast<uchar*>(qImage.bits()), qImage.bytesPerLine());
		saveImage("_Left_Analysis.jpg", mImage);

		ui.ivLeftAnalysisImage->SetImage(qImage);
		ui.log->Log("done!");

		// reset
		point_leftFoot.clear();
		ui.radioButton_left->setAutoExclusive(false);
		ui.radioButton_left->setChecked(false);
		ui.radioButton_left->setAutoExclusive(true);

	}
}
void MainWindow::processing_rightFoot(){
	std::cout << "right click " << std::endl;

	// selection done
	if (point_rightFoot.size() == 7){
		// line 1
		Line line1(point_rightFoot[2], point_rightFoot[3]);

		rightPainter->drawExtenLine(point_rightFoot[2], point_rightFoot[3], 100, Qt::red, 1);
		// line 2

		Line line2(point_rightFoot[1], point_rightFoot[2]);
		rightPainter->drawExtenLine(point_rightFoot[1], point_rightFoot[2], 100, Qt::red, 1);
		// line 3
		Line line3(point_rightFoot[2], point_rightFoot[6]);
		rightPainter->drawLine(point_rightFoot[2], point_rightFoot[6]);
		// line 4

		Line line4(point_rightFoot[0], point_rightFoot[4]);
		rightPainter->drawLine(point_rightFoot[0], point_rightFoot[4], Qt::blue);

		// line 5
		Line line5(point_rightFoot[3], point_rightFoot[5]);
		rightPainter->drawLine(point_rightFoot[3], point_rightFoot[5]);

		// extension line
		rightPainter->drawExtenLine(point_rightFoot[5], point_rightFoot[6], 100, Qt::red, 1);

		// center point
		rightPainter->drawPoint((point_rightFoot[2] + point_rightFoot[6]) / 2, Qt::blue, 8);
		rightPainter->drawLine((point_rightFoot[2] + point_rightFoot[6]) / 2, point_rightFoot[4]);
		float lenght_vertical_foot = Line::lengthSegment((point_rightFoot[2] + point_rightFoot[6]) / 2, point_rightFoot[4]);
		lenght_vertical_foot *= rightImageScale*rightScannerScale;

		// caculation angle
		float angle_line1_line2 = AngleFrom3Point(point_rightFoot[0], point_rightFoot[2], point_rightFoot[1]);

		float angle_line1_line3_lower = AngleFrom3Point(point_rightFoot[3], point_rightFoot[2], point_rightFoot[6]);
		float angle_line1_line3_upper = 180 - angle_line1_line3_lower;

		////lenght line 3
		float lenght_line3 = Line::lengthSegment(point_rightFoot[2], point_rightFoot[6]);
		lenght_line3 *= rightImageScale*rightScannerScale;

		//lenght line 4
		float lenght_line4 = Line::lengthSegment(point_rightFoot[0], point_rightFoot[4]);
		lenght_line4 *= rightImageScale*rightScannerScale;

		// lenght line 5
		float lenght_line5 = Line::lengthSegment(point_rightFoot[3], point_rightFoot[5]);
		lenght_line5 *= rightImageScale*rightScannerScale;

		// Last additiolnal line
		rightPainter->drawPoint((point_rightFoot[2] + point_rightFoot[3]) / 2, Qt::green, 8);
		rightPainter->drawLine((point_rightFoot[2] + point_rightFoot[3]) / 2, NornalPtFrom3Point(point_rightFoot[2], point_rightFoot[3], point_rightFoot[6]), Qt::green, 1);

		// 
		// 5 section
		rightMeasuring_2(point_rightFoot);
		// display

		ui.lbRight_Angle_L1_L2->setText(QString::number(angle_line1_line2, 'f', 2));
		ui.lbRight_Lenght_Line3->setText(QString::number(lenght_line3, 'f', 2));
		ui.lbRight_Lenght_Line4->setText(QString::number(lenght_line4, 'f', 2));
		ui.lbRight_Lenght_Line5->setText(QString::number(lenght_line5, 'f', 2));
		ui.lbRight_Angle_Upper->setText(QString::number(angle_line1_line3_upper, 'f', 2));
		ui.lbRight_Lenght_Vertical->setText(QString::number(lenght_vertical_foot, 'f', 2));

		// show and clear data	
		QImage qImage = rightPainter->theImage;
		Mat mImage = Mat(qImage.height(), qImage.width(), CV_8UC4, const_cast<uchar*>(qImage.bits()), qImage.bytesPerLine());
		saveImage("_Right_Analysis.jpg", mImage);

		ui.ivRightAnalysisImage->SetImage(qImage);
		ui.log->Log("done!");
		
		// reset
		point_rightFoot.clear();
		ui.radioButton_right->setAutoExclusive(false);
		ui.radioButton_right->setChecked(false);
		ui.radioButton_right->setAutoExclusive(true);
	}
}

float MainWindow::AngleFrom3Point(QPoint &First_ptr, QPoint &Fixed_ptr, QPoint &Last_ptr){

	QPoint middle_ptr = (First_ptr + Last_ptr) / 2;
	QLineF first_line(First_ptr, Fixed_ptr);
	QLineF middle_line(middle_ptr, Fixed_ptr);
	QLineF sencond_line(Last_ptr, Fixed_ptr);

	float angle_1 = first_line.angle(middle_line);
	float angle_2 = sencond_line.angle(middle_line);

	float real_angle = angle_1 + angle_2;

	return real_angle;
}

float MainWindow::AngleFrom3Point_2(QPoint &First_ptr, QPoint &Fixed_ptr, QPoint &Last_ptr){
	QLineF first_line(First_ptr, Fixed_ptr);
	QLineF sencond_line(Last_ptr, Fixed_ptr);

	float real_angle = first_line.angle(sencond_line);

	return real_angle;
}

QPoint MainWindow::NornalPtFrom3Point(QPoint &First_ptr, QPoint &Last_ptr, QPoint &criter_ptr){

	QPoint t_point1, t_point2, t_result;

	t_point1 = (First_ptr + Last_ptr) / 2;

	t_point2.setX(100);
	t_point2.setY((Last_ptr.x() - First_ptr.x())*100 / (First_ptr.y() - Last_ptr.y()));

	if (criter_ptr.x() < t_point1.x()){
	
		t_result.setX(criter_ptr.x() - 30);
		t_result.setY(-1 * t_point2.y()*t_point1.x()/100 + t_point2.y()*t_result.x()/100 + t_point1.y());
	}
	else{

		t_result.setX(criter_ptr.x() + 30);
		t_result.setY(-1 * t_point2.y()*t_point1.x() / 100 + t_point2.y()*t_result.x() / 100 + t_point1.y());
	}

	return t_result;
}

void MainWindow::leftMeasuring_2(vector<QPoint> &points){
	
	
	/*ui.lbLeftFootLength->setText(QString::number(leftFootLength,'f',2));*/

	Line line1(points[1], points[2]);
	Line line2(points[1], points[3]);
	/*ui.lbLeftFootAngle->setText(QString::number(leftFootAngle, 'f', 2));*/

	leftPainter->drawLine(points[2], points[6]);
	Line line3(points[2], points[6]);
	float b4 = points[5].y() - line3.a*points[5].x();
	Line line4(line3.a, b4);
	QPointF it = Line::intersect2Lines(line2, line4);
	QPoint inter(it.x(), it.y());
	leftPainter->drawPoint(inter, Qt::green);
	leftPainter->drawLine(points[5], inter, Qt::magenta);

	vector<QPoint> topPoints = Line::divideSegment(points[2], points[6], 5);
	vector<QPoint> bottomPoints = Line::divideSegment(inter, points[5], 5);
	for (int i = 0; i < 4; i++){
		leftPainter->drawPoint(topPoints[i], Qt::cyan);
		leftPainter->drawPoint(bottomPoints[i], Qt::cyan);
		leftPainter->drawLine(topPoints[i], bottomPoints[i], Qt::red);
	}
	
}


void MainWindow::rightMeasuring_2(vector<QPoint> &points){
	Line line1(points[1], points[2]);
	Line line2(points[1], points[3]);
	/*ui.lbLeftFootAngle->setText(QString::number(leftFootAngle, 'f', 2));*/

	rightPainter->drawLine(points[2], points[6]);
	Line line3(points[2], points[6]);
	float b4 = points[5].y() - line3.a*points[5].x();
	Line line4(line3.a, b4);
	QPointF it = Line::intersect2Lines(line2, line4);
	QPoint inter(it.x(), it.y());
	rightPainter->drawPoint(inter, Qt::green);
	rightPainter->drawLine(points[5], inter, Qt::magenta);

	vector<QPoint> topPoints = Line::divideSegment(points[2], points[6], 5);
	vector<QPoint> bottomPoints = Line::divideSegment(inter, points[5], 5);
	for (int i = 0; i < 4; i++){
		rightPainter->drawPoint(topPoints[i], Qt::cyan);
		rightPainter->drawPoint(bottomPoints[i], Qt::cyan);
		rightPainter->drawLine(topPoints[i], bottomPoints[i], Qt::red);
	}
}


void MainWindow::measureDistance_left(){

	std::cout << "measure left" << std::endl;

	if (distance_left_point.size() == 2){
		leftPainter->drawLine_temp(distance_left_point[0], distance_left_point[1], Qt::blue);
		float distance_lenght = Line::lengthSegment(distance_left_point[0], distance_left_point[1]);
		distance_lenght *= leftImageScale*leftScannerScale;
		ui.lbLeft_Distance->setText(QString::number(distance_lenght, 'f', 2));

		// clear
		distance_left_point.clear();
	}
}
void MainWindow::measureDistance_right(){
	std::cout << "measure right" << std::endl;
	if (distance_right_point.size() == 2){
		rightPainter->drawLine_temp(distance_right_point[0], distance_right_point[1], Qt::blue);
		float distance_lenght = Line::lengthSegment(distance_right_point[0], distance_right_point[1]);
		distance_lenght *= rightImageScale*rightScannerScale;
		ui.lbRight_Distance->setText(QString::number(distance_lenght, 'f', 2));

		// clear
		distance_right_point.clear();
	}
}

void MainWindow::on_leCustomerHeight_returnPressed(){

	float t_valuef1, t_valuef2, t_valuef3;
	int   t_valuei;

	QString t_stringbuf1 = ui.leCustomerWeight->text();
	QString t_stringbuf2 = ui.leCustomerHeight->text();

	t_valuef1 = t_stringbuf1.toFloat();
	t_valuef2 = (t_stringbuf2.toFloat()) / 100.f;

	if (t_valuef2 == 0.f){

		t_valuef3 = 0.f;
	}
	else{
		t_valuei = (int)(10.f*t_valuef1 / (t_valuef2*t_valuef2));

		t_valuef3 = ((float)t_valuei) / 10.f;
	}

	ui.leBodyMass->setText(QString::number(t_valuef3));

}

void MainWindow::on_leCustomerWeight_returnPressed(){

	float t_valuef1, t_valuef2, t_valuef3;
	int   t_valuei;

	QString t_stringbuf1 = ui.leCustomerWeight->text();
	QString t_stringbuf2 = ui.leCustomerHeight->text();

	t_valuef1 = t_stringbuf1.toFloat();
	t_valuef2 = (t_stringbuf2.toFloat()) / 100.f;

	if (t_valuef2 == 0.f){

		t_valuef3 = 0.f;
	}
	else{
		t_valuei = (int)(10.f*t_valuef1 / (t_valuef2*t_valuef2));

		t_valuef3 = ((float)t_valuei) / 10.f;
	}

	ui.leBodyMass->setText(QString::number(t_valuef3));

}