#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent),
	leftScannerIndex(0),
	rightScannerIndex(0),
	leftPainter(new Painter),
	rightPainter(new Painter)
	
{
	ui.setupUi(this);
	on_pbBodyMeasurement_clicked();
	webcameraTimer = new QTimer();
	connect(webcameraTimer, SIGNAL(timeout()), this, SLOT(on_webcamera()));
	webcameraTimer->setInterval(100);
	// initialize webcamera
	webcamera1.open(0);
	

	leftDraw = new(QTimer);
	connect(leftDraw, SIGNAL(timeout()), this, SLOT(on_leftDraw()));
	leftDraw->setInterval(200);
	rightDraw = new(QTimer);
	connect(rightDraw, SIGNAL(timeout()), this, SLOT(on_rightDraw()));
	rightDraw->setInterval(200);
	isLeftScannerConnect = isRightScannerConnect = false;
	loadScannerSetting();

	sysPath = "G:/Project2016/Test Foot System";
	dirModel = new QFileSystemModel(this);
	dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
	fileModel = new QFileSystemModel(this);
	fileModel->setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);

	bridgeTimer = new QTimer();
	connect(bridgeTimer, SIGNAL(timeout()), this, SLOT(on_bridge()));
	bridgeTimer->setInterval(50);
	bridgeCalibTimer = new QTimer();
	connect(bridgeCalibTimer, SIGNAL(timeout()), this, SLOT(on_bridgeCalib()));
	bridgeCalibTimer->setInterval(50);
	openBridge();
}

void MainWindow::on_actionNewCustomer_triggered(){

}

void MainWindow::on_actionExit_triggered(){
	close();
}

void MainWindow::on_actionAbout_triggered(){
	QMessageBox::about(this, "Foot Measurement", "This software was developed by .... in 2016, Ulsan, Korea");
}

void MainWindow::refreshGUI(){
	ui.pbBodyMeasurement->setStyleSheet("color:black; background:#E5E8E8");
	ui.pbFootAnalysis->setStyleSheet("color:black; background:#E5E8E8");
	ui.pbUpload->setStyleSheet("color:black; background:#E5E8E8");
	ui.pbTransferStatus->setStyleSheet("color:black; background:#E5E8E8");
	ui.pbSettings->setStyleSheet("color:black; background:#E5E8E8");
	ui.frameMain->hide();
	ui.frameFootAnalysis->hide();
	ui.frameUpload->hide();
	ui.frameSettings->hide();
}

void MainWindow::on_pbBodyMeasurement_clicked(){
	refreshGUI();
	ui.pbBodyMeasurement->setStyleSheet("color:red");
	ui.frameMain->show();
}

void MainWindow::on_pbFootAnalysis_clicked(){
	refreshGUI();
	ui.pbFootAnalysis->setStyleSheet("color:red");
	ui.frameFootAnalysis->show();
}

void MainWindow::on_pbUpload_clicked(){
	refreshGUI();
	ui.pbUpload->setStyleSheet("color:red");
	showSysFiles();
	ui.frameUpload->show();
	on_ckShowPassword_stateChanged();
}

void MainWindow::on_pbSettings_clicked(){
	refreshGUI();
	ui.pbSettings->setStyleSheet("color:red");
	ui.frameSettings->show();
}

void MainWindow::on_updateSettings(){

}


void MainWindow::initializeScanners(){
	if (leftScanner.twInitialize(0) != TWRC_SUCCESS){
		QMessageBox::critical(this, tr("Scanners Initialization"), tr("Unable load Scanner Drivers"));
		return;
	}
	if (leftScanner.twListDevices() == TWRC_FAILURE) {
		QMessageBox::critical(this, tr("Scanners Finding"), tr("No Image Acquisitiion Device on system"));
		return;
	}
	for (int i = 0; i < leftScanner.twList.size(); i++){
		ui.cbLeftScanner->addItem(QString::fromStdString(leftScanner.twList[i]));
	}

	if (rightScanner.twInitialize(1) != TWRC_SUCCESS){
		QMessageBox::critical(this, tr("Scanners Initialization"), tr("Unable load Scanner Drivers"));
		return;
	}
	if (rightScanner.twListDevices() == TWRC_FAILURE) {
		QMessageBox::critical(this, tr("Scanners Finding"), tr("No Image Acquisitiion Device on system"));
		return;
	}
	for (int i = 0; i < rightScanner.twList.size(); i++){
		ui.cbRightScanner->addItem(QString::fromStdString(rightScanner.twList[i]));
	}
}

void MainWindow::on_cbLeftScanner_activated(){
	if(isLeftScannerConnect) leftScanner.twCloseSource();
	leftScannerIndex = ui.cbLeftScanner->currentIndex();
	if (leftScannerIndex == 0 || leftScannerIndex == rightScannerIndex){
		ui.cbLeftScanner->setCurrentIndex(0);
		leftScannerIndex = 0;
		isLeftScannerConnect = false;
		return;
	}
	if (leftScanner.twSelectDevice(leftScannerIndex - 1) != TWRC_SUCCESS){
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
	if (rightScannerIndex == 0 || leftScannerIndex == rightScannerIndex){
		ui.cbRightScanner->setCurrentIndex(0);
		rightScannerIndex = 0;
		isRightScannerConnect = false;
		return;
	}
	if (rightScanner.twSelectDevice(rightScannerIndex - 1) != TWRC_SUCCESS){
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
	if (leftScannerIndex == 0) return;
	if (leftScanner.twScan("leftScan.jpg") == TWRC_FAILURE){
		QMessageBox::critical(this, tr("Left Scanner"), tr("Scanning error"));
		return;
	}
	leftScanImage = imread("leftScan.jpg");
	if (leftScanImage.empty()) return;
	fixScanError(leftScannerName,leftScanImage);
	Mat image;
	cvtColor(leftScanImage, image, CV_RGB2BGR);
	QImage qimg(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
	leftPainter->setImage(qimg);
	leftImageScale = 1.0/leftPainter->resizeFactor;
	ui.lbLeftImageScale->setText(QString::number(leftImageScale));

	on_pbRightScan_clicked();
}

void MainWindow::on_pbRightScan_clicked(){
	if (rightScannerIndex == 0) return;
	if (rightScanner.twScan("rightScan.jpg") == TWRC_FAILURE){
		QMessageBox::critical(this, tr("Right Scanner"), tr("Scanning error"));
		return;
	}
	rightScanImage = imread("rightScan.jpg");
	if (rightScanImage.empty()) return;
	fixScanError(rightScannerName, rightScanImage);
	Mat image;
	cvtColor(rightScanImage, image, CV_RGB2BGR);
	QImage qimg(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
	rightPainter->setImage(qimg);
	rightImageScale = 1.0/rightPainter->resizeFactor;
	ui.lbRightImageScale->setText(QString::number(rightImageScale));
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
	ui.ivFootPrintView->SetImage(footImage);
}

void MainWindow::on_pbFootPrintCapture_clicked(){
	if (footImage.empty())return;
	ui.ivFootView->SetImage(footImage);
	QString fileName = ui.leMeasureDate->text() + "_" + ui.leCenterName->text() + "_" + ui.leCustomerName->text() + "_Footprint.jpg";
	fileName.remove(" ");
	fileName = sysPath + "/" + fileName;
	string fn = sysPath.toStdString();	fn.append("/Footprint.jpg");
	imwrite(fn, footImage);
	QString fname = QString::fromUtf8(fn.c_str());
	QFile::rename(fname, fileName);
}

void MainWindow::on_pbSelectUpperCamera_clicked(){
	if (webcamera1.isOpened()){
		webcamera1.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
		webcamera1.set(CV_CAP_PROP_FRAME_HEIGHT, 720);
		webcameraTimer->start();
	}
	else
		QMessageBox::critical(this, tr("Webcamera Initialization"), tr("Cannot Connect to Webcamera"));
}

void MainWindow::on_pbSelectBodyCamera_clicked(){

}

void MainWindow::on_webcamera(){
	if (webcamera1.isOpened()){
		webcamera1 >> upperView;
		ui.ivBodyCameraViews->SetImage(upperView);
	}
}

void MainWindow::on_pbUpperCapture_clicked(){
	webcameraTimer->stop();
	if (upperView.empty()) return;
	ui.ivBodyTopView->SetImage(upperView);
	QString fileName = ui.leMeasureDate->text() + "_" + ui.leCenterName->text() +"_"+ ui.leCustomerName->text() + "_UpperView.jpg";
	fileName.remove(" ");
	fileName = sysPath + "/" + fileName;
	string fn = sysPath.toStdString();	fn.append("/UpperView.jpg");
	imwrite(fn, upperView);
	QString fname = QString::fromUtf8(fn.c_str());
	QFile::rename(fname, fileName);
}

void MainWindow::fixScanError(QString scannerName, Mat &scanImage){
	if (scannerName.contains("WIA")){
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
}

void MainWindow::on_tbLeftFootMeasure_clicked(){
	leftPainter->setDraw = true;
	leftDraw->start();
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
		leftPainter->setDraw = false;
		leftDraw->stop();
		leftMeasuring(leftPainter->points);
		leftPainter->points.clear();
	}
}

void MainWindow::leftMeasuring(vector<QPoint> &points){
	leftFootLength = Line::lengthSegment(points[0], points[1]);
	leftFootLength *= leftImageScale*leftScannerScale;
	ui.lbLeftFootLength->setText(QString::number(leftFootLength,'f',2));

	Line line1(points[2], points[3]);
	Line line2(points[2], points[4]);
	leftFootAngle = Line::Angle2Lines(line2, line1);
	ui.lbLeftFootAngle->setText(QString::number(leftFootAngle, 'f', 2));

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
	rightPainter->setDraw = true;
	rightDraw->start();
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
		rightPainter->setDraw = false;
		rightDraw->stop();
		rightMeasuring(rightPainter->points);
		rightPainter->points.clear();
	}
}

void MainWindow::rightMeasuring(vector<QPoint> &points){
	rightFootLength = Line::lengthSegment(points[0], points[1]);
	rightFootLength *= rightImageScale*rightScannerScale;
	ui.lbRightFootLength->setText(QString::number(rightFootLength, 'f', 2));

	Line line1(points[2], points[3]);
	Line line2(points[2], points[4]);
	rightFootAngle = Line::Angle2Lines(line2, line1);
	ui.lbRightFootAngle->setText(QString::number(rightFootAngle, 'f', 2));

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
}

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
				sharedDriveList << QString::fromUtf16(temp.c_str());
			}
			p++;
		}
	}
}

void MainWindow::on_pbReloadScannerDrivers_clicked(){
	leftScanner.twRelease();
	rightScanner.twRelease();
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

	QString mPath = "\\\\" + ui.leIPAddress->text();
	dirModel->setRootPath(mPath);
	ui.treeView->setModel(dirModel);
	showServerEntries();
}

void MainWindow::showServerEntries(){
	QString mPath = "\\\\" + ui.leIPAddress->text();
	fileModel->setRootPath(mPath);
	ui.listView->setModel(fileModel);
}

void MainWindow::showSysFiles(){
	QDir sysDir(sysPath);
	listSysFiles = sysDir.entryList(QDir::NoDotAndDotDot | QDir::Files);
	QStringListModel *sysFilesModel = new QStringListModel(this);
	sysFilesModel->setStringList(listSysFiles);
	ui.listView2->setModel(sysFilesModel);
}

void MainWindow::on_treeView_clicked(const QModelIndex &index){
	treeIndex = index;
	serverPath = dirModel->fileInfo(index).absoluteFilePath();
	ui.listView->setRootIndex(fileModel->setRootPath(serverPath));
}

void MainWindow::on_pbUploadFiles_clicked(){
	QModelIndexList indexes = ui.listView2->selectionModel()->selectedIndexes();
	if (indexes.isEmpty()){
		QMessageBox::critical(this, "Uppload Files", "No file is selected!!!");
		return;
	}
	for (int i = 0; i < indexes.size(); i++){
		QString fileName = "/" + listSysFiles.at(indexes[i].row());
		QString sourceFullName = sysPath + fileName;
		QString destFullName = serverPath + fileName;
	//	if (!CopyFile(sourceFullName.utf16(), destFullName.utf16(), true)){
		if (!QFile::copy(sourceFullName, destFullName)){
			QMessageBox::critical(this, "Upload Files.. ", "Cannot upload file: " + fileName);
		}
	}
	defineTreeView();
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
		QMessageBox::critical(this, "Open Bridge Load Cells", "No Bridge is detected!");
		ui.groupBox_LoadCell->setTitle("No Bridge");
		return;
	}
	bridgeName = QString::fromUtf8(deviceName);
	ui.groupBox_LoadCell->setTitle(bridgeName);
	loadBridgeSetting();
}

void MainWindow::openBridge(){
	QStringList bridges, gains;
	bridges << "Bridge 0" << "Bridge 1" << "Bridge 2" << "Bridge 3";
	ui.cbBridges->addItems(bridges);
	gains << "1" << "8" << "16" << "32" << "64" << "128";
	ui.cbBridgeGains->addItems(gains);
	bridgeRate = 200;
	selectedBridgeIndex = selectedGainIndex = 0;

	ui.leValue_1->setEnabled(false);
	ui.leValue_2->setEnabled(false);
	ui.leValue_3->setEnabled(false);
	ui.leValue_4->setEnabled(false);
	ui.pbSet_1->setEnabled(false);
	ui.pbSet_2->setEnabled(false);
	ui.pbSet_3->setEnabled(false);
	ui.pbSet_4->setEnabled(false);

	CPhidgetBridge_create(&bridge);
	CPhidget_open((CPhidgetHandle)bridge, -1);
	_sleep(100);
	const char *deviceName;
	if (CPhidget_getDeviceName((CPhidgetHandle)bridge, &deviceName) != 0) {
		QMessageBox::critical(this, "Open Bridge Load Cells", "No Bridge is detected!");
		ui.groupBox_LoadCell->setTitle("No Bridge");
		return;
	}
	bridgeName = QString::fromUtf8(deviceName);
	ui.groupBox_LoadCell->setTitle(bridgeName);
	loadBridgeSetting();

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
	double value, real[4];
	for (int i = 0; i < 4; i++){
		CPhidgetBridge_getBridgeValue(bridge, i, &value);
		real[i] = calibBridgeParameters[i][2] * value*value +
			calibBridgeParameters[i][1] * value +
			calibBridgeParameters[i][0];
	}
	ui.lbFrontLeftFootWeight->setText(QString::number(real[0],'f',2));
	ui.lbBackLeftFootWeight->setText(QString::number(real[1],'f',2));
	ui.lbFrontRightFootWeight->setText(QString::number(real[2],'f',2));
	ui.lbBackRightFootWeight->setText(QString::number(real[3],'f',2));
}

void MainWindow::on_bridgeCalib(){
	if (!bridgeIsSet) setBridge();
	double value;
	CPhidgetBridge_getBridgeValue(bridge, selectedBridgeIndex, &value);
	ui.leBridgeValue->setText(QString::number(value));
	double real = calibBridgeParameters[selectedBridgeIndex][2] * value*value +
		calibBridgeParameters[selectedBridgeIndex][1] * value +
		calibBridgeParameters[selectedBridgeIndex][0];
	ui.leConvertedValue->setText(QString::number(real));
}

void MainWindow::on_cbBridges_activated(){
	selectedBridgeIndex = ui.cbBridges->currentIndex();
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
	ui.leValue_1->setEnabled(true);
	ui.pbSet_1->setEnabled(true);
	ui.pbBridgeCalib->setEnabled(false);
}

void MainWindow::on_pbSet_1_clicked(){
	bridgeValue = ui.leBridgeValue->text().toDouble();
	realValue = ui.leValue_1->text().toDouble();
	calibValues[0][0] = bridgeValue;
	calibValues[0][1] = realValue;
	ui.leValue_1->setEnabled(false);
	ui.pbSet_1->setEnabled(false);
	ui.leValue_2->setEnabled(true);
	ui.pbSet_2->setEnabled(true);
}

void MainWindow::on_pbSet_2_clicked(){
	bridgeValue = ui.leBridgeValue->text().toDouble();
	realValue = ui.leValue_2->text().toDouble();
	calibValues[1][0] = bridgeValue;
	calibValues[1][1] = realValue;
	ui.leValue_2->setEnabled(false);
	ui.pbSet_2->setEnabled(false);
	ui.leValue_3->setEnabled(true);
	ui.pbSet_3->setEnabled(true);
}

void MainWindow::on_pbSet_3_clicked(){
	bridgeValue = ui.leBridgeValue->text().toDouble();
	realValue = ui.leValue_3->text().toDouble();
	calibValues[2][0] = bridgeValue;
	calibValues[2][1] = realValue;
	ui.leValue_3->setEnabled(false);
	ui.pbSet_3->setEnabled(false);
	ui.leValue_4->setEnabled(true);
	ui.pbSet_4->setEnabled(true);
}

void MainWindow::on_pbSet_4_clicked(){
	bridgeValue = ui.leBridgeValue->text().toDouble();
	realValue = ui.leValue_4->text().toDouble();
	calibValues[3][0] = bridgeValue;
	calibValues[3][1] = realValue;
	ui.leValue_4->setEnabled(false);
	ui.pbSet_4->setEnabled(false);
	ui.pbBridgeCalib->setEnabled(true);
	bridgeCalibration();
}

void MainWindow::bridgeCalibration(){
	Mat bridge(4, 1, CV_32F);
	Mat real(4, 1, CV_32F);
	for (int i = 0; i < 4; i++){
		bridge.at<float>(i, 0) = calibValues[i][0];
		real.at<float>(i, 0) = calibValues[i][1];
	}
	Mat result(3, 1, CV_32F);
	polyfit(bridge, real, result, 2);
	for (int i = 0; i < 3; i++){
		float temp = result.at<float>(i, 0);
		calibBridgeParameters[selectedBridgeIndex][i] = temp;
	}
	bridgeIsSet = false;
}

void MainWindow::on_pbSaveBridgeSetting_clicked(){
	FILE *f = fopen("calibBridge.dat", "wb");
	if (!f){
		QMessageBox::critical(this, tr("Load Cell Calibration"), QString("Can not save calibration data !"));
		return;
	}
	for (int i = 0; i < 4; i++){
		fwrite(&calibBridgeParameters[i][0], sizeof(float), 1, f);
		fwrite(&calibBridgeParameters[i][1], sizeof(float), 1, f);
		fwrite(&calibBridgeParameters[i][2], sizeof(float), 1, f);
	}
	fclose(f);
}

void MainWindow::loadBridgeSetting(){
	FILE *f = fopen("calibBridge.dat", "rb");
	if (!f){
		QMessageBox::critical(this, tr("Load Cell Calibration"), QString("Cannot load calibration data !"));
		return;
	}
	for (int i = 0; i < 4; i++){
		fread(&calibBridgeParameters[i][0], sizeof(float), 1, f);
		fread(&calibBridgeParameters[i][1], sizeof(float), 1, f);
		fread(&calibBridgeParameters[i][2], sizeof(float), 1, f);
		CPhidgetBridge_setEnabled(bridge, i, true);
		CPhidgetBridge_setDataRate(bridge, bridgeRate);
	}
	fclose(f);
}

void MainWindow::closeEvent(QCloseEvent *event){
	leftScanner.twRelease();
	rightScanner.twRelease();
	event->accept();
}