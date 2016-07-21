/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "imgview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionExit;
    QAction *actionNewCustomer;
    QAction *actionSettings;
    QAction *actionAbout;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *leMeasureDate;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *leCenterName;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *leCustomerName;
    QLineEdit *leCustomerHeight;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *leBirthDate;
    QLineEdit *leCustomerWeight;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *leCustomerSex;
    QLineEdit *leBodyMass;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QFrame *frameWindows;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbBodyMeasurement;
    QPushButton *pbFootAnalysis;
    QPushButton *pbUpload;
    QPushButton *pbTransferStatus;
    QPushButton *pbSettings;
    QSpacerItem *horizontalSpacer_7;
    QFrame *frameMain;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_8;
    ImgView *ivFootView;
    ImgView *ivBodyTopView;
    ImgView *ivBodyFrontView;
    ImgView *ivBodySideView;
    ImgView *ivBodyBackView;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_11;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pbSelectBodyCamera;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pbSelectUpperCamera;
    QSpacerItem *horizontalSpacer_10;
    ImgView *ivBodyCameraViews;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_9;
    QPushButton *pbUpperCapture;
    QPushButton *pbSideCapture;
    QSpacerItem *horizontalSpacer_11;
    QVBoxLayout *verticalLayout_10;
    QPushButton *pbFrontCapture;
    QPushButton *pbBackCapture;
    QSpacerItem *horizontalSpacer_13;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_12;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *pbSelectFootScanner;
    QSpacerItem *horizontalSpacer_16;
    ImgView *ivFootPrintView;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *pbFootPrintCapture;
    QSpacerItem *horizontalSpacer_18;
    QFrame *frameFootAnalysis;
    QHBoxLayout *horizontalLayout_8;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *pbLeftScan;
    QToolButton *tbLeftFootMeasure;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *pbRightScan;
    QToolButton *tbRightFootMeasure;
    QSpacerItem *horizontalSpacer_20;
    QHBoxLayout *horizontalLayout_10;
    QScrollArea *scrollAreaLeftFoot;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *scrollAreaRightFoot;
    QWidget *scrollAreaWidgetContents_2;
    QFrame *frame_12;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *lbLeftFootLength;
    QLabel *label_14;
    QLabel *label_4;
    QLabel *lbLeftFootAngle;
    QLabel *label_13;
    QLabel *lbRightFootLength;
    QLabel *label_12;
    QLabel *lbRightFootAngle;
    QLabel *label_17;
    QLabel *label_16;
    QLabel *label_15;
    QPushButton *pbMeasureWeight;
    QWidget *layoutWidget1;
    QFormLayout *formLayout_3;
    QLabel *label_28;
    QLabel *lbFrontLeftFootWeight;
    QLabel *label_29;
    QLabel *lbBackLeftFootWeight;
    QLabel *label_30;
    QLabel *lbFrontRightFootWeight;
    QLabel *label_31;
    QLabel *lbBackRightFootWeight;
    QFrame *frameUpload;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_16;
    QFormLayout *formLayout_2;
    QTreeView *treeView;
    QListView *listView;
    QListView *listView2;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_15;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLineEdit *leIPAddress;
    QLabel *label_6;
    QLineEdit *leUserName;
    QLabel *label_7;
    QLineEdit *lePassword;
    QCheckBox *ckShowPassword;
    QPushButton *pbConnectServer;
    QPushButton *pbMakeFolder;
    QPushButton *pbUploadFiles;
    QPushButton *pbSetSystemFolder;
    QSpacerItem *verticalSpacer_6;
    QFrame *frameSettings;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_11;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *cbLeftScanner;
    QComboBox *cbRightScanner;
    QLabel *lbLeftImageScale;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *lbRightImageScale;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *leLeftScannerScale;
    QLineEdit *leRightScannerScale;
    QPushButton *pbSaveScannerSetting;
    QPushButton *pbReloadScannerDrivers;
    QGroupBox *groupBox_LoadCell;
    QCheckBox *ckEnabled;
    QLabel *label_18;
    QLineEdit *leFormula;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QPushButton *pbBridgeCalib;
    QLineEdit *leRate;
    QPushButton *pbSet_1;
    QPushButton *pbSet_4;
    QLineEdit *leBridgeValue;
    QLabel *label_22;
    QLineEdit *leValue_4;
    QLabel *label_23;
    QLineEdit *leConvertedValue;
    QLineEdit *leValue_3;
    QLineEdit *leValue_2;
    QPushButton *pbSet_3;
    QComboBox *cbBridgeGains;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QPushButton *pbSet_2;
    QLabel *label_27;
    QLineEdit *leValue_1;
    QSlider *slRate;
    QComboBox *cbBridges;
    QPushButton *pbSaveBridgeSetting;
    QPushButton *pbReloadBridge;
    QSpacerItem *horizontalSpacer_22;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAbout;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1025, 2150);
        actionExit = new QAction(MainWindowClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionNewCustomer = new QAction(MainWindowClass);
        actionNewCustomer->setObjectName(QStringLiteral("actionNewCustomer"));
        actionSettings = new QAction(MainWindowClass);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionAbout = new QAction(MainWindowClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_7 = new QVBoxLayout(centralWidget);
        verticalLayout_7->setSpacing(1);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(1, 1, 1, 1);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMaximumSize(QSize(16777215, 80));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        leMeasureDate = new QLineEdit(frame);
        leMeasureDate->setObjectName(QStringLiteral("leMeasureDate"));
        leMeasureDate->setMinimumSize(QSize(120, 25));
        QFont font;
        font.setFamily(QStringLiteral("Malgun Gothic"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        leMeasureDate->setFont(font);
        leMeasureDate->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(leMeasureDate);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        leCenterName = new QLineEdit(frame);
        leCenterName->setObjectName(QStringLiteral("leCenterName"));
        leCenterName->setMinimumSize(QSize(120, 25));
        leCenterName->setFont(font);
        leCenterName->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(leCenterName);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        leCustomerName = new QLineEdit(frame);
        leCustomerName->setObjectName(QStringLiteral("leCustomerName"));
        leCustomerName->setMinimumSize(QSize(120, 25));
        leCustomerName->setFont(font);
        leCustomerName->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(leCustomerName);

        leCustomerHeight = new QLineEdit(frame);
        leCustomerHeight->setObjectName(QStringLiteral("leCustomerHeight"));
        leCustomerHeight->setMinimumSize(QSize(120, 25));
        leCustomerHeight->setFont(font);
        leCustomerHeight->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(leCustomerHeight);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        leBirthDate = new QLineEdit(frame);
        leBirthDate->setObjectName(QStringLiteral("leBirthDate"));
        leBirthDate->setMinimumSize(QSize(120, 25));
        leBirthDate->setFont(font);
        leBirthDate->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(leBirthDate);

        leCustomerWeight = new QLineEdit(frame);
        leCustomerWeight->setObjectName(QStringLiteral("leCustomerWeight"));
        leCustomerWeight->setMinimumSize(QSize(120, 25));
        leCustomerWeight->setFont(font);
        leCustomerWeight->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(leCustomerWeight);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);


        horizontalLayout->addLayout(verticalLayout_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        leCustomerSex = new QLineEdit(frame);
        leCustomerSex->setObjectName(QStringLiteral("leCustomerSex"));
        leCustomerSex->setMinimumSize(QSize(120, 25));
        leCustomerSex->setFont(font);
        leCustomerSex->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(leCustomerSex);

        leBodyMass = new QLineEdit(frame);
        leBodyMass->setObjectName(QStringLiteral("leBodyMass"));
        leBodyMass->setMinimumSize(QSize(120, 25));
        leBodyMass->setFont(font);
        leBodyMass->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(leBodyMass);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);


        horizontalLayout->addLayout(verticalLayout_5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout_7->addWidget(frame);

        frameWindows = new QFrame(centralWidget);
        frameWindows->setObjectName(QStringLiteral("frameWindows"));
        frameWindows->setFrameShape(QFrame::StyledPanel);
        frameWindows->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frameWindows);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 10);
        frame_7 = new QFrame(frameWindows);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setMinimumSize(QSize(0, 30));
        frame_7->setMaximumSize(QSize(16777215, 30));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_7);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pbBodyMeasurement = new QPushButton(frame_7);
        pbBodyMeasurement->setObjectName(QStringLiteral("pbBodyMeasurement"));
        pbBodyMeasurement->setMinimumSize(QSize(130, 30));
        pbBodyMeasurement->setFont(font);
        pbBodyMeasurement->setAutoFillBackground(false);
        pbBodyMeasurement->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(pbBodyMeasurement);

        pbFootAnalysis = new QPushButton(frame_7);
        pbFootAnalysis->setObjectName(QStringLiteral("pbFootAnalysis"));
        pbFootAnalysis->setMinimumSize(QSize(130, 30));
        pbFootAnalysis->setFont(font);

        horizontalLayout_2->addWidget(pbFootAnalysis);

        pbUpload = new QPushButton(frame_7);
        pbUpload->setObjectName(QStringLiteral("pbUpload"));
        pbUpload->setMinimumSize(QSize(130, 30));
        pbUpload->setFont(font);

        horizontalLayout_2->addWidget(pbUpload);

        pbTransferStatus = new QPushButton(frame_7);
        pbTransferStatus->setObjectName(QStringLiteral("pbTransferStatus"));
        pbTransferStatus->setMinimumSize(QSize(130, 30));
        pbTransferStatus->setFont(font);

        horizontalLayout_2->addWidget(pbTransferStatus);

        pbSettings = new QPushButton(frame_7);
        pbSettings->setObjectName(QStringLiteral("pbSettings"));
        pbSettings->setMinimumSize(QSize(130, 30));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        pbSettings->setFont(font1);

        horizontalLayout_2->addWidget(pbSettings);

        horizontalSpacer_7 = new QSpacerItem(445, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);


        verticalLayout_6->addWidget(frame_7);

        frameMain = new QFrame(frameWindows);
        frameMain->setObjectName(QStringLiteral("frameMain"));
        frameMain->setMinimumSize(QSize(0, 500));
        frameMain->setFrameShape(QFrame::NoFrame);
        frameMain->setFrameShadow(QFrame::Plain);
        frameMain->setLineWidth(1);
        horizontalLayout_3 = new QHBoxLayout(frameMain);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_4 = new QFrame(frameMain);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setMinimumSize(QSize(200, 0));
        frame_4->setStyleSheet(QStringLiteral(""));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Plain);
        frame_4->setLineWidth(1);
        verticalLayout_8 = new QVBoxLayout(frame_4);
        verticalLayout_8->setSpacing(1);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        ivFootView = new ImgView(frame_4);
        ivFootView->setObjectName(QStringLiteral("ivFootView"));
        QFont font2;
        font2.setFamily(QStringLiteral("Malgun Gothic"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        ivFootView->setFont(font2);
        ivFootView->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(ivFootView);

        ivBodyTopView = new ImgView(frame_4);
        ivBodyTopView->setObjectName(QStringLiteral("ivBodyTopView"));
        ivBodyTopView->setFont(font2);
        ivBodyTopView->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(ivBodyTopView);

        ivBodyFrontView = new ImgView(frame_4);
        ivBodyFrontView->setObjectName(QStringLiteral("ivBodyFrontView"));
        ivBodyFrontView->setFont(font2);
        ivBodyFrontView->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(ivBodyFrontView);

        ivBodySideView = new ImgView(frame_4);
        ivBodySideView->setObjectName(QStringLiteral("ivBodySideView"));
        ivBodySideView->setFont(font2);
        ivBodySideView->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(ivBodySideView);

        ivBodyBackView = new ImgView(frame_4);
        ivBodyBackView->setObjectName(QStringLiteral("ivBodyBackView"));
        ivBodyBackView->setFont(font2);
        ivBodyBackView->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(ivBodyBackView);


        horizontalLayout_3->addWidget(frame_4);

        frame_5 = new QFrame(frameMain);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setMinimumSize(QSize(400, 0));
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Plain);
        frame_5->setLineWidth(1);
        verticalLayout_11 = new QVBoxLayout(frame_5);
        verticalLayout_11->setSpacing(1);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        frame_8 = new QFrame(frame_5);
        frame_8->setObjectName(QStringLiteral("frame_8"));
        frame_8->setMinimumSize(QSize(0, 70));
        frame_8->setMaximumSize(QSize(16777215, 70));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_8);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        pbSelectBodyCamera = new QPushButton(frame_8);
        pbSelectBodyCamera->setObjectName(QStringLiteral("pbSelectBodyCamera"));
        pbSelectBodyCamera->setMinimumSize(QSize(130, 30));
        pbSelectBodyCamera->setFont(font);

        horizontalLayout_4->addWidget(pbSelectBodyCamera);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        pbSelectUpperCamera = new QPushButton(frame_8);
        pbSelectUpperCamera->setObjectName(QStringLiteral("pbSelectUpperCamera"));
        pbSelectUpperCamera->setMinimumSize(QSize(130, 30));
        pbSelectUpperCamera->setFont(font);

        horizontalLayout_4->addWidget(pbSelectUpperCamera);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        verticalLayout_11->addWidget(frame_8);

        ivBodyCameraViews = new ImgView(frame_5);
        ivBodyCameraViews->setObjectName(QStringLiteral("ivBodyCameraViews"));
        ivBodyCameraViews->setMinimumSize(QSize(0, 300));
        QFont font3;
        font3.setPointSize(10);
        ivBodyCameraViews->setFont(font3);
        ivBodyCameraViews->setFrameShape(QFrame::NoFrame);
        ivBodyCameraViews->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(ivBodyCameraViews);

        frame_9 = new QFrame(frame_5);
        frame_9->setObjectName(QStringLiteral("frame_9"));
        frame_9->setMinimumSize(QSize(0, 100));
        frame_9->setMaximumSize(QSize(16777215, 100));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_9);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_12);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        pbUpperCapture = new QPushButton(frame_9);
        pbUpperCapture->setObjectName(QStringLiteral("pbUpperCapture"));
        pbUpperCapture->setMinimumSize(QSize(130, 30));
        pbUpperCapture->setFont(font);

        verticalLayout_9->addWidget(pbUpperCapture);

        pbSideCapture = new QPushButton(frame_9);
        pbSideCapture->setObjectName(QStringLiteral("pbSideCapture"));
        pbSideCapture->setMinimumSize(QSize(130, 30));
        pbSideCapture->setFont(font);

        verticalLayout_9->addWidget(pbSideCapture);


        horizontalLayout_5->addLayout(verticalLayout_9);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        pbFrontCapture = new QPushButton(frame_9);
        pbFrontCapture->setObjectName(QStringLiteral("pbFrontCapture"));
        pbFrontCapture->setMinimumSize(QSize(130, 30));
        pbFrontCapture->setFont(font);

        verticalLayout_10->addWidget(pbFrontCapture);

        pbBackCapture = new QPushButton(frame_9);
        pbBackCapture->setObjectName(QStringLiteral("pbBackCapture"));
        pbBackCapture->setMinimumSize(QSize(130, 30));
        pbBackCapture->setFont(font);

        verticalLayout_10->addWidget(pbBackCapture);


        horizontalLayout_5->addLayout(verticalLayout_10);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_13);


        verticalLayout_11->addWidget(frame_9);


        horizontalLayout_3->addWidget(frame_5);

        frame_6 = new QFrame(frameMain);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setMinimumSize(QSize(400, 0));
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Plain);
        frame_6->setLineWidth(1);
        verticalLayout_12 = new QVBoxLayout(frame_6);
        verticalLayout_12->setSpacing(1);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        frame_10 = new QFrame(frame_6);
        frame_10->setObjectName(QStringLiteral("frame_10"));
        frame_10->setMinimumSize(QSize(0, 70));
        frame_10->setMaximumSize(QSize(16777215, 70));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_10);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_15);

        pbSelectFootScanner = new QPushButton(frame_10);
        pbSelectFootScanner->setObjectName(QStringLiteral("pbSelectFootScanner"));
        pbSelectFootScanner->setMinimumSize(QSize(130, 30));
        pbSelectFootScanner->setFont(font);

        horizontalLayout_6->addWidget(pbSelectFootScanner);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_16);


        verticalLayout_12->addWidget(frame_10);

        ivFootPrintView = new ImgView(frame_6);
        ivFootPrintView->setObjectName(QStringLiteral("ivFootPrintView"));
        ivFootPrintView->setMinimumSize(QSize(0, 300));
        ivFootPrintView->setFont(font3);
        ivFootPrintView->setFrameShape(QFrame::NoFrame);
        ivFootPrintView->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(ivFootPrintView);

        frame_11 = new QFrame(frame_6);
        frame_11->setObjectName(QStringLiteral("frame_11"));
        frame_11->setMinimumSize(QSize(0, 70));
        frame_11->setMaximumSize(QSize(16777215, 70));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_11);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_17);

        pbFootPrintCapture = new QPushButton(frame_11);
        pbFootPrintCapture->setObjectName(QStringLiteral("pbFootPrintCapture"));
        pbFootPrintCapture->setMinimumSize(QSize(130, 30));
        pbFootPrintCapture->setFont(font);

        horizontalLayout_7->addWidget(pbFootPrintCapture);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_18);


        verticalLayout_12->addWidget(frame_11);


        horizontalLayout_3->addWidget(frame_6);


        verticalLayout_6->addWidget(frameMain);

        frameFootAnalysis = new QFrame(frameWindows);
        frameFootAnalysis->setObjectName(QStringLiteral("frameFootAnalysis"));
        frameFootAnalysis->setMinimumSize(QSize(0, 500));
        frameFootAnalysis->setFrameShape(QFrame::Box);
        frameFootAnalysis->setFrameShadow(QFrame::Plain);
        horizontalLayout_8 = new QHBoxLayout(frameFootAnalysis);
        horizontalLayout_8->setSpacing(1);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(frameFootAnalysis);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_13 = new QVBoxLayout(frame_3);
        verticalLayout_13->setSpacing(1);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_19);

        pbLeftScan = new QPushButton(frame_3);
        pbLeftScan->setObjectName(QStringLiteral("pbLeftScan"));
        pbLeftScan->setMinimumSize(QSize(200, 30));

        horizontalLayout_9->addWidget(pbLeftScan);

        tbLeftFootMeasure = new QToolButton(frame_3);
        tbLeftFootMeasure->setObjectName(QStringLiteral("tbLeftFootMeasure"));
        tbLeftFootMeasure->setStyleSheet(QStringLiteral("border: none"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/MainWindow/measure.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        tbLeftFootMeasure->setIcon(icon);
        tbLeftFootMeasure->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(tbLeftFootMeasure);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_14);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_21);

        pbRightScan = new QPushButton(frame_3);
        pbRightScan->setObjectName(QStringLiteral("pbRightScan"));
        pbRightScan->setMinimumSize(QSize(200, 30));

        horizontalLayout_9->addWidget(pbRightScan);

        tbRightFootMeasure = new QToolButton(frame_3);
        tbRightFootMeasure->setObjectName(QStringLiteral("tbRightFootMeasure"));
        tbRightFootMeasure->setStyleSheet(QStringLiteral("border: none"));
        tbRightFootMeasure->setIcon(icon);
        tbRightFootMeasure->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(tbRightFootMeasure);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_20);


        verticalLayout_13->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        scrollAreaLeftFoot = new QScrollArea(frame_3);
        scrollAreaLeftFoot->setObjectName(QStringLiteral("scrollAreaLeftFoot"));
        scrollAreaLeftFoot->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 377, 458));
        scrollAreaLeftFoot->setWidget(scrollAreaWidgetContents);

        horizontalLayout_10->addWidget(scrollAreaLeftFoot);

        scrollAreaRightFoot = new QScrollArea(frame_3);
        scrollAreaRightFoot->setObjectName(QStringLiteral("scrollAreaRightFoot"));
        scrollAreaRightFoot->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 377, 458));
        scrollAreaRightFoot->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_10->addWidget(scrollAreaRightFoot);


        verticalLayout_13->addLayout(horizontalLayout_10);


        horizontalLayout_8->addWidget(frame_3);

        frame_12 = new QFrame(frameFootAnalysis);
        frame_12->setObjectName(QStringLiteral("frame_12"));
        frame_12->setMinimumSize(QSize(250, 0));
        frame_12->setMaximumSize(QSize(250, 16777215));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame_12);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 231, 112));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font3);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lbLeftFootLength = new QLabel(layoutWidget);
        lbLeftFootLength->setObjectName(QStringLiteral("lbLeftFootLength"));
        QFont font4;
        font4.setPointSize(13);
        lbLeftFootLength->setFont(font4);

        gridLayout->addWidget(lbLeftFootLength, 0, 1, 1, 1);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        QFont font5;
        font5.setPointSize(12);
        label_14->setFont(font5);

        gridLayout->addWidget(label_14, 0, 2, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font3);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        lbLeftFootAngle = new QLabel(layoutWidget);
        lbLeftFootAngle->setObjectName(QStringLiteral("lbLeftFootAngle"));
        lbLeftFootAngle->setFont(font4);

        gridLayout->addWidget(lbLeftFootAngle, 1, 1, 1, 1);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font3);

        gridLayout->addWidget(label_13, 2, 0, 1, 1);

        lbRightFootLength = new QLabel(layoutWidget);
        lbRightFootLength->setObjectName(QStringLiteral("lbRightFootLength"));
        lbRightFootLength->setFont(font4);

        gridLayout->addWidget(lbRightFootLength, 2, 1, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font3);

        gridLayout->addWidget(label_12, 3, 0, 1, 1);

        lbRightFootAngle = new QLabel(layoutWidget);
        lbRightFootAngle->setObjectName(QStringLiteral("lbRightFootAngle"));
        lbRightFootAngle->setFont(font4);

        gridLayout->addWidget(lbRightFootAngle, 3, 1, 1, 1);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font5);

        gridLayout->addWidget(label_17, 3, 2, 1, 1);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font5);

        gridLayout->addWidget(label_16, 1, 2, 1, 1);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font5);

        gridLayout->addWidget(label_15, 2, 2, 1, 1);

        pbMeasureWeight = new QPushButton(frame_12);
        pbMeasureWeight->setObjectName(QStringLiteral("pbMeasureWeight"));
        pbMeasureWeight->setGeometry(QRect(10, 180, 200, 30));
        pbMeasureWeight->setMinimumSize(QSize(200, 30));
        layoutWidget1 = new QWidget(frame_12);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 220, 231, 121));
        formLayout_3 = new QFormLayout(layoutWidget1);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_28 = new QLabel(layoutWidget1);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setFont(font3);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_28);

        lbFrontLeftFootWeight = new QLabel(layoutWidget1);
        lbFrontLeftFootWeight->setObjectName(QStringLiteral("lbFrontLeftFootWeight"));
        lbFrontLeftFootWeight->setFont(font4);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lbFrontLeftFootWeight);

        label_29 = new QLabel(layoutWidget1);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setFont(font3);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_29);

        lbBackLeftFootWeight = new QLabel(layoutWidget1);
        lbBackLeftFootWeight->setObjectName(QStringLiteral("lbBackLeftFootWeight"));
        lbBackLeftFootWeight->setFont(font4);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, lbBackLeftFootWeight);

        label_30 = new QLabel(layoutWidget1);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setFont(font3);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_30);

        lbFrontRightFootWeight = new QLabel(layoutWidget1);
        lbFrontRightFootWeight->setObjectName(QStringLiteral("lbFrontRightFootWeight"));
        lbFrontRightFootWeight->setFont(font4);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, lbFrontRightFootWeight);

        label_31 = new QLabel(layoutWidget1);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setFont(font3);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_31);

        lbBackRightFootWeight = new QLabel(layoutWidget1);
        lbBackRightFootWeight->setObjectName(QStringLiteral("lbBackRightFootWeight"));
        lbBackRightFootWeight->setFont(font4);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, lbBackRightFootWeight);


        horizontalLayout_8->addWidget(frame_12);


        verticalLayout_6->addWidget(frameFootAnalysis);

        frameUpload = new QFrame(frameWindows);
        frameUpload->setObjectName(QStringLiteral("frameUpload"));
        frameUpload->setMinimumSize(QSize(0, 500));
        frameUpload->setFrameShape(QFrame::Box);
        frameUpload->setFrameShadow(QFrame::Plain);
        layoutWidget2 = new QWidget(frameUpload);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(12, 51, 710, 394));
        verticalLayout_16 = new QVBoxLayout(layoutWidget2);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        treeView = new QTreeView(layoutWidget2);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setMinimumSize(QSize(400, 0));
        treeView->setMaximumSize(QSize(400, 16777215));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, treeView);

        listView = new QListView(layoutWidget2);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setMinimumSize(QSize(300, 0));
        listView->setMaximumSize(QSize(300, 16777215));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setSelectionMode(QAbstractItemView::NoSelection);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, listView);


        verticalLayout_16->addLayout(formLayout_2);

        listView2 = new QListView(layoutWidget2);
        listView2->setObjectName(QStringLiteral("listView2"));
        listView2->setMinimumSize(QSize(700, 0));
        listView2->setMaximumSize(QSize(710, 16777215));
        listView2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView2->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout_16->addWidget(listView2);

        layoutWidget3 = new QWidget(frameUpload);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(728, 51, 203, 341));
        verticalLayout_15 = new QVBoxLayout(layoutWidget3);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(layoutWidget3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QFont font6;
        font6.setBold(true);
        font6.setWeight(75);
        groupBox_2->setFont(font6);
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(3);
        formLayout->setVerticalSpacing(4);
        formLayout->setContentsMargins(5, 2, 2, 2);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font7;
        font7.setBold(false);
        font7.setWeight(50);
        label_5->setFont(font7);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        leIPAddress = new QLineEdit(groupBox_2);
        leIPAddress->setObjectName(QStringLiteral("leIPAddress"));
        leIPAddress->setFont(font7);

        formLayout->setWidget(0, QFormLayout::FieldRole, leIPAddress);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font7);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        leUserName = new QLineEdit(groupBox_2);
        leUserName->setObjectName(QStringLiteral("leUserName"));
        leUserName->setFont(font7);

        formLayout->setWidget(1, QFormLayout::FieldRole, leUserName);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font7);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        lePassword = new QLineEdit(groupBox_2);
        lePassword->setObjectName(QStringLiteral("lePassword"));
        lePassword->setFont(font7);
        lePassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, lePassword);

        ckShowPassword = new QCheckBox(groupBox_2);
        ckShowPassword->setObjectName(QStringLiteral("ckShowPassword"));
        ckShowPassword->setFont(font7);

        formLayout->setWidget(3, QFormLayout::FieldRole, ckShowPassword);


        verticalLayout_15->addWidget(groupBox_2);

        pbConnectServer = new QPushButton(layoutWidget3);
        pbConnectServer->setObjectName(QStringLiteral("pbConnectServer"));
        pbConnectServer->setMinimumSize(QSize(0, 30));

        verticalLayout_15->addWidget(pbConnectServer);

        pbMakeFolder = new QPushButton(layoutWidget3);
        pbMakeFolder->setObjectName(QStringLiteral("pbMakeFolder"));
        pbMakeFolder->setMinimumSize(QSize(0, 30));

        verticalLayout_15->addWidget(pbMakeFolder);

        pbUploadFiles = new QPushButton(layoutWidget3);
        pbUploadFiles->setObjectName(QStringLiteral("pbUploadFiles"));
        pbUploadFiles->setMinimumSize(QSize(0, 30));

        verticalLayout_15->addWidget(pbUploadFiles);

        pbSetSystemFolder = new QPushButton(layoutWidget3);
        pbSetSystemFolder->setObjectName(QStringLiteral("pbSetSystemFolder"));
        pbSetSystemFolder->setMinimumSize(QSize(0, 30));

        verticalLayout_15->addWidget(pbSetSystemFolder);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_6);


        verticalLayout_6->addWidget(frameUpload);

        frameSettings = new QFrame(frameWindows);
        frameSettings->setObjectName(QStringLiteral("frameSettings"));
        frameSettings->setMinimumSize(QSize(0, 500));
        frameSettings->setFrameShape(QFrame::Box);
        frameSettings->setFrameShadow(QFrame::Plain);
        horizontalLayout_12 = new QHBoxLayout(frameSettings);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        groupBox = new QGroupBox(frameSettings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(350, 0));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 101, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 101, 21));
        cbLeftScanner = new QComboBox(groupBox);
        cbLeftScanner->setObjectName(QStringLiteral("cbLeftScanner"));
        cbLeftScanner->setGeometry(QRect(140, 30, 181, 22));
        cbRightScanner = new QComboBox(groupBox);
        cbRightScanner->setObjectName(QStringLiteral("cbRightScanner"));
        cbRightScanner->setGeometry(QRect(140, 80, 181, 22));
        lbLeftImageScale = new QLabel(groupBox);
        lbLeftImageScale->setObjectName(QStringLiteral("lbLeftImageScale"));
        lbLeftImageScale->setGeometry(QRect(170, 130, 81, 21));
        lbLeftImageScale->setFont(font5);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 160, 141, 21));
        label_8->setFont(font3);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 130, 141, 21));
        label_9->setFont(font3);
        lbRightImageScale = new QLabel(groupBox);
        lbRightImageScale->setObjectName(QStringLiteral("lbRightImageScale"));
        lbRightImageScale->setGeometry(QRect(170, 160, 81, 21));
        lbRightImageScale->setFont(font5);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 220, 141, 21));
        label_10->setFont(font3);
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 190, 141, 21));
        label_11->setFont(font3);
        leLeftScannerScale = new QLineEdit(groupBox);
        leLeftScannerScale->setObjectName(QStringLiteral("leLeftScannerScale"));
        leLeftScannerScale->setGeometry(QRect(160, 190, 61, 21));
        QFont font8;
        font8.setPointSize(12);
        font8.setBold(false);
        font8.setWeight(50);
        leLeftScannerScale->setFont(font8);
        leRightScannerScale = new QLineEdit(groupBox);
        leRightScannerScale->setObjectName(QStringLiteral("leRightScannerScale"));
        leRightScannerScale->setGeometry(QRect(160, 220, 61, 21));
        leRightScannerScale->setFont(font8);
        pbSaveScannerSetting = new QPushButton(groupBox);
        pbSaveScannerSetting->setObjectName(QStringLiteral("pbSaveScannerSetting"));
        pbSaveScannerSetting->setGeometry(QRect(20, 380, 150, 30));
        pbSaveScannerSetting->setMinimumSize(QSize(150, 30));
        pbSaveScannerSetting->setMaximumSize(QSize(150, 30));
        pbReloadScannerDrivers = new QPushButton(groupBox);
        pbReloadScannerDrivers->setObjectName(QStringLiteral("pbReloadScannerDrivers"));
        pbReloadScannerDrivers->setGeometry(QRect(180, 380, 150, 30));
        pbReloadScannerDrivers->setMinimumSize(QSize(150, 30));
        pbReloadScannerDrivers->setMaximumSize(QSize(150, 30));

        horizontalLayout_11->addWidget(groupBox);

        groupBox_LoadCell = new QGroupBox(frameSettings);
        groupBox_LoadCell->setObjectName(QStringLiteral("groupBox_LoadCell"));
        groupBox_LoadCell->setMinimumSize(QSize(300, 450));
        ckEnabled = new QCheckBox(groupBox_LoadCell);
        ckEnabled->setObjectName(QStringLiteral("ckEnabled"));
        ckEnabled->setGeometry(QRect(40, 60, 70, 17));
        ckEnabled->setFont(font7);
        label_18 = new QLabel(groupBox_LoadCell);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(50, 240, 51, 16));
        label_18->setFont(font7);
        leFormula = new QLineEdit(groupBox_LoadCell);
        leFormula->setObjectName(QStringLiteral("leFormula"));
        leFormula->setGeometry(QRect(80, 310, 201, 20));
        leFormula->setFont(font7);
        leFormula->setReadOnly(true);
        label_19 = new QLabel(groupBox_LoadCell);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(30, 120, 101, 20));
        label_19->setFont(font7);
        label_20 = new QLabel(groupBox_LoadCell);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(170, 60, 31, 16));
        label_20->setFont(font7);
        label_21 = new QLabel(groupBox_LoadCell);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(50, 270, 51, 16));
        label_21->setFont(font7);
        pbBridgeCalib = new QPushButton(groupBox_LoadCell);
        pbBridgeCalib->setObjectName(QStringLiteral("pbBridgeCalib"));
        pbBridgeCalib->setGeometry(QRect(30, 150, 101, 23));
        pbBridgeCalib->setFont(font7);
        leRate = new QLineEdit(groupBox_LoadCell);
        leRate->setObjectName(QStringLiteral("leRate"));
        leRate->setGeometry(QRect(240, 340, 41, 20));
        leRate->setFont(font7);
        leRate->setAlignment(Qt::AlignCenter);
        pbSet_1 = new QPushButton(groupBox_LoadCell);
        pbSet_1->setObjectName(QStringLiteral("pbSet_1"));
        pbSet_1->setGeometry(QRect(190, 180, 51, 23));
        pbSet_1->setFont(font7);
        pbSet_4 = new QPushButton(groupBox_LoadCell);
        pbSet_4->setObjectName(QStringLiteral("pbSet_4"));
        pbSet_4->setGeometry(QRect(190, 270, 51, 23));
        pbSet_4->setFont(font7);
        leBridgeValue = new QLineEdit(groupBox_LoadCell);
        leBridgeValue->setObjectName(QStringLiteral("leBridgeValue"));
        leBridgeValue->setGeometry(QRect(140, 90, 113, 20));
        leBridgeValue->setFont(font7);
        label_22 = new QLabel(groupBox_LoadCell);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(50, 210, 51, 16));
        label_22->setFont(font7);
        leValue_4 = new QLineEdit(groupBox_LoadCell);
        leValue_4->setObjectName(QStringLiteral("leValue_4"));
        leValue_4->setGeometry(QRect(100, 270, 81, 20));
        leValue_4->setFont(font7);
        leValue_4->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(groupBox_LoadCell);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(30, 310, 51, 16));
        label_23->setFont(font7);
        leConvertedValue = new QLineEdit(groupBox_LoadCell);
        leConvertedValue->setObjectName(QStringLiteral("leConvertedValue"));
        leConvertedValue->setGeometry(QRect(140, 120, 113, 20));
        leConvertedValue->setFont(font7);
        leConvertedValue->setReadOnly(true);
        leValue_3 = new QLineEdit(groupBox_LoadCell);
        leValue_3->setObjectName(QStringLiteral("leValue_3"));
        leValue_3->setGeometry(QRect(100, 240, 81, 20));
        leValue_3->setFont(font7);
        leValue_3->setAlignment(Qt::AlignCenter);
        leValue_2 = new QLineEdit(groupBox_LoadCell);
        leValue_2->setObjectName(QStringLiteral("leValue_2"));
        leValue_2->setGeometry(QRect(100, 210, 81, 20));
        leValue_2->setFont(font7);
        leValue_2->setAlignment(Qt::AlignCenter);
        pbSet_3 = new QPushButton(groupBox_LoadCell);
        pbSet_3->setObjectName(QStringLiteral("pbSet_3"));
        pbSet_3->setGeometry(QRect(190, 240, 51, 23));
        pbSet_3->setFont(font7);
        cbBridgeGains = new QComboBox(groupBox_LoadCell);
        cbBridgeGains->setObjectName(QStringLiteral("cbBridgeGains"));
        cbBridgeGains->setGeometry(QRect(200, 60, 51, 21));
        cbBridgeGains->setFont(font7);
        label_24 = new QLabel(groupBox_LoadCell);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(30, 340, 51, 16));
        label_24->setFont(font7);
        label_25 = new QLabel(groupBox_LoadCell);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(60, 30, 81, 16));
        label_25->setFont(font7);
        label_26 = new QLabel(groupBox_LoadCell);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(50, 180, 51, 16));
        label_26->setFont(font7);
        pbSet_2 = new QPushButton(groupBox_LoadCell);
        pbSet_2->setObjectName(QStringLiteral("pbSet_2"));
        pbSet_2->setGeometry(QRect(190, 210, 51, 23));
        pbSet_2->setFont(font7);
        label_27 = new QLabel(groupBox_LoadCell);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(30, 90, 101, 20));
        label_27->setFont(font7);
        leValue_1 = new QLineEdit(groupBox_LoadCell);
        leValue_1->setObjectName(QStringLiteral("leValue_1"));
        leValue_1->setGeometry(QRect(100, 180, 81, 20));
        leValue_1->setFont(font7);
        leValue_1->setAlignment(Qt::AlignCenter);
        slRate = new QSlider(groupBox_LoadCell);
        slRate->setObjectName(QStringLiteral("slRate"));
        slRate->setGeometry(QRect(80, 340, 151, 22));
        slRate->setFont(font7);
        slRate->setMinimum(8);
        slRate->setMaximum(1000);
        slRate->setValue(200);
        slRate->setOrientation(Qt::Horizontal);
        slRate->setTickPosition(QSlider::TicksBelow);
        cbBridges = new QComboBox(groupBox_LoadCell);
        cbBridges->setObjectName(QStringLiteral("cbBridges"));
        cbBridges->setGeometry(QRect(140, 30, 71, 21));
        cbBridges->setFont(font7);
        pbSaveBridgeSetting = new QPushButton(groupBox_LoadCell);
        pbSaveBridgeSetting->setObjectName(QStringLiteral("pbSaveBridgeSetting"));
        pbSaveBridgeSetting->setGeometry(QRect(20, 380, 120, 30));
        pbSaveBridgeSetting->setMinimumSize(QSize(120, 30));
        pbSaveBridgeSetting->setMaximumSize(QSize(120, 30));
        pbReloadBridge = new QPushButton(groupBox_LoadCell);
        pbReloadBridge->setObjectName(QStringLiteral("pbReloadBridge"));
        pbReloadBridge->setGeometry(QRect(160, 380, 120, 30));
        pbReloadBridge->setMinimumSize(QSize(120, 30));
        pbReloadBridge->setMaximumSize(QSize(120, 30));

        horizontalLayout_11->addWidget(groupBox_LoadCell);


        horizontalLayout_12->addLayout(horizontalLayout_11);

        horizontalSpacer_22 = new QSpacerItem(253, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_22);


        verticalLayout_6->addWidget(frameSettings);


        verticalLayout_7->addWidget(frameWindows);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1025, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindowClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNewCustomer);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuAbout->addAction(actionAbout);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0));
        actionExit->setText(QApplication::translate("MainWindowClass", "&Exit", 0));
        actionNewCustomer->setText(QApplication::translate("MainWindowClass", "New Customer", 0));
        actionSettings->setText(QApplication::translate("MainWindowClass", "Settings", 0));
        actionAbout->setText(QApplication::translate("MainWindowClass", "About", 0));
        leMeasureDate->setText(QApplication::translate("MainWindowClass", "\354\270\241\354\240\225\354\235\274\354\236\220", 0));
        leCenterName->setText(QApplication::translate("MainWindowClass", "\354\204\274\355\204\260\353\252\205", 0));
        leCustomerName->setText(QApplication::translate("MainWindowClass", "\355\232\214\354\233\220\353\252\205", 0));
        leCustomerHeight->setText(QApplication::translate("MainWindowClass", "\354\213\240\354\236\245", 0));
        leBirthDate->setText(QApplication::translate("MainWindowClass", "\354\203\235\353\205\204\354\233\224\354\235\274", 0));
        leCustomerWeight->setText(QApplication::translate("MainWindowClass", "\354\262\264\354\244\221", 0));
        leCustomerSex->setText(QApplication::translate("MainWindowClass", "\354\204\261\353\263\204", 0));
        leBodyMass->setText(QApplication::translate("MainWindowClass", "\354\262\264\354\247\210\353\237\211", 0));
        pbBodyMeasurement->setText(QApplication::translate("MainWindowClass", "\354\262\264\355\230\225\354\270\241\354\240\225", 0));
        pbFootAnalysis->setText(QApplication::translate("MainWindowClass", "\354\241\261\355\230\225\353\266\204\354\204\235", 0));
        pbUpload->setText(QApplication::translate("MainWindowClass", "\354\227\205\353\241\234\353\223\234", 0));
        pbTransferStatus->setText(QApplication::translate("MainWindowClass", "\354\240\204\354\206\241\354\203\201\355\203\234", 0));
        pbSettings->setText(QApplication::translate("MainWindowClass", "SETTINGS", 0));
        ivFootView->setText(QApplication::translate("MainWindowClass", "\354\262\264\355\230\225\354\215\270\353\204\244\354\235\274", 0));
        ivBodyTopView->setText(QApplication::translate("MainWindowClass", "\354\203\201\354\270\241\354\215\270\353\204\244\354\235\274", 0));
        ivBodyFrontView->setText(QApplication::translate("MainWindowClass", "\354\240\225\353\251\264\354\215\270\353\204\244\354\235\274", 0));
        ivBodySideView->setText(QApplication::translate("MainWindowClass", "\354\270\241\353\251\264\354\215\270\353\204\244\354\235\274", 0));
        ivBodyBackView->setText(QApplication::translate("MainWindowClass", "\355\233\204\353\251\264\354\215\270\353\204\244\354\235\274", 0));
        pbSelectBodyCamera->setText(QApplication::translate("MainWindowClass", "\354\262\264\355\230\225\354\270\241\354\240\225\354\271\264\353\251\224\353\235\274\354\204\240\355\203\235", 0));
        pbSelectUpperCamera->setText(QApplication::translate("MainWindowClass", "\354\203\201\354\270\241\354\271\264\353\251\224\353\235\274\354\204\240\355\203\235", 0));
        ivBodyCameraViews->setText(QApplication::translate("MainWindowClass", "Body Camera Views", 0));
        pbUpperCapture->setText(QApplication::translate("MainWindowClass", "\354\203\201\354\270\241\354\270\241\354\240\225", 0));
        pbSideCapture->setText(QApplication::translate("MainWindowClass", "\354\270\241\353\251\261\354\270\241\354\240\225", 0));
        pbFrontCapture->setText(QApplication::translate("MainWindowClass", "\354\240\225\353\251\261\354\270\241\354\240\225", 0));
        pbBackCapture->setText(QApplication::translate("MainWindowClass", "\355\233\204\353\251\261\354\270\241\354\240\225", 0));
        pbSelectFootScanner->setText(QApplication::translate("MainWindowClass", "\354\241\261\355\230\225\354\212\244\354\272\220\353\204\210\354\204\240\355\203\235", 0));
        ivFootPrintView->setText(QApplication::translate("MainWindowClass", "Foot View", 0));
        pbFootPrintCapture->setText(QApplication::translate("MainWindowClass", "\354\241\261\355\230\225\354\270\241\354\240\225", 0));
        pbLeftScan->setText(QApplication::translate("MainWindowClass", "Left Foot Scan", 0));
#ifndef QT_NO_TOOLTIP
        tbLeftFootMeasure->setToolTip(QApplication::translate("MainWindowClass", "Measure", 0));
#endif // QT_NO_TOOLTIP
        tbLeftFootMeasure->setText(QApplication::translate("MainWindowClass", "...", 0));
        pbRightScan->setText(QApplication::translate("MainWindowClass", "Right Foot Scan", 0));
#ifndef QT_NO_TOOLTIP
        tbRightFootMeasure->setToolTip(QApplication::translate("MainWindowClass", "Measure", 0));
#endif // QT_NO_TOOLTIP
        tbRightFootMeasure->setText(QApplication::translate("MainWindowClass", "...", 0));
        label_3->setText(QApplication::translate("MainWindowClass", "Left Foot Legth:", 0));
        lbLeftFootLength->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_14->setText(QApplication::translate("MainWindowClass", "cm", 0));
        label_4->setText(QApplication::translate("MainWindowClass", "Left Foot Angle:", 0));
        lbLeftFootAngle->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_13->setText(QApplication::translate("MainWindowClass", "Right Foot Legth:", 0));
        lbRightFootLength->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_12->setText(QApplication::translate("MainWindowClass", "Right Foot Angle:", 0));
        lbRightFootAngle->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_17->setText(QApplication::translate("MainWindowClass", "deg", 0));
        label_16->setText(QApplication::translate("MainWindowClass", "deg", 0));
        label_15->setText(QApplication::translate("MainWindowClass", "cm", 0));
        pbMeasureWeight->setText(QApplication::translate("MainWindowClass", "Measure Foot Weight", 0));
        label_28->setText(QApplication::translate("MainWindowClass", "Front Left Foot Weight:", 0));
        lbFrontLeftFootWeight->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_29->setText(QApplication::translate("MainWindowClass", "Back Left Foot Weight:", 0));
        lbBackLeftFootWeight->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_30->setText(QApplication::translate("MainWindowClass", "Front Right  Foot Weight:", 0));
        lbFrontRightFootWeight->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_31->setText(QApplication::translate("MainWindowClass", "Back Right  Foot Weight:", 0));
        lbBackRightFootWeight->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindowClass", "Login", 0));
        label_5->setText(QApplication::translate("MainWindowClass", "IP Address:", 0));
        label_6->setText(QApplication::translate("MainWindowClass", "User name:", 0));
        label_7->setText(QApplication::translate("MainWindowClass", "Password:", 0));
        ckShowPassword->setText(QApplication::translate("MainWindowClass", "Show password", 0));
        pbConnectServer->setText(QApplication::translate("MainWindowClass", "Connect Server", 0));
        pbMakeFolder->setText(QApplication::translate("MainWindowClass", "Make Folder", 0));
        pbUploadFiles->setText(QApplication::translate("MainWindowClass", "Upload Files...", 0));
        pbSetSystemFolder->setText(QApplication::translate("MainWindowClass", "Set Sytem Folder", 0));
        groupBox->setTitle(QApplication::translate("MainWindowClass", "Scanners", 0));
        label->setText(QApplication::translate("MainWindowClass", "Left Foot Scanner:", 0));
        label_2->setText(QApplication::translate("MainWindowClass", "Right Foot Scanner:", 0));
        lbLeftImageScale->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_8->setText(QApplication::translate("MainWindowClass", "Right Foot Image Scale:", 0));
        label_9->setText(QApplication::translate("MainWindowClass", "Left Foot Image Scale:", 0));
        lbRightImageScale->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_10->setText(QApplication::translate("MainWindowClass", "Right Scanner Scale:", 0));
        label_11->setText(QApplication::translate("MainWindowClass", "Left Scanner Scale:", 0));
        leLeftScannerScale->setText(QApplication::translate("MainWindowClass", "1", 0));
        leRightScannerScale->setText(QApplication::translate("MainWindowClass", "1", 0));
        pbSaveScannerSetting->setText(QApplication::translate("MainWindowClass", "Save Scanner Setting", 0));
        pbReloadScannerDrivers->setText(QApplication::translate("MainWindowClass", "Reload Scanner Drivers", 0));
        groupBox_LoadCell->setTitle(QApplication::translate("MainWindowClass", "Load Cells", 0));
        ckEnabled->setText(QApplication::translate("MainWindowClass", "Enabled", 0));
        label_18->setText(QApplication::translate("MainWindowClass", "Value 3:", 0));
        label_19->setText(QApplication::translate("MainWindowClass", "Converted Value [kg]", 0));
        label_20->setText(QApplication::translate("MainWindowClass", "Gain:", 0));
        label_21->setText(QApplication::translate("MainWindowClass", "Value 4:", 0));
        pbBridgeCalib->setText(QApplication::translate("MainWindowClass", "Start Calibration", 0));
        leRate->setText(QApplication::translate("MainWindowClass", "200", 0));
        pbSet_1->setText(QApplication::translate("MainWindowClass", "Set", 0));
        pbSet_4->setText(QApplication::translate("MainWindowClass", "Set", 0));
        leBridgeValue->setText(QApplication::translate("MainWindowClass", "Unknown", 0));
        label_22->setText(QApplication::translate("MainWindowClass", "Value 2:", 0));
        label_23->setText(QApplication::translate("MainWindowClass", "Formula:", 0));
        leConvertedValue->setText(QString());
        pbSet_3->setText(QApplication::translate("MainWindowClass", "Set", 0));
        label_24->setText(QApplication::translate("MainWindowClass", "Rate:", 0));
        label_25->setText(QApplication::translate("MainWindowClass", "Choose Bridge:", 0));
        label_26->setText(QApplication::translate("MainWindowClass", "Value 1:", 0));
        pbSet_2->setText(QApplication::translate("MainWindowClass", "Set", 0));
        label_27->setText(QApplication::translate("MainWindowClass", "Bridge Value [mV/V]:", 0));
        pbSaveBridgeSetting->setText(QApplication::translate("MainWindowClass", "Save Bridge Setting", 0));
        pbReloadBridge->setText(QApplication::translate("MainWindowClass", "Reload Bridge", 0));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", 0));
        menuAbout->setTitle(QApplication::translate("MainWindowClass", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
