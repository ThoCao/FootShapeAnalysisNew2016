/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "imgview.h"
#include "logviewer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionExit;
    QAction *actionNewCustomer;
    QAction *actionSettings;
    QAction *actionAbout;
    QAction *actionCalib_Scale;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_3;
    QLabel *label_40;
    QDateEdit *dateEdit;
    QLabel *label_33;
    QLineEdit *leCustomerName;
    QLabel *label_39;
    QDateEdit *dateEdit_2;
    QLabel *label_37;
    QComboBox *comboBox;
    QLabel *label_34;
    QLineEdit *leCenterName;
    QLabel *label_35;
    QLineEdit *leCustomerHeight;
    QLabel *label_36;
    QLineEdit *leCustomerWeight;
    QLabel *label_38;
    QLineEdit *leBodyMass;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_3;
    ImgView *ivBodyFrontView;
    ImgView *ivBodyTopView;
    ImgView *ivBodySideView;
    ImgView *ivBodyBackView;
    ImgView *ivBodyCameraViews;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pbSelectUpperCamera;
    QPushButton *pbUpperCapture;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pbSelectBodyCamera;
    QPushButton *pbFrontCapture;
    QPushButton *pbSideCapture;
    QPushButton *pbBackCapture;
    QWidget *tab_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    ImgView *ivLeftAnalysisImage;
    ImgView *ivRightAnalysisImage;
    ImgView *ivLeftDetectImage;
    ImgView *ivRightDetectImage;
    LogViewer *log;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *pbLeftScan;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbOldCustomer;
    QSpacerItem *horizontalSpacer_9;
    QToolButton *tbLeftFootReload;
    QRadioButton *radioButton_left;
    QRadioButton *radioButton_left_foot_mearsure;
    QToolButton *tbLeftFootDetect;
    QSpacerItem *horizontalSpacer_21;
    QToolButton *tbRightFootReload;
    QRadioButton *radioButton_right;
    QRadioButton *radioButton_right_foot_mearsure;
    QToolButton *tbRightFootDetect;
    QSpacerItem *horizontalSpacer_20;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollAreaLeftFoot;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *scrollAreaRightFoot;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_9;
    QGridLayout *gridLayout;
    QLabel *label_49;
    QLabel *label_46;
    QLabel *label_47;
    QLabel *label_42;
    QLabel *lbLeft_Lenght_Line4;
    QLabel *lbRight_Lenght_Line4;
    QLabel *label_41;
    QLabel *lbLeft_Lenght_Line3;
    QLabel *lbRight_Lenght_Line3;
    QLabel *label_43;
    QLabel *lbLeft_Lenght_Line5;
    QLabel *lbRight_Lenght_Line5;
    QLabel *label_48;
    QLabel *lbLeft_Lenght_Vertical;
    QLabel *lbRight_Lenght_Vertical;
    QLabel *label_5;
    QLabel *lbLeft_Angle_L1_L2;
    QLabel *lbRight_Angle_L1_L2;
    QLabel *label_44;
    QLabel *lbLeft_Angle_Upper;
    QLabel *lbRight_Angle_Upper;
    QLabel *label_50;
    QLabel *lbLeft_Distance;
    QLabel *lbRight_Distance;
    QSpacerItem *verticalSpacer_11;
    QGridLayout *gridLayout_2;
    QLabel *label_28;
    QLabel *lbFrontLeftFootWeight;
    QLabel *label_29;
    QLabel *lbBackLeftFootWeight;
    QLabel *label_30;
    QLabel *lbFrontRightFootWeight;
    QLabel *label_31;
    QLabel *lbBackRightFootWeight;
    QSpacerItem *verticalSpacer_10;
    QPushButton *pbSaveAnalysisResults;
    QSpacerItem *verticalSpacer_7;
    ImgView *commandPicture;
    QWidget *tab_3;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *verticalLayout_22;
    QTreeView *treeView;
    QListView *listView2;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_23;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QLabel *label_6;
    QLineEdit *leUserName;
    QLabel *label_7;
    QLineEdit *lePassword;
    QCheckBox *ckShowPassword;
    QPushButton *pbConnectServer;
    QPushButton *pbUploadFiles;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QWidget *tab_4;
    QWidget *tab_5;
    QGridLayout *gridLayout_6;
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
    QGroupBox *groupBox_3;
    ImgView *ivWebcamera;
    QComboBox *cbWebcamSelect;
    QPushButton *pbSetUpperWebcam;
    QPushButton *pbSetSideWebcam;
    QPushButton *pbReSetWebcam;
    QGroupBox *groupBox_LoadCell;
    QCheckBox *ckEnabled;
    QLabel *label_18;
    QLineEdit *leFormula;
    QLabel *label_20;
    QLabel *label_21;
    QPushButton *pbBridgeCalib;
    QLineEdit *leRate;
    QLabel *label_22;
    QLineEdit *leValue_4;
    QLabel *label_23;
    QLineEdit *leValue_3;
    QLineEdit *leValue_2;
    QComboBox *cbBridgeGains;
    QLabel *label_24;
    QLabel *label_26;
    QLineEdit *leValue_1;
    QSlider *slRate;
    QPushButton *pbSaveBridgeSetting;
    QLineEdit *leValue_5;
    QPushButton *pbSet_5;
    QPushButton *pbSet_6;
    QLabel *label_32;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QMenu *menuEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1386, 868);
        QIcon icon;
        icon.addFile(QStringLiteral("detect.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowClass->setWindowIcon(icon);
        MainWindowClass->setStyleSheet(QLatin1String("QPushButton{\n"
"	background:#eee;\n"
"	border:1px solid #555;\n"
"	border-radius:5px;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"	background:#ccc;\n"
"}\n"
"\n"
"QPushButton::pressed{\n"
"	background:#aaa;\n"
"}\n"
"QPushButton[IsCaptureButton=true]{\n"
"	background:#bcf;\n"
"	border:1px solid #555;\n"
"	border-radius:5px;\n"
"}\n"
"\n"
"QPushButton::hover[IsCaptureButton=true]{\n"
"	background:#cbe;\n"
"	border:1px solid #555;\n"
"	border-radius:5px;\n"
"}\n"
"QPushButton::pressed[IsCaptureButton=true]{\n"
"	background:#9ad;\n"
"	border:1px solid #555;\n"
"	border-radius:5px;\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton[ButtonType=\"Mid\"]{\n"
"\n"
"	margin-bottom:-1px;\n"
"}\n"
"\n"
"QPushButton[ButtonType=\"Top\"]{\n"
"	background: qlineargradient(x1 : 0, y1 : 0, x2 : 1, y2 :   1, stop :   0.0 #c0dbff,\n"
"        stop :   0.5 #cfd26f, stop :   0.55 #c7df6f, stop :   1.0 #f5f9ff);\n"
"	border-top-left-radius: 20px;\n"
"	margin-bottom:-1px;\n"
"}\n"
"\n"
"QPushButton[ButtonType=\"Bot\"]{\n"
"	/*background:qlineargradie"
                        "nt(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #999, stop: 0.5 #ccc, stop:1 #ccc);*/\n"
"	background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1,\n"
"     stop :   0.0 #0af,\n"
"     stop :   0.5 #00f,\n"
"     stop :   1.0 #0af);\n"
"	border-bottom-left-radius: 20px;\n"
"}\n"
"QPlainTextEdit{\n"
"	background:#ddd;\n"
"	border:1px solid #333;\n"
"\n"
"}\n"
"/*ThoCao  Group Slector*/\n"
"\n"
"QPushButton:on {\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #5AA72D,\n"
"        stop :   0.5 #B3E296, stop :   0.55 #B3E296, stop :   1.0 #f5f9ff);\n"
"        padding-top: 2px;\n"
"        padding-left: 3px;\n"
"}\n"
"QPushButton:disabled {\n"
"        background: transparent #e5e9ee;\n"
"        padding-top: 2px;        \n"
"        padding-left: 3px;\n"
"        color: black;\n"
"}\n"
"/*  Button Right */\n"
"QPushButton[ButtonType=\"RIGHT\"]{\n"
"        	border-top-right-radius: 20px;\n"
"            border-bottom-right-radius: 20px;\n"
"}\n"
"/* QLineEdit*/\n"
"QLineE"
                        "dit{\n"
" /*   background:#00ff7f;*/\n"
"    border:1px solid #555;\n"
"	border-radius:5px;\n"
"}\n"
"\n"
"\n"
"\n"
"QToolButton[ButtonType=\"SideButton\"]{\n"
"	background:#eee;\n"
"	border:1px solid #555;\n"
"	margin-bottom:-1px;\n"
"	margin-right:-1px;\n"
"}\n"
"QToolButton[ButtonType=\"SideButton\"][IsBot=true]{\n"
"	margin-bottom:0px;\n"
"	border-bottom-left-radius: 10px;\n"
"}\n"
"QToolButton[ButtonType=\"SideButton\"][IsTop=true]{\n"
"	border-top-left-radius: 10px;\n"
"}\n"
"\n"
"\n"
"QToolButton::hover[ButtonType=\"SideButton\"]{\n"
"	background:#ccc;\n"
"}\n"
"\n"
"QToolButton::pressed[ButtonType=\"SideButton\"]{\n"
"	background:#bbb;\n"
"}\n"
"\n"
"QTabWidget{\n"
"	border:1px solid #555;\n"
"}\n"
"\n"
"QLabel[IsImgView=true]{\n"
"	border: 1px solid #555;\n"
"}"));
        actionExit = new QAction(MainWindowClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionNewCustomer = new QAction(MainWindowClass);
        actionNewCustomer->setObjectName(QStringLiteral("actionNewCustomer"));
        actionSettings = new QAction(MainWindowClass);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionAbout = new QAction(MainWindowClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionCalib_Scale = new QAction(MainWindowClass);
        actionCalib_Scale->setObjectName(QStringLiteral("actionCalib_Scale"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_7 = new QVBoxLayout(centralWidget);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_40 = new QLabel(centralWidget);
        label_40->setObjectName(QStringLiteral("label_40"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        label_40->setFont(font);

        gridLayout_3->addWidget(label_40, 0, 0, 1, 1);

        dateEdit = new QDateEdit(centralWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setDateTime(QDateTime(QDate(2016, 9, 1), QTime(0, 0, 0)));

        gridLayout_3->addWidget(dateEdit, 0, 1, 1, 1);

        label_33 = new QLabel(centralWidget);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setFont(font);

        gridLayout_3->addWidget(label_33, 0, 2, 1, 1);

        leCustomerName = new QLineEdit(centralWidget);
        leCustomerName->setObjectName(QStringLiteral("leCustomerName"));
        leCustomerName->setMinimumSize(QSize(100, 22));
        QFont font1;
        font1.setFamily(QStringLiteral("Malgun Gothic"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        leCustomerName->setFont(font1);
        leCustomerName->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(leCustomerName, 0, 3, 1, 1);

        label_39 = new QLabel(centralWidget);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setFont(font);

        gridLayout_3->addWidget(label_39, 0, 4, 1, 1);

        dateEdit_2 = new QDateEdit(centralWidget);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setDateTime(QDateTime(QDate(1980, 1, 1), QTime(0, 0, 0)));

        gridLayout_3->addWidget(dateEdit_2, 0, 5, 1, 1);

        label_37 = new QLabel(centralWidget);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setFont(font);

        gridLayout_3->addWidget(label_37, 0, 6, 1, 1);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEnabled(true);

        gridLayout_3->addWidget(comboBox, 0, 7, 1, 1);

        label_34 = new QLabel(centralWidget);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setFont(font);

        gridLayout_3->addWidget(label_34, 1, 0, 1, 1);

        leCenterName = new QLineEdit(centralWidget);
        leCenterName->setObjectName(QStringLiteral("leCenterName"));
        leCenterName->setMinimumSize(QSize(100, 22));
        leCenterName->setFont(font1);
        leCenterName->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(leCenterName, 1, 1, 1, 1);

        label_35 = new QLabel(centralWidget);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setFont(font);

        gridLayout_3->addWidget(label_35, 1, 2, 1, 1);

        leCustomerHeight = new QLineEdit(centralWidget);
        leCustomerHeight->setObjectName(QStringLiteral("leCustomerHeight"));
        leCustomerHeight->setMinimumSize(QSize(100, 22));
        leCustomerHeight->setFont(font1);
        leCustomerHeight->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(leCustomerHeight, 1, 3, 1, 1);

        label_36 = new QLabel(centralWidget);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setFont(font);

        gridLayout_3->addWidget(label_36, 1, 4, 1, 1);

        leCustomerWeight = new QLineEdit(centralWidget);
        leCustomerWeight->setObjectName(QStringLiteral("leCustomerWeight"));
        leCustomerWeight->setMinimumSize(QSize(100, 22));
        leCustomerWeight->setFont(font1);
        leCustomerWeight->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(leCustomerWeight, 1, 5, 1, 1);

        label_38 = new QLabel(centralWidget);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setFont(font);

        gridLayout_3->addWidget(label_38, 1, 6, 1, 1);

        leBodyMass = new QLineEdit(centralWidget);
        leBodyMass->setObjectName(QStringLiteral("leBodyMass"));
        leBodyMass->setMinimumSize(QSize(100, 22));
        leBodyMass->setFont(font1);
        leBodyMass->setAlignment(Qt::AlignCenter);
        leBodyMass->setReadOnly(true);

        gridLayout_3->addWidget(leBodyMass, 1, 7, 1, 1);


        verticalLayout_7->addLayout(gridLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(72, 72));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        toolButton->setFont(font2);
        toolButton->setProperty("IsTop", QVariant(true));

        verticalLayout_6->addWidget(toolButton);

        toolButton_2 = new QToolButton(centralWidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(72, 72));
        toolButton_2->setFont(font2);

        verticalLayout_6->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(centralWidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(72, 72));
        toolButton_3->setFont(font2);

        verticalLayout_6->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(centralWidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(72, 72));
        toolButton_4->setFont(font2);

        verticalLayout_6->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(centralWidget);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setMinimumSize(QSize(72, 72));
        toolButton_5->setFont(font2);
        toolButton_5->setProperty("IsBot", QVariant(true));

        verticalLayout_6->addWidget(toolButton_5);


        verticalLayout_5->addLayout(verticalLayout_6);

        verticalSpacer = new QSpacerItem(20, 256, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_5);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabBarAutoHide(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        ivBodyFrontView = new ImgView(tab);
        ivBodyFrontView->setObjectName(QStringLiteral("ivBodyFrontView"));
        ivBodyFrontView->setMinimumSize(QSize(160, 160));
        ivBodyFrontView->setMaximumSize(QSize(160, 160));
        QFont font3;
        font3.setFamily(QStringLiteral("Malgun Gothic"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        ivBodyFrontView->setFont(font3);
        ivBodyFrontView->setLayoutDirection(Qt::LeftToRight);
        ivBodyFrontView->setStyleSheet(QStringLiteral(""));
        ivBodyFrontView->setAlignment(Qt::AlignCenter);
        ivBodyFrontView->setProperty("IsImgView", QVariant(true));

        verticalLayout_3->addWidget(ivBodyFrontView);

        ivBodyTopView = new ImgView(tab);
        ivBodyTopView->setObjectName(QStringLiteral("ivBodyTopView"));
        ivBodyTopView->setMinimumSize(QSize(160, 160));
        ivBodyTopView->setMaximumSize(QSize(160, 160));
        ivBodyTopView->setFont(font3);
        ivBodyTopView->setLayoutDirection(Qt::LeftToRight);
        ivBodyTopView->setStyleSheet(QStringLiteral(""));
        ivBodyTopView->setAlignment(Qt::AlignCenter);
        ivBodyTopView->setProperty("IsImgView", QVariant(true));

        verticalLayout_3->addWidget(ivBodyTopView);

        ivBodySideView = new ImgView(tab);
        ivBodySideView->setObjectName(QStringLiteral("ivBodySideView"));
        ivBodySideView->setMinimumSize(QSize(160, 160));
        ivBodySideView->setMaximumSize(QSize(160, 160));
        ivBodySideView->setFont(font3);
        ivBodySideView->setLayoutDirection(Qt::LeftToRight);
        ivBodySideView->setAlignment(Qt::AlignCenter);
        ivBodySideView->setProperty("IsImgView", QVariant(true));

        verticalLayout_3->addWidget(ivBodySideView);

        ivBodyBackView = new ImgView(tab);
        ivBodyBackView->setObjectName(QStringLiteral("ivBodyBackView"));
        ivBodyBackView->setMinimumSize(QSize(160, 160));
        ivBodyBackView->setMaximumSize(QSize(160, 160));
        ivBodyBackView->setFont(font3);
        ivBodyBackView->setLayoutDirection(Qt::LeftToRight);
        ivBodyBackView->setAlignment(Qt::AlignCenter);
        ivBodyBackView->setProperty("IsImgView", QVariant(true));

        verticalLayout_3->addWidget(ivBodyBackView);


        gridLayout_4->addLayout(verticalLayout_3, 0, 0, 1, 1);

        ivBodyCameraViews = new ImgView(tab);
        ivBodyCameraViews->setObjectName(QStringLiteral("ivBodyCameraViews"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ivBodyCameraViews->sizePolicy().hasHeightForWidth());
        ivBodyCameraViews->setSizePolicy(sizePolicy);
        ivBodyCameraViews->setMinimumSize(QSize(960, 540));
        ivBodyCameraViews->setMaximumSize(QSize(1280, 1280));
        QFont font4;
        font4.setPointSize(10);
        ivBodyCameraViews->setFont(font4);
        ivBodyCameraViews->setStyleSheet(QStringLiteral(""));
        ivBodyCameraViews->setFrameShape(QFrame::NoFrame);
        ivBodyCameraViews->setAlignment(Qt::AlignCenter);
        ivBodyCameraViews->setProperty("IsImgView", QVariant(true));

        gridLayout_4->addWidget(ivBodyCameraViews, 0, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pbSelectUpperCamera = new QPushButton(tab);
        pbSelectUpperCamera->setObjectName(QStringLiteral("pbSelectUpperCamera"));
        pbSelectUpperCamera->setMinimumSize(QSize(130, 30));
        pbSelectUpperCamera->setFont(font1);
        pbSelectUpperCamera->setProperty("IsCaptureButton", QVariant(true));

        horizontalLayout_5->addWidget(pbSelectUpperCamera);

        pbUpperCapture = new QPushButton(tab);
        pbUpperCapture->setObjectName(QStringLiteral("pbUpperCapture"));
        pbUpperCapture->setMinimumSize(QSize(130, 30));
        pbUpperCapture->setFont(font1);

        horizontalLayout_5->addWidget(pbUpperCapture);

        horizontalSpacer_3 = new QSpacerItem(78, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        pbSelectBodyCamera = new QPushButton(tab);
        pbSelectBodyCamera->setObjectName(QStringLiteral("pbSelectBodyCamera"));
        pbSelectBodyCamera->setMinimumSize(QSize(130, 30));
        pbSelectBodyCamera->setFont(font1);
        pbSelectBodyCamera->setProperty("IsCaptureButton", QVariant(true));

        horizontalLayout_5->addWidget(pbSelectBodyCamera);

        pbFrontCapture = new QPushButton(tab);
        pbFrontCapture->setObjectName(QStringLiteral("pbFrontCapture"));
        pbFrontCapture->setMinimumSize(QSize(130, 30));
        pbFrontCapture->setFont(font1);

        horizontalLayout_5->addWidget(pbFrontCapture);

        pbSideCapture = new QPushButton(tab);
        pbSideCapture->setObjectName(QStringLiteral("pbSideCapture"));
        pbSideCapture->setMinimumSize(QSize(130, 30));
        pbSideCapture->setFont(font1);

        horizontalLayout_5->addWidget(pbSideCapture);

        pbBackCapture = new QPushButton(tab);
        pbBackCapture->setObjectName(QStringLiteral("pbBackCapture"));
        pbBackCapture->setMinimumSize(QSize(130, 30));
        pbBackCapture->setFont(font1);

        horizontalLayout_5->addWidget(pbBackCapture);


        gridLayout_4->addLayout(horizontalLayout_5, 1, 0, 1, 2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 1259, 764));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ivLeftAnalysisImage = new ImgView(layoutWidget);
        ivLeftAnalysisImage->setObjectName(QStringLiteral("ivLeftAnalysisImage"));
        ivLeftAnalysisImage->setMinimumSize(QSize(160, 160));
        ivLeftAnalysisImage->setMaximumSize(QSize(160, 160));
        ivLeftAnalysisImage->setFont(font3);
        ivLeftAnalysisImage->setLayoutDirection(Qt::LeftToRight);
        ivLeftAnalysisImage->setStyleSheet(QStringLiteral(""));
        ivLeftAnalysisImage->setAlignment(Qt::AlignCenter);
        ivLeftAnalysisImage->setProperty("IsImgView", QVariant(true));

        verticalLayout->addWidget(ivLeftAnalysisImage);

        ivRightAnalysisImage = new ImgView(layoutWidget);
        ivRightAnalysisImage->setObjectName(QStringLiteral("ivRightAnalysisImage"));
        ivRightAnalysisImage->setMinimumSize(QSize(160, 160));
        ivRightAnalysisImage->setMaximumSize(QSize(160, 160));
        ivRightAnalysisImage->setFont(font3);
        ivRightAnalysisImage->setLayoutDirection(Qt::LeftToRight);
        ivRightAnalysisImage->setStyleSheet(QStringLiteral(""));
        ivRightAnalysisImage->setAlignment(Qt::AlignCenter);
        ivRightAnalysisImage->setProperty("IsImgView", QVariant(true));

        verticalLayout->addWidget(ivRightAnalysisImage);

        ivLeftDetectImage = new ImgView(layoutWidget);
        ivLeftDetectImage->setObjectName(QStringLiteral("ivLeftDetectImage"));
        ivLeftDetectImage->setMinimumSize(QSize(160, 160));
        ivLeftDetectImage->setMaximumSize(QSize(160, 160));
        ivLeftDetectImage->setFont(font3);
        ivLeftDetectImage->setLayoutDirection(Qt::LeftToRight);
        ivLeftDetectImage->setStyleSheet(QStringLiteral(""));
        ivLeftDetectImage->setAlignment(Qt::AlignCenter);
        ivLeftDetectImage->setProperty("IsImgView", QVariant(true));

        verticalLayout->addWidget(ivLeftDetectImage);

        ivRightDetectImage = new ImgView(layoutWidget);
        ivRightDetectImage->setObjectName(QStringLiteral("ivRightDetectImage"));
        ivRightDetectImage->setMinimumSize(QSize(160, 160));
        ivRightDetectImage->setMaximumSize(QSize(160, 160));
        ivRightDetectImage->setFont(font3);
        ivRightDetectImage->setLayoutDirection(Qt::LeftToRight);
        ivRightDetectImage->setStyleSheet(QStringLiteral(""));
        ivRightDetectImage->setAlignment(Qt::AlignCenter);
        ivRightDetectImage->setProperty("IsImgView", QVariant(true));

        verticalLayout->addWidget(ivRightDetectImage);

        log = new LogViewer(layoutWidget);
        log->setObjectName(QStringLiteral("log"));
        log->setMinimumSize(QSize(160, 40));
        log->setMaximumSize(QSize(160, 60));
        log->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(log);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_19);

        pbLeftScan = new QPushButton(layoutWidget);
        pbLeftScan->setObjectName(QStringLiteral("pbLeftScan"));
        pbLeftScan->setMinimumSize(QSize(200, 30));

        horizontalLayout_15->addWidget(pbLeftScan);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_14);


        verticalLayout_4->addLayout(horizontalLayout_15);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pbOldCustomer = new QPushButton(layoutWidget);
        pbOldCustomer->setObjectName(QStringLiteral("pbOldCustomer"));
        pbOldCustomer->setMinimumSize(QSize(50, 30));

        horizontalLayout->addWidget(pbOldCustomer);

        horizontalSpacer_9 = new QSpacerItem(38, 47, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        tbLeftFootReload = new QToolButton(layoutWidget);
        tbLeftFootReload->setObjectName(QStringLiteral("tbLeftFootReload"));
        tbLeftFootReload->setMinimumSize(QSize(36, 36));
        tbLeftFootReload->setStyleSheet(QStringLiteral("border: none"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/MainWindow/reload.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        tbLeftFootReload->setIcon(icon1);
        tbLeftFootReload->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(tbLeftFootReload);

        radioButton_left = new QRadioButton(layoutWidget);
        radioButton_left->setObjectName(QStringLiteral("radioButton_left"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/MainWindow/set-square.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_left->setIcon(icon2);

        horizontalLayout->addWidget(radioButton_left);

        radioButton_left_foot_mearsure = new QRadioButton(layoutWidget);
        radioButton_left_foot_mearsure->setObjectName(QStringLiteral("radioButton_left_foot_mearsure"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/MainWindow/measure.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_left_foot_mearsure->setIcon(icon3);

        horizontalLayout->addWidget(radioButton_left_foot_mearsure);

        tbLeftFootDetect = new QToolButton(layoutWidget);
        tbLeftFootDetect->setObjectName(QStringLiteral("tbLeftFootDetect"));
        tbLeftFootDetect->setMinimumSize(QSize(36, 36));
        tbLeftFootDetect->setStyleSheet(QStringLiteral("border: none"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/MainWindow/detect.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbLeftFootDetect->setIcon(icon4);
        tbLeftFootDetect->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(tbLeftFootDetect);

        horizontalSpacer_21 = new QSpacerItem(88, 29, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_21);

        tbRightFootReload = new QToolButton(layoutWidget);
        tbRightFootReload->setObjectName(QStringLiteral("tbRightFootReload"));
        tbRightFootReload->setMinimumSize(QSize(36, 36));
        tbRightFootReload->setStyleSheet(QStringLiteral("border: none"));
        tbRightFootReload->setIcon(icon1);
        tbRightFootReload->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(tbRightFootReload);

        radioButton_right = new QRadioButton(layoutWidget);
        radioButton_right->setObjectName(QStringLiteral("radioButton_right"));
        radioButton_right->setIcon(icon2);

        horizontalLayout->addWidget(radioButton_right);

        radioButton_right_foot_mearsure = new QRadioButton(layoutWidget);
        radioButton_right_foot_mearsure->setObjectName(QStringLiteral("radioButton_right_foot_mearsure"));
        radioButton_right_foot_mearsure->setIcon(icon3);

        horizontalLayout->addWidget(radioButton_right_foot_mearsure);

        tbRightFootDetect = new QToolButton(layoutWidget);
        tbRightFootDetect->setObjectName(QStringLiteral("tbRightFootDetect"));
        tbRightFootDetect->setMinimumSize(QSize(36, 36));
        tbRightFootDetect->setStyleSheet(QStringLiteral("border: none"));
        tbRightFootDetect->setIcon(icon4);
        tbRightFootDetect->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(tbRightFootDetect);

        horizontalSpacer_20 = new QSpacerItem(80, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_20);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        scrollAreaLeftFoot = new QScrollArea(layoutWidget);
        scrollAreaLeftFoot->setObjectName(QStringLiteral("scrollAreaLeftFoot"));
        scrollAreaLeftFoot->setMinimumSize(QSize(400, 0));
        scrollAreaLeftFoot->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        scrollAreaLeftFoot->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 398, 663));
        scrollAreaLeftFoot->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollAreaLeftFoot);

        scrollAreaRightFoot = new QScrollArea(layoutWidget);
        scrollAreaRightFoot->setObjectName(QStringLiteral("scrollAreaRightFoot"));
        scrollAreaRightFoot->setMinimumSize(QSize(400, 0));
        scrollAreaRightFoot->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        scrollAreaRightFoot->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 398, 663));
        scrollAreaRightFoot->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_2->addWidget(scrollAreaRightFoot);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_9 = new QSpacerItem(197, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_9);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_49 = new QLabel(layoutWidget);
        label_49->setObjectName(QStringLiteral("label_49"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_49->sizePolicy().hasHeightForWidth());
        label_49->setSizePolicy(sizePolicy1);
        label_49->setMinimumSize(QSize(10, 0));
        label_49->setMaximumSize(QSize(16777215, 16777215));
        label_49->setFont(font4);
        label_49->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_49, 0, 0, 1, 1);

        label_46 = new QLabel(layoutWidget);
        label_46->setObjectName(QStringLiteral("label_46"));
        sizePolicy1.setHeightForWidth(label_46->sizePolicy().hasHeightForWidth());
        label_46->setSizePolicy(sizePolicy1);
        label_46->setMinimumSize(QSize(10, 0));
        label_46->setMaximumSize(QSize(16777215, 16777215));
        label_46->setFont(font4);
        label_46->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_46, 0, 1, 1, 1);

        label_47 = new QLabel(layoutWidget);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setMinimumSize(QSize(20, 0));
        label_47->setFont(font4);
        label_47->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_47, 0, 2, 1, 1);

        label_42 = new QLabel(layoutWidget);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setFont(font4);

        gridLayout->addWidget(label_42, 1, 0, 1, 1);

        lbLeft_Lenght_Line4 = new QLabel(layoutWidget);
        lbLeft_Lenght_Line4->setObjectName(QStringLiteral("lbLeft_Lenght_Line4"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lbLeft_Lenght_Line4->sizePolicy().hasHeightForWidth());
        lbLeft_Lenght_Line4->setSizePolicy(sizePolicy2);
        lbLeft_Lenght_Line4->setMinimumSize(QSize(60, 0));
        QFont font5;
        font5.setPointSize(13);
        lbLeft_Lenght_Line4->setFont(font5);
        lbLeft_Lenght_Line4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbLeft_Lenght_Line4, 1, 1, 1, 1);

        lbRight_Lenght_Line4 = new QLabel(layoutWidget);
        lbRight_Lenght_Line4->setObjectName(QStringLiteral("lbRight_Lenght_Line4"));
        sizePolicy2.setHeightForWidth(lbRight_Lenght_Line4->sizePolicy().hasHeightForWidth());
        lbRight_Lenght_Line4->setSizePolicy(sizePolicy2);
        lbRight_Lenght_Line4->setMinimumSize(QSize(60, 0));
        lbRight_Lenght_Line4->setFont(font5);
        lbRight_Lenght_Line4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbRight_Lenght_Line4, 1, 2, 1, 1);

        label_41 = new QLabel(layoutWidget);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setFont(font4);

        gridLayout->addWidget(label_41, 2, 0, 1, 1);

        lbLeft_Lenght_Line3 = new QLabel(layoutWidget);
        lbLeft_Lenght_Line3->setObjectName(QStringLiteral("lbLeft_Lenght_Line3"));
        sizePolicy2.setHeightForWidth(lbLeft_Lenght_Line3->sizePolicy().hasHeightForWidth());
        lbLeft_Lenght_Line3->setSizePolicy(sizePolicy2);
        lbLeft_Lenght_Line3->setMinimumSize(QSize(60, 0));
        lbLeft_Lenght_Line3->setFont(font5);
        lbLeft_Lenght_Line3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbLeft_Lenght_Line3, 2, 1, 1, 1);

        lbRight_Lenght_Line3 = new QLabel(layoutWidget);
        lbRight_Lenght_Line3->setObjectName(QStringLiteral("lbRight_Lenght_Line3"));
        sizePolicy2.setHeightForWidth(lbRight_Lenght_Line3->sizePolicy().hasHeightForWidth());
        lbRight_Lenght_Line3->setSizePolicy(sizePolicy2);
        lbRight_Lenght_Line3->setMinimumSize(QSize(60, 0));
        lbRight_Lenght_Line3->setFont(font5);
        lbRight_Lenght_Line3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbRight_Lenght_Line3, 2, 2, 1, 1);

        label_43 = new QLabel(layoutWidget);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setFont(font4);

        gridLayout->addWidget(label_43, 3, 0, 1, 1);

        lbLeft_Lenght_Line5 = new QLabel(layoutWidget);
        lbLeft_Lenght_Line5->setObjectName(QStringLiteral("lbLeft_Lenght_Line5"));
        sizePolicy2.setHeightForWidth(lbLeft_Lenght_Line5->sizePolicy().hasHeightForWidth());
        lbLeft_Lenght_Line5->setSizePolicy(sizePolicy2);
        lbLeft_Lenght_Line5->setMinimumSize(QSize(60, 0));
        lbLeft_Lenght_Line5->setFont(font5);
        lbLeft_Lenght_Line5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbLeft_Lenght_Line5, 3, 1, 1, 1);

        lbRight_Lenght_Line5 = new QLabel(layoutWidget);
        lbRight_Lenght_Line5->setObjectName(QStringLiteral("lbRight_Lenght_Line5"));
        sizePolicy2.setHeightForWidth(lbRight_Lenght_Line5->sizePolicy().hasHeightForWidth());
        lbRight_Lenght_Line5->setSizePolicy(sizePolicy2);
        lbRight_Lenght_Line5->setMinimumSize(QSize(60, 0));
        lbRight_Lenght_Line5->setFont(font5);
        lbRight_Lenght_Line5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbRight_Lenght_Line5, 3, 2, 1, 1);

        label_48 = new QLabel(layoutWidget);
        label_48->setObjectName(QStringLiteral("label_48"));
        label_48->setFont(font4);
        label_48->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(label_48, 4, 0, 1, 1);

        lbLeft_Lenght_Vertical = new QLabel(layoutWidget);
        lbLeft_Lenght_Vertical->setObjectName(QStringLiteral("lbLeft_Lenght_Vertical"));
        sizePolicy2.setHeightForWidth(lbLeft_Lenght_Vertical->sizePolicy().hasHeightForWidth());
        lbLeft_Lenght_Vertical->setSizePolicy(sizePolicy2);
        lbLeft_Lenght_Vertical->setMinimumSize(QSize(60, 0));
        lbLeft_Lenght_Vertical->setFont(font5);
        lbLeft_Lenght_Vertical->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbLeft_Lenght_Vertical, 4, 1, 1, 1);

        lbRight_Lenght_Vertical = new QLabel(layoutWidget);
        lbRight_Lenght_Vertical->setObjectName(QStringLiteral("lbRight_Lenght_Vertical"));
        sizePolicy2.setHeightForWidth(lbRight_Lenght_Vertical->sizePolicy().hasHeightForWidth());
        lbRight_Lenght_Vertical->setSizePolicy(sizePolicy2);
        lbRight_Lenght_Vertical->setMinimumSize(QSize(60, 0));
        lbRight_Lenght_Vertical->setFont(font5);
        lbRight_Lenght_Vertical->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbRight_Lenght_Vertical, 4, 2, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font4);

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        lbLeft_Angle_L1_L2 = new QLabel(layoutWidget);
        lbLeft_Angle_L1_L2->setObjectName(QStringLiteral("lbLeft_Angle_L1_L2"));
        sizePolicy2.setHeightForWidth(lbLeft_Angle_L1_L2->sizePolicy().hasHeightForWidth());
        lbLeft_Angle_L1_L2->setSizePolicy(sizePolicy2);
        lbLeft_Angle_L1_L2->setMinimumSize(QSize(60, 0));
        lbLeft_Angle_L1_L2->setFont(font5);
        lbLeft_Angle_L1_L2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbLeft_Angle_L1_L2, 5, 1, 1, 1);

        lbRight_Angle_L1_L2 = new QLabel(layoutWidget);
        lbRight_Angle_L1_L2->setObjectName(QStringLiteral("lbRight_Angle_L1_L2"));
        sizePolicy2.setHeightForWidth(lbRight_Angle_L1_L2->sizePolicy().hasHeightForWidth());
        lbRight_Angle_L1_L2->setSizePolicy(sizePolicy2);
        lbRight_Angle_L1_L2->setMinimumSize(QSize(60, 0));
        lbRight_Angle_L1_L2->setFont(font5);
        lbRight_Angle_L1_L2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbRight_Angle_L1_L2, 5, 2, 1, 1);

        label_44 = new QLabel(layoutWidget);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setFont(font4);

        gridLayout->addWidget(label_44, 6, 0, 1, 1);

        lbLeft_Angle_Upper = new QLabel(layoutWidget);
        lbLeft_Angle_Upper->setObjectName(QStringLiteral("lbLeft_Angle_Upper"));
        sizePolicy2.setHeightForWidth(lbLeft_Angle_Upper->sizePolicy().hasHeightForWidth());
        lbLeft_Angle_Upper->setSizePolicy(sizePolicy2);
        lbLeft_Angle_Upper->setMinimumSize(QSize(60, 0));
        lbLeft_Angle_Upper->setFont(font5);
        lbLeft_Angle_Upper->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbLeft_Angle_Upper, 6, 1, 1, 1);

        lbRight_Angle_Upper = new QLabel(layoutWidget);
        lbRight_Angle_Upper->setObjectName(QStringLiteral("lbRight_Angle_Upper"));
        sizePolicy2.setHeightForWidth(lbRight_Angle_Upper->sizePolicy().hasHeightForWidth());
        lbRight_Angle_Upper->setSizePolicy(sizePolicy2);
        lbRight_Angle_Upper->setMinimumSize(QSize(60, 0));
        lbRight_Angle_Upper->setFont(font5);
        lbRight_Angle_Upper->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbRight_Angle_Upper, 6, 2, 1, 1);

        label_50 = new QLabel(layoutWidget);
        label_50->setObjectName(QStringLiteral("label_50"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        label_50->setPalette(palette);
        label_50->setFont(font4);
        label_50->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(label_50, 7, 0, 1, 1);

        lbLeft_Distance = new QLabel(layoutWidget);
        lbLeft_Distance->setObjectName(QStringLiteral("lbLeft_Distance"));
        sizePolicy2.setHeightForWidth(lbLeft_Distance->sizePolicy().hasHeightForWidth());
        lbLeft_Distance->setSizePolicy(sizePolicy2);
        lbLeft_Distance->setMinimumSize(QSize(60, 0));
        QPalette palette1;
        QBrush brush2(QColor(0, 0, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        lbLeft_Distance->setPalette(palette1);
        lbLeft_Distance->setFont(font5);
        lbLeft_Distance->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbLeft_Distance, 7, 1, 1, 1);

        lbRight_Distance = new QLabel(layoutWidget);
        lbRight_Distance->setObjectName(QStringLiteral("lbRight_Distance"));
        sizePolicy2.setHeightForWidth(lbRight_Distance->sizePolicy().hasHeightForWidth());
        lbRight_Distance->setSizePolicy(sizePolicy2);
        lbRight_Distance->setMinimumSize(QSize(60, 0));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        lbRight_Distance->setPalette(palette2);
        lbRight_Distance->setFont(font5);
        lbRight_Distance->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbRight_Distance, 7, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer_11 = new QSpacerItem(197, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_11);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_28 = new QLabel(layoutWidget);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setFont(font4);

        gridLayout_2->addWidget(label_28, 0, 0, 1, 1);

        lbFrontLeftFootWeight = new QLabel(layoutWidget);
        lbFrontLeftFootWeight->setObjectName(QStringLiteral("lbFrontLeftFootWeight"));
        sizePolicy2.setHeightForWidth(lbFrontLeftFootWeight->sizePolicy().hasHeightForWidth());
        lbFrontLeftFootWeight->setSizePolicy(sizePolicy2);
        lbFrontLeftFootWeight->setMinimumSize(QSize(70, 0));
        lbFrontLeftFootWeight->setFont(font5);

        gridLayout_2->addWidget(lbFrontLeftFootWeight, 0, 1, 1, 1);

        label_29 = new QLabel(layoutWidget);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setFont(font4);

        gridLayout_2->addWidget(label_29, 1, 0, 1, 1);

        lbBackLeftFootWeight = new QLabel(layoutWidget);
        lbBackLeftFootWeight->setObjectName(QStringLiteral("lbBackLeftFootWeight"));
        sizePolicy2.setHeightForWidth(lbBackLeftFootWeight->sizePolicy().hasHeightForWidth());
        lbBackLeftFootWeight->setSizePolicy(sizePolicy2);
        lbBackLeftFootWeight->setMinimumSize(QSize(70, 0));
        lbBackLeftFootWeight->setFont(font5);

        gridLayout_2->addWidget(lbBackLeftFootWeight, 1, 1, 1, 1);

        label_30 = new QLabel(layoutWidget);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setFont(font4);

        gridLayout_2->addWidget(label_30, 2, 0, 1, 1);

        lbFrontRightFootWeight = new QLabel(layoutWidget);
        lbFrontRightFootWeight->setObjectName(QStringLiteral("lbFrontRightFootWeight"));
        sizePolicy2.setHeightForWidth(lbFrontRightFootWeight->sizePolicy().hasHeightForWidth());
        lbFrontRightFootWeight->setSizePolicy(sizePolicy2);
        lbFrontRightFootWeight->setMinimumSize(QSize(70, 0));
        lbFrontRightFootWeight->setFont(font5);

        gridLayout_2->addWidget(lbFrontRightFootWeight, 2, 1, 1, 1);

        label_31 = new QLabel(layoutWidget);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setFont(font4);

        gridLayout_2->addWidget(label_31, 3, 0, 1, 1);

        lbBackRightFootWeight = new QLabel(layoutWidget);
        lbBackRightFootWeight->setObjectName(QStringLiteral("lbBackRightFootWeight"));
        sizePolicy2.setHeightForWidth(lbBackRightFootWeight->sizePolicy().hasHeightForWidth());
        lbBackRightFootWeight->setSizePolicy(sizePolicy2);
        lbBackRightFootWeight->setMinimumSize(QSize(70, 0));
        lbBackRightFootWeight->setFont(font5);

        gridLayout_2->addWidget(lbBackRightFootWeight, 3, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        verticalSpacer_10 = new QSpacerItem(197, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_10);

        pbSaveAnalysisResults = new QPushButton(layoutWidget);
        pbSaveAnalysisResults->setObjectName(QStringLiteral("pbSaveAnalysisResults"));
        pbSaveAnalysisResults->setMinimumSize(QSize(200, 30));
        pbSaveAnalysisResults->setMaximumSize(QSize(200, 16777215));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/MainWindow/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSaveAnalysisResults->setIcon(icon5);

        verticalLayout_2->addWidget(pbSaveAnalysisResults);

        verticalSpacer_7 = new QSpacerItem(197, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_7);

        commandPicture = new ImgView(layoutWidget);
        commandPicture->setObjectName(QStringLiteral("commandPicture"));
        commandPicture->setEnabled(true);
        commandPicture->setMinimumSize(QSize(176, 176));
        commandPicture->setMaximumSize(QSize(200, 16777215));
        commandPicture->setFont(font3);
        commandPicture->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(commandPicture);


        horizontalLayout_3->addLayout(verticalLayout_2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_8 = new QGridLayout(tab_3);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        treeView = new QTreeView(tab_3);
        treeView->setObjectName(QStringLiteral("treeView"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy3);
        treeView->setMinimumSize(QSize(600, 400));
        treeView->setMaximumSize(QSize(400, 16777215));

        verticalLayout_22->addWidget(treeView);

        listView2 = new QListView(tab_3);
        listView2->setObjectName(QStringLiteral("listView2"));
        listView2->setMinimumSize(QSize(600, 0));
        listView2->setMaximumSize(QSize(710, 16777215));
        listView2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView2->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout_22->addWidget(listView2);


        horizontalLayout_19->addLayout(verticalLayout_22);

        horizontalSpacer_12 = new QSpacerItem(50, 77, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_12);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        groupBox_2 = new QGroupBox(tab_3);
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
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        leUserName = new QLineEdit(groupBox_2);
        leUserName->setObjectName(QStringLiteral("leUserName"));
        leUserName->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, leUserName);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_7);

        lePassword = new QLineEdit(groupBox_2);
        lePassword->setObjectName(QStringLiteral("lePassword"));
        lePassword->setFont(font);
        lePassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lePassword);

        ckShowPassword = new QCheckBox(groupBox_2);
        ckShowPassword->setObjectName(QStringLiteral("ckShowPassword"));
        ckShowPassword->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, ckShowPassword);


        verticalLayout_23->addWidget(groupBox_2);

        pbConnectServer = new QPushButton(tab_3);
        pbConnectServer->setObjectName(QStringLiteral("pbConnectServer"));
        pbConnectServer->setMinimumSize(QSize(200, 30));

        verticalLayout_23->addWidget(pbConnectServer);

        pbUploadFiles = new QPushButton(tab_3);
        pbUploadFiles->setObjectName(QStringLiteral("pbUploadFiles"));
        pbUploadFiles->setMinimumSize(QSize(200, 30));

        verticalLayout_23->addWidget(pbUploadFiles);

        verticalSpacer_3 = new QSpacerItem(122, 378, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_23->addItem(verticalSpacer_3);


        horizontalLayout_19->addLayout(verticalLayout_23);


        gridLayout_8->addLayout(horizontalLayout_19, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(434, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_6 = new QGridLayout(tab_5);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox = new QGroupBox(tab_5);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(350, 0));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 101, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 101, 21));
        cbLeftScanner = new QComboBox(groupBox);
        cbLeftScanner->setObjectName(QStringLiteral("cbLeftScanner"));
        cbLeftScanner->setGeometry(QRect(140, 40, 181, 22));
        cbRightScanner = new QComboBox(groupBox);
        cbRightScanner->setObjectName(QStringLiteral("cbRightScanner"));
        cbRightScanner->setGeometry(QRect(140, 90, 181, 22));
        lbLeftImageScale = new QLabel(groupBox);
        lbLeftImageScale->setObjectName(QStringLiteral("lbLeftImageScale"));
        lbLeftImageScale->setGeometry(QRect(170, 140, 81, 21));
        QFont font7;
        font7.setPointSize(12);
        lbLeftImageScale->setFont(font7);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 170, 141, 21));
        label_8->setFont(font4);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 140, 141, 21));
        label_9->setFont(font4);
        lbRightImageScale = new QLabel(groupBox);
        lbRightImageScale->setObjectName(QStringLiteral("lbRightImageScale"));
        lbRightImageScale->setGeometry(QRect(170, 170, 81, 21));
        lbRightImageScale->setFont(font7);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 230, 141, 21));
        label_10->setFont(font4);
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 200, 141, 21));
        label_11->setFont(font4);
        leLeftScannerScale = new QLineEdit(groupBox);
        leLeftScannerScale->setObjectName(QStringLiteral("leLeftScannerScale"));
        leLeftScannerScale->setGeometry(QRect(160, 200, 61, 21));
        QFont font8;
        font8.setPointSize(12);
        font8.setBold(false);
        font8.setWeight(50);
        leLeftScannerScale->setFont(font8);
        leRightScannerScale = new QLineEdit(groupBox);
        leRightScannerScale->setObjectName(QStringLiteral("leRightScannerScale"));
        leRightScannerScale->setGeometry(QRect(160, 230, 61, 21));
        leRightScannerScale->setFont(font8);
        pbSaveScannerSetting = new QPushButton(groupBox);
        pbSaveScannerSetting->setObjectName(QStringLiteral("pbSaveScannerSetting"));
        pbSaveScannerSetting->setGeometry(QRect(20, 390, 150, 30));
        pbSaveScannerSetting->setMinimumSize(QSize(150, 30));
        pbSaveScannerSetting->setMaximumSize(QSize(150, 30));

        gridLayout_6->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(tab_5);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        ivWebcamera = new ImgView(groupBox_3);
        ivWebcamera->setObjectName(QStringLiteral("ivWebcamera"));
        ivWebcamera->setGeometry(QRect(20, 50, 198, 131));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(ivWebcamera->sizePolicy().hasHeightForWidth());
        ivWebcamera->setSizePolicy(sizePolicy4);
        ivWebcamera->setFont(font3);
        ivWebcamera->setAlignment(Qt::AlignCenter);
        cbWebcamSelect = new QComboBox(groupBox_3);
        cbWebcamSelect->setObjectName(QStringLiteral("cbWebcamSelect"));
        cbWebcamSelect->setGeometry(QRect(30, 190, 181, 22));
        pbSetUpperWebcam = new QPushButton(groupBox_3);
        pbSetUpperWebcam->setObjectName(QStringLiteral("pbSetUpperWebcam"));
        pbSetUpperWebcam->setGeometry(QRect(230, 60, 101, 23));
        pbSetSideWebcam = new QPushButton(groupBox_3);
        pbSetSideWebcam->setObjectName(QStringLiteral("pbSetSideWebcam"));
        pbSetSideWebcam->setGeometry(QRect(230, 90, 101, 23));
        pbReSetWebcam = new QPushButton(groupBox_3);
        pbReSetWebcam->setObjectName(QStringLiteral("pbReSetWebcam"));
        pbReSetWebcam->setGeometry(QRect(240, 190, 91, 23));
        pbReSetWebcam->setStyleSheet(QLatin1String("QPushButton{\n"
"   \n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../../../FootShapeAnalysis/FootShapeAnalysis/reload.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pbReSetWebcam->setIcon(icon6);
        pbReSetWebcam->setIconSize(QSize(20, 20));
        ivWebcamera->raise();
        cbWebcamSelect->raise();
        pbSetUpperWebcam->raise();
        pbSetSideWebcam->raise();
        pbReSetWebcam->raise();

        gridLayout_6->addWidget(groupBox_3, 0, 1, 1, 1);

        groupBox_LoadCell = new QGroupBox(tab_5);
        groupBox_LoadCell->setObjectName(QStringLiteral("groupBox_LoadCell"));
        groupBox_LoadCell->setMinimumSize(QSize(300, 450));
        ckEnabled = new QCheckBox(groupBox_LoadCell);
        ckEnabled->setObjectName(QStringLiteral("ckEnabled"));
        ckEnabled->setGeometry(QRect(40, 70, 70, 17));
        ckEnabled->setFont(font);
        label_18 = new QLabel(groupBox_LoadCell);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(50, 293, 51, 16));
        label_18->setFont(font);
        leFormula = new QLineEdit(groupBox_LoadCell);
        leFormula->setObjectName(QStringLiteral("leFormula"));
        leFormula->setGeometry(QRect(80, 360, 231, 20));
        leFormula->setFont(font);
        leFormula->setReadOnly(true);
        label_20 = new QLabel(groupBox_LoadCell);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(170, 70, 31, 16));
        label_20->setFont(font);
        label_21 = new QLabel(groupBox_LoadCell);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(50, 323, 51, 16));
        label_21->setFont(font);
        pbBridgeCalib = new QPushButton(groupBox_LoadCell);
        pbBridgeCalib->setObjectName(QStringLiteral("pbBridgeCalib"));
        pbBridgeCalib->setGeometry(QRect(7, 130, 101, 23));
        pbBridgeCalib->setFont(font);
        leRate = new QLineEdit(groupBox_LoadCell);
        leRate->setObjectName(QStringLiteral("leRate"));
        leRate->setGeometry(QRect(240, 390, 41, 20));
        leRate->setFont(font);
        leRate->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(groupBox_LoadCell);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(50, 263, 51, 16));
        label_22->setFont(font);
        leValue_4 = new QLineEdit(groupBox_LoadCell);
        leValue_4->setObjectName(QStringLiteral("leValue_4"));
        leValue_4->setGeometry(QRect(100, 323, 81, 20));
        leValue_4->setFont(font);
        leValue_4->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(groupBox_LoadCell);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(30, 360, 51, 16));
        label_23->setFont(font);
        leValue_3 = new QLineEdit(groupBox_LoadCell);
        leValue_3->setObjectName(QStringLiteral("leValue_3"));
        leValue_3->setGeometry(QRect(100, 293, 81, 20));
        leValue_3->setFont(font);
        leValue_3->setAlignment(Qt::AlignCenter);
        leValue_2 = new QLineEdit(groupBox_LoadCell);
        leValue_2->setObjectName(QStringLiteral("leValue_2"));
        leValue_2->setGeometry(QRect(100, 263, 81, 20));
        leValue_2->setFont(font);
        leValue_2->setAlignment(Qt::AlignCenter);
        cbBridgeGains = new QComboBox(groupBox_LoadCell);
        cbBridgeGains->setObjectName(QStringLiteral("cbBridgeGains"));
        cbBridgeGains->setGeometry(QRect(200, 70, 51, 21));
        cbBridgeGains->setFont(font);
        label_24 = new QLabel(groupBox_LoadCell);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(30, 390, 51, 16));
        label_24->setFont(font);
        label_26 = new QLabel(groupBox_LoadCell);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(50, 233, 51, 16));
        label_26->setFont(font);
        leValue_1 = new QLineEdit(groupBox_LoadCell);
        leValue_1->setObjectName(QStringLiteral("leValue_1"));
        leValue_1->setGeometry(QRect(100, 233, 81, 20));
        leValue_1->setFont(font);
        leValue_1->setAlignment(Qt::AlignCenter);
        slRate = new QSlider(groupBox_LoadCell);
        slRate->setObjectName(QStringLiteral("slRate"));
        slRate->setGeometry(QRect(80, 390, 151, 22));
        slRate->setFont(font);
        slRate->setMinimum(8);
        slRate->setMaximum(1000);
        slRate->setValue(200);
        slRate->setOrientation(Qt::Horizontal);
        slRate->setTickPosition(QSlider::TicksBelow);
        pbSaveBridgeSetting = new QPushButton(groupBox_LoadCell);
        pbSaveBridgeSetting->setObjectName(QStringLiteral("pbSaveBridgeSetting"));
        pbSaveBridgeSetting->setGeometry(QRect(20, 430, 120, 30));
        pbSaveBridgeSetting->setMinimumSize(QSize(120, 30));
        pbSaveBridgeSetting->setMaximumSize(QSize(120, 30));
        leValue_5 = new QLineEdit(groupBox_LoadCell);
        leValue_5->setObjectName(QStringLiteral("leValue_5"));
        leValue_5->setEnabled(false);
        leValue_5->setGeometry(QRect(100, 201, 81, 20));
        leValue_5->setFont(font);
        leValue_5->setStyleSheet(QLatin1String("QLineEdit{\n"
"   \n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        leValue_5->setAlignment(Qt::AlignCenter);
        pbSet_5 = new QPushButton(groupBox_LoadCell);
        pbSet_5->setObjectName(QStringLiteral("pbSet_5"));
        pbSet_5->setEnabled(false);
        pbSet_5->setGeometry(QRect(189, 200, 51, 23));
        pbSet_5->setFont(font);
        pbSet_6 = new QPushButton(groupBox_LoadCell);
        pbSet_6->setObjectName(QStringLiteral("pbSet_6"));
        pbSet_6->setEnabled(false);
        pbSet_6->setGeometry(QRect(249, 200, 51, 23));
        pbSet_6->setFont(font);
        label_32 = new QLabel(groupBox_LoadCell);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(9, 200, 91, 20));
        label_32->setFont(font6);

        gridLayout_6->addWidget(groupBox_LoadCell, 0, 2, 1, 1);

        tabWidget->addTab(tab_5, QString());

        horizontalLayout_4->addWidget(tabWidget);


        verticalLayout_7->addLayout(horizontalLayout_4);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1386, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionNewCustomer);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuAbout->addAction(actionAbout);
        menuEdit->addAction(actionCalib_Scale);

        retranslateUi(MainWindowClass);

        tabWidget->setCurrentIndex(4);
        cbWebcamSelect->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0));
        actionExit->setText(QApplication::translate("MainWindowClass", "&Exit", 0));
        actionExit->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+E", 0));
        actionNewCustomer->setText(QApplication::translate("MainWindowClass", "New Customer", 0));
        actionSettings->setText(QApplication::translate("MainWindowClass", "Settings", 0));
        actionAbout->setText(QApplication::translate("MainWindowClass", "About", 0));
        actionCalib_Scale->setText(QApplication::translate("MainWindowClass", "Calib Scale", 0));
        label_40->setText(QApplication::translate("MainWindowClass", "\354\270\241\354\240\225\354\235\274\354\236\220(date):", 0));
        dateEdit->setDisplayFormat(QApplication::translate("MainWindowClass", "yyyy-MM-dd", 0));
        label_33->setText(QApplication::translate("MainWindowClass", "\352\263\240\352\260\235\353\252\205(name):", 0));
        leCustomerName->setText(QApplication::translate("MainWindowClass", "\355\231\215\352\270\270\353\217\231", 0));
        label_39->setText(QApplication::translate("MainWindowClass", "\354\203\235\353\205\204\354\233\224\354\235\274(birth date):", 0));
        dateEdit_2->setDisplayFormat(QApplication::translate("MainWindowClass", "yyyy-MM-dd", 0));
        label_37->setText(QApplication::translate("MainWindowClass", "\354\204\261\353\263\204(sex):", 0));
        label_34->setText(QApplication::translate("MainWindowClass", "\352\270\260\352\264\200\353\252\205(institute):", 0));
        leCenterName->setText(QApplication::translate("MainWindowClass", "\354\225\204\354\202\260\353\263\221\354\233\220", 0));
        label_35->setText(QApplication::translate("MainWindowClass", "\354\213\240\354\236\245(height)[cm]:", 0));
        leCustomerHeight->setText(QApplication::translate("MainWindowClass", "180", 0));
        label_36->setText(QApplication::translate("MainWindowClass", "\354\262\264\354\244\221(weight)[kg]:", 0));
        leCustomerWeight->setText(QApplication::translate("MainWindowClass", "75", 0));
        label_38->setText(QApplication::translate("MainWindowClass", "\354\262\264\354\247\210\353\237\211(B.M. index):", 0));
        leBodyMass->setText(QApplication::translate("MainWindowClass", "7", 0));
        toolButton->setText(QApplication::translate("MainWindowClass", "\354\262\264\355\230\225\354\270\241\354\240\225", 0));
        toolButton->setProperty("ButtonType", QVariant(QApplication::translate("MainWindowClass", "SideButton", 0)));
        toolButton_2->setText(QApplication::translate("MainWindowClass", "\354\241\261\355\230\225\353\266\204\354\204\235", 0));
        toolButton_2->setProperty("ButtonType", QVariant(QApplication::translate("MainWindowClass", "SideButton", 0)));
        toolButton_3->setText(QApplication::translate("MainWindowClass", "\354\227\205\353\241\234\353\223\234", 0));
        toolButton_3->setProperty("ButtonType", QVariant(QApplication::translate("MainWindowClass", "SideButton", 0)));
        toolButton_4->setText(QApplication::translate("MainWindowClass", "\354\240\204\354\206\241\354\203\201\355\203\234", 0));
        toolButton_4->setProperty("ButtonType", QVariant(QApplication::translate("MainWindowClass", "SideButton", 0)));
        toolButton_5->setText(QApplication::translate("MainWindowClass", "Setting", 0));
        toolButton_5->setProperty("ButtonType", QVariant(QApplication::translate("MainWindowClass", "SideButton", 0)));
        ivBodyFrontView->setText(QApplication::translate("MainWindowClass", "\354\240\225\353\251\264\354\215\270\353\204\244\354\235\274", 0));
        ivBodyTopView->setText(QApplication::translate("MainWindowClass", "\354\203\201\354\270\241\354\215\270\353\204\244\354\235\274", 0));
        ivBodySideView->setText(QApplication::translate("MainWindowClass", "\354\270\241\353\251\264\354\215\270\353\204\244\354\235\274", 0));
        ivBodyBackView->setText(QApplication::translate("MainWindowClass", "\355\233\204\353\251\264\354\215\270\353\204\244\354\235\274", 0));
        ivBodyCameraViews->setText(QApplication::translate("MainWindowClass", "Body Camera Views", 0));
        pbSelectUpperCamera->setText(QApplication::translate("MainWindowClass", "\354\203\201\353\251\264\354\271\264\353\251\224\353\235\274 \354\204\240\355\203\235", 0));
        pbUpperCapture->setText(QApplication::translate("MainWindowClass", "\354\203\201\353\251\264 \354\270\241\354\240\225", 0));
        pbSelectBodyCamera->setText(QApplication::translate("MainWindowClass", "\354\240\225\353\251\264\354\271\264\353\251\224\353\235\274 \354\204\240\355\203\235", 0));
        pbFrontCapture->setText(QApplication::translate("MainWindowClass", "\354\240\225\353\251\264 \354\270\241\354\240\225", 0));
        pbSideCapture->setText(QApplication::translate("MainWindowClass", "\354\270\241\353\251\264 \354\270\241\354\240\225", 0));
        pbBackCapture->setText(QApplication::translate("MainWindowClass", "\355\233\204 \353\251\264 \354\270\241\354\240\225", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindowClass", "\354\262\264\355\230\225\354\270\241\354\240\225", 0));
        ivLeftAnalysisImage->setText(QApplication::translate("MainWindowClass", "\354\231\274\353\260\234 (\355\212\271\354\247\225\354\240\220)", 0));
        ivRightAnalysisImage->setText(QApplication::translate("MainWindowClass", "\354\230\244\353\245\270\353\260\234 (\355\212\271\354\247\225\354\240\220)", 0));
        ivLeftDetectImage->setText(QApplication::translate("MainWindowClass", "\354\231\274\353\260\234 (\355\225\230\354\244\221\354\240\220)", 0));
        ivRightDetectImage->setText(QApplication::translate("MainWindowClass", "\354\230\244\353\245\270\353\260\234 (\355\225\230\354\244\221\354\240\220)", 0));
        pbLeftScan->setText(QApplication::translate("MainWindowClass", "Foot Scan", 0));
        pbOldCustomer->setText(QApplication::translate("MainWindowClass", "ReLoad", 0));
#ifndef QT_NO_TOOLTIP
        tbLeftFootReload->setToolTip(QApplication::translate("MainWindowClass", "Reload", 0));
#endif // QT_NO_TOOLTIP
        tbLeftFootReload->setText(QApplication::translate("MainWindowClass", "...", 0));
        radioButton_left->setText(QApplication::translate("MainWindowClass", "Left", 0));
        radioButton_left_foot_mearsure->setText(QApplication::translate("MainWindowClass", "Distance", 0));
#ifndef QT_NO_TOOLTIP
        tbLeftFootDetect->setToolTip(QApplication::translate("MainWindowClass", "Detect", 0));
#endif // QT_NO_TOOLTIP
        tbLeftFootDetect->setText(QApplication::translate("MainWindowClass", "...", 0));
#ifndef QT_NO_TOOLTIP
        tbRightFootReload->setToolTip(QApplication::translate("MainWindowClass", "Reload", 0));
#endif // QT_NO_TOOLTIP
        tbRightFootReload->setText(QApplication::translate("MainWindowClass", "...", 0));
        radioButton_right->setText(QApplication::translate("MainWindowClass", "Right", 0));
        radioButton_right_foot_mearsure->setText(QApplication::translate("MainWindowClass", "Distance", 0));
#ifndef QT_NO_TOOLTIP
        tbRightFootDetect->setToolTip(QApplication::translate("MainWindowClass", "Detect", 0));
#endif // QT_NO_TOOLTIP
        tbRightFootDetect->setText(QApplication::translate("MainWindowClass", "...", 0));
        label_49->setText(QApplication::translate("MainWindowClass", "\355\225\255\353\252\251", 0));
        label_46->setText(QApplication::translate("MainWindowClass", "\354\231\274\353\260\234", 0));
        label_47->setText(QApplication::translate("MainWindowClass", "\354\230\244\353\245\270\353\260\234", 0));
        label_42->setText(QApplication::translate("MainWindowClass", "\353\260\234 \352\270\270\354\235\264 [cm]:", 0));
        lbLeft_Lenght_Line4->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        lbRight_Lenght_Line4->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_41->setText(QApplication::translate("MainWindowClass", "\353\260\234 \353\202\230\353\271\204 [cm]:", 0));
        lbLeft_Lenght_Line3->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        lbRight_Lenght_Line3->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_43->setText(QApplication::translate("MainWindowClass", "\353\260\234 \353\222\244\352\277\210\354\271\230 \353\202\230\353\271\204 [cm]:", 0));
        lbLeft_Lenght_Line5->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        lbRight_Lenght_Line5->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_48->setText(QApplication::translate("MainWindowClass", "Shell \352\270\270\354\235\264 [cm]:", 0));
        lbLeft_Lenght_Vertical->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        lbRight_Lenght_Vertical->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_5->setText(QApplication::translate("MainWindowClass", "\354\227\204\354\247\200\353\260\234\352\260\200\353\235\275 \352\260\201\353\217\204[deg]:", 0));
        lbLeft_Angle_L1_L2->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        lbRight_Angle_L1_L2->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_44->setText(QApplication::translate("MainWindowClass", "\354\241\260\354\235\270\355\212\270 \352\260\201\353\217\204 [deg]:", 0));
        lbLeft_Angle_Upper->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        lbRight_Angle_Upper->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_50->setText(QApplication::translate("MainWindowClass", "\354\266\224\352\260\200\352\270\270\354\235\264 [cm]:", 0));
        lbLeft_Distance->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        lbRight_Distance->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_28->setText(QApplication::translate("MainWindowClass", "\354\231\274\353\260\234 \354\225\236\354\252\275 \355\225\230\354\244\221 \353\266\204\355\217\254 [%]:", 0));
        lbFrontLeftFootWeight->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_29->setText(QApplication::translate("MainWindowClass", "\354\231\274\353\260\234 \353\222\267\352\277\210\354\271\230 \355\225\230\354\244\221 \353\266\204\355\217\254 [%]:", 0));
        lbBackLeftFootWeight->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_30->setText(QApplication::translate("MainWindowClass", "\354\230\244\353\245\270\353\260\234 \354\225\236\354\252\275 \355\225\230\354\244\221 \353\266\204\355\217\254 [%]:", 0));
        lbFrontRightFootWeight->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        label_31->setText(QApplication::translate("MainWindowClass", "\354\230\244\353\245\270\353\260\234 \353\222\267\352\277\210\354\271\230 \355\225\230\354\244\221 \353\266\204\355\217\254 [%]:", 0));
        lbBackRightFootWeight->setText(QApplication::translate("MainWindowClass", "0.000", 0));
        pbSaveAnalysisResults->setText(QApplication::translate("MainWindowClass", "Save Analysis Results", 0));
        commandPicture->setText(QApplication::translate("MainWindowClass", "command picture", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindowClass", "\354\241\261\355\230\225\353\266\204\354\204\235", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindowClass", "Login", 0));
        label_6->setText(QApplication::translate("MainWindowClass", "User name:", 0));
        label_7->setText(QApplication::translate("MainWindowClass", "Password:", 0));
        ckShowPassword->setText(QApplication::translate("MainWindowClass", "Show password", 0));
        pbConnectServer->setText(QApplication::translate("MainWindowClass", "Connect Server", 0));
        pbUploadFiles->setText(QApplication::translate("MainWindowClass", "Upload Files...", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindowClass", "\354\227\205\353\241\234\353\223\234", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindowClass", "\354\240\204\354\206\241\354\203\201\355\203\234", 0));
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
        groupBox_3->setTitle(QApplication::translate("MainWindowClass", "Web cameras", 0));
        ivWebcamera->setText(QApplication::translate("MainWindowClass", "Web camera", 0));
        pbSetUpperWebcam->setText(QApplication::translate("MainWindowClass", "Upper View", 0));
        pbSetSideWebcam->setText(QApplication::translate("MainWindowClass", "Front View", 0));
        pbReSetWebcam->setText(QApplication::translate("MainWindowClass", "Undo", 0));
        groupBox_LoadCell->setTitle(QApplication::translate("MainWindowClass", "Load Cells", 0));
        ckEnabled->setText(QApplication::translate("MainWindowClass", "Enabled", 0));
        label_18->setText(QApplication::translate("MainWindowClass", "Value 3:", 0));
        label_20->setText(QApplication::translate("MainWindowClass", "Gain:", 0));
        label_21->setText(QApplication::translate("MainWindowClass", "Value 4:", 0));
        pbBridgeCalib->setText(QApplication::translate("MainWindowClass", "Start Calibration", 0));
        leRate->setText(QApplication::translate("MainWindowClass", "200", 0));
        label_22->setText(QApplication::translate("MainWindowClass", "Value 2:", 0));
        label_23->setText(QApplication::translate("MainWindowClass", "Formula:", 0));
        label_24->setText(QApplication::translate("MainWindowClass", "Rate:", 0));
        label_26->setText(QApplication::translate("MainWindowClass", "Value 1:", 0));
        pbSaveBridgeSetting->setText(QApplication::translate("MainWindowClass", "Save Bridge Setting", 0));
        pbSet_5->setText(QApplication::translate("MainWindowClass", "Push", 0));
        pbSet_6->setText(QApplication::translate("MainWindowClass", "Pop", 0));
        label_32->setText(QApplication::translate("MainWindowClass", "Times Saved", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindowClass", "Setting", 0));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", 0));
        menuAbout->setTitle(QApplication::translate("MainWindowClass", "About", 0));
        menuEdit->setTitle(QApplication::translate("MainWindowClass", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
