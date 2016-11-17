/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[100];
    char stringdata[2277];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 27), // "sig_left_scanner_id_changed"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 3), // "idx"
QT_MOC_LITERAL(4, 44, 28), // "sig_right_scanner_id_changed"
QT_MOC_LITERAL(5, 73, 11), // "test_signal"
QT_MOC_LITERAL(6, 85, 14), // "measuring_left"
QT_MOC_LITERAL(7, 100, 15), // "measuring_right"
QT_MOC_LITERAL(8, 116, 13), // "distance_left"
QT_MOC_LITERAL(9, 130, 14), // "distance_right"
QT_MOC_LITERAL(10, 145, 21), // "on_toolButton_clicked"
QT_MOC_LITERAL(11, 167, 23), // "on_toolButton_2_clicked"
QT_MOC_LITERAL(12, 191, 23), // "on_toolButton_3_clicked"
QT_MOC_LITERAL(13, 215, 23), // "on_toolButton_4_clicked"
QT_MOC_LITERAL(14, 239, 23), // "on_toolButton_5_clicked"
QT_MOC_LITERAL(15, 263, 25), // "on_scanner_status_changed"
QT_MOC_LITERAL(16, 289, 3), // "msg"
QT_MOC_LITERAL(17, 293, 16), // "on_scanner_error"
QT_MOC_LITERAL(18, 310, 25), // "on_scanner_image_captured"
QT_MOC_LITERAL(19, 336, 7), // "cv::Mat"
QT_MOC_LITERAL(20, 344, 30), // "on_actionNewCustomer_triggered"
QT_MOC_LITERAL(21, 375, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(22, 399, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(23, 424, 30), // "on_actionCalib_Scale_triggered"
QT_MOC_LITERAL(24, 455, 28), // "on_pbBodyMeasurement_clicked"
QT_MOC_LITERAL(25, 484, 25), // "on_pbFootAnalysis_clicked"
QT_MOC_LITERAL(26, 510, 19), // "on_pbUpload_clicked"
QT_MOC_LITERAL(27, 530, 21), // "on_pbSettings_clicked"
QT_MOC_LITERAL(28, 552, 17), // "on_updateSettings"
QT_MOC_LITERAL(29, 570, 30), // "on_pbSelectUpperCamera_clicked"
QT_MOC_LITERAL(30, 601, 29), // "on_pbSelectBodyCamera_clicked"
QT_MOC_LITERAL(31, 631, 25), // "on_pbUpperCapture_clicked"
QT_MOC_LITERAL(32, 657, 25), // "on_pbFrontCapture_clicked"
QT_MOC_LITERAL(33, 683, 24), // "on_pbBackCapture_clicked"
QT_MOC_LITERAL(34, 708, 24), // "on_pbSideCapture_clicked"
QT_MOC_LITERAL(35, 733, 12), // "on_webcamera"
QT_MOC_LITERAL(36, 746, 27), // "on_cbWebcamSelect_activated"
QT_MOC_LITERAL(37, 774, 27), // "on_pbSetUpperWebcam_clicked"
QT_MOC_LITERAL(38, 802, 26), // "on_pbSetSideWebcam_clicked"
QT_MOC_LITERAL(39, 829, 24), // "on_pbReSetWebcam_clicked"
QT_MOC_LITERAL(40, 854, 33), // "on_pbReloadScannerDrivers_cli..."
QT_MOC_LITERAL(41, 888, 21), // "on_pbLeftScan_clicked"
QT_MOC_LITERAL(42, 910, 22), // "on_pbRightScan_clicked"
QT_MOC_LITERAL(43, 933, 28), // "on_tbLeftFootMeasure_clicked"
QT_MOC_LITERAL(44, 962, 29), // "on_tbRightFootMeasure_clicked"
QT_MOC_LITERAL(45, 992, 11), // "on_leftDraw"
QT_MOC_LITERAL(46, 1004, 12), // "on_rightDraw"
QT_MOC_LITERAL(47, 1017, 30), // "on_pbSelectFootScanner_clicked"
QT_MOC_LITERAL(48, 1048, 29), // "on_pbFootPrintCapture_clicked"
QT_MOC_LITERAL(49, 1078, 26), // "on_cbLeftScanner_activated"
QT_MOC_LITERAL(50, 1105, 27), // "on_cbRightScanner_activated"
QT_MOC_LITERAL(51, 1133, 37), // "on_leLeftScannerScale_editing..."
QT_MOC_LITERAL(52, 1171, 38), // "on_leRightScannerScale_editin..."
QT_MOC_LITERAL(53, 1210, 31), // "on_pbSaveScannerSetting_clicked"
QT_MOC_LITERAL(54, 1242, 27), // "on_tbLeftFootReload_clicked"
QT_MOC_LITERAL(55, 1270, 28), // "on_tbRightFootReload_clicked"
QT_MOC_LITERAL(56, 1299, 27), // "on_tbLeftFootDetect_clicked"
QT_MOC_LITERAL(57, 1327, 28), // "on_tbRightFootDetect_clicked"
QT_MOC_LITERAL(58, 1356, 25), // "on_tbLeftFootSave_clicked"
QT_MOC_LITERAL(59, 1382, 26), // "on_tbRightFootSave_clicked"
QT_MOC_LITERAL(60, 1409, 13), // "on_leftDetect"
QT_MOC_LITERAL(61, 1423, 14), // "on_rightDetect"
QT_MOC_LITERAL(62, 1438, 32), // "on_pbSaveAnalysisResults_clicked"
QT_MOC_LITERAL(63, 1471, 26), // "on_pbConnectServer_clicked"
QT_MOC_LITERAL(64, 1498, 19), // "on_treeView_clicked"
QT_MOC_LITERAL(65, 1518, 5), // "index"
QT_MOC_LITERAL(66, 1524, 23), // "on_pbMakeFolder_clicked"
QT_MOC_LITERAL(67, 1548, 24), // "on_pbUploadFiles_clicked"
QT_MOC_LITERAL(68, 1573, 28), // "on_pbSetSystemFolder_clicked"
QT_MOC_LITERAL(69, 1602, 30), // "on_ckShowPassword_stateChanged"
QT_MOC_LITERAL(70, 1633, 9), // "on_bridge"
QT_MOC_LITERAL(71, 1643, 14), // "on_bridgeCalib"
QT_MOC_LITERAL(72, 1658, 22), // "on_cbBridges_activated"
QT_MOC_LITERAL(73, 1681, 26), // "on_cbBridgeGains_activated"
QT_MOC_LITERAL(74, 1708, 25), // "on_ckEnabled_stateChanged"
QT_MOC_LITERAL(75, 1734, 22), // "on_slRate_valueChanged"
QT_MOC_LITERAL(76, 1757, 25), // "on_leRate_editingFinished"
QT_MOC_LITERAL(77, 1783, 24), // "on_pbBridgeCalib_clicked"
QT_MOC_LITERAL(78, 1808, 18), // "on_pbSet_1_clicked"
QT_MOC_LITERAL(79, 1827, 18), // "on_pbSet_2_clicked"
QT_MOC_LITERAL(80, 1846, 18), // "on_pbSet_3_clicked"
QT_MOC_LITERAL(81, 1865, 18), // "on_pbSet_4_clicked"
QT_MOC_LITERAL(82, 1884, 30), // "on_pbSaveBridgeSetting_clicked"
QT_MOC_LITERAL(83, 1915, 25), // "on_pbReloadBridge_clicked"
QT_MOC_LITERAL(84, 1941, 26), // "on_pbMeasureWeight_clicked"
QT_MOC_LITERAL(85, 1968, 18), // "on_pbSet_5_clicked"
QT_MOC_LITERAL(86, 1987, 18), // "on_pbSet_6_clicked"
QT_MOC_LITERAL(87, 2006, 13), // "comBineImages"
QT_MOC_LITERAL(88, 2020, 8), // "cv::Mat&"
QT_MOC_LITERAL(89, 2029, 6), // "image1"
QT_MOC_LITERAL(90, 2036, 6), // "image2"
QT_MOC_LITERAL(91, 2043, 24), // "on_pbOldCustomer_clicked"
QT_MOC_LITERAL(92, 2068, 33), // "on_leCustomerHeight_returnPre..."
QT_MOC_LITERAL(93, 2102, 33), // "on_leCustomerWeight_returnPre..."
QT_MOC_LITERAL(94, 2136, 19), // "processing_leftFoot"
QT_MOC_LITERAL(95, 2156, 20), // "processing_rightFoot"
QT_MOC_LITERAL(96, 2177, 27), // "on_radioButton_left_toggled"
QT_MOC_LITERAL(97, 2205, 28), // "on_radioButton_right_toggled"
QT_MOC_LITERAL(98, 2234, 20), // "measureDistance_left"
QT_MOC_LITERAL(99, 2255, 21) // "measureDistance_right"

    },
    "MainWindow\0sig_left_scanner_id_changed\0"
    "\0idx\0sig_right_scanner_id_changed\0"
    "test_signal\0measuring_left\0measuring_right\0"
    "distance_left\0distance_right\0"
    "on_toolButton_clicked\0on_toolButton_2_clicked\0"
    "on_toolButton_3_clicked\0on_toolButton_4_clicked\0"
    "on_toolButton_5_clicked\0"
    "on_scanner_status_changed\0msg\0"
    "on_scanner_error\0on_scanner_image_captured\0"
    "cv::Mat\0on_actionNewCustomer_triggered\0"
    "on_actionExit_triggered\0"
    "on_actionAbout_triggered\0"
    "on_actionCalib_Scale_triggered\0"
    "on_pbBodyMeasurement_clicked\0"
    "on_pbFootAnalysis_clicked\0on_pbUpload_clicked\0"
    "on_pbSettings_clicked\0on_updateSettings\0"
    "on_pbSelectUpperCamera_clicked\0"
    "on_pbSelectBodyCamera_clicked\0"
    "on_pbUpperCapture_clicked\0"
    "on_pbFrontCapture_clicked\0"
    "on_pbBackCapture_clicked\0"
    "on_pbSideCapture_clicked\0on_webcamera\0"
    "on_cbWebcamSelect_activated\0"
    "on_pbSetUpperWebcam_clicked\0"
    "on_pbSetSideWebcam_clicked\0"
    "on_pbReSetWebcam_clicked\0"
    "on_pbReloadScannerDrivers_clicked\0"
    "on_pbLeftScan_clicked\0on_pbRightScan_clicked\0"
    "on_tbLeftFootMeasure_clicked\0"
    "on_tbRightFootMeasure_clicked\0on_leftDraw\0"
    "on_rightDraw\0on_pbSelectFootScanner_clicked\0"
    "on_pbFootPrintCapture_clicked\0"
    "on_cbLeftScanner_activated\0"
    "on_cbRightScanner_activated\0"
    "on_leLeftScannerScale_editingFinished\0"
    "on_leRightScannerScale_editingFinished\0"
    "on_pbSaveScannerSetting_clicked\0"
    "on_tbLeftFootReload_clicked\0"
    "on_tbRightFootReload_clicked\0"
    "on_tbLeftFootDetect_clicked\0"
    "on_tbRightFootDetect_clicked\0"
    "on_tbLeftFootSave_clicked\0"
    "on_tbRightFootSave_clicked\0on_leftDetect\0"
    "on_rightDetect\0on_pbSaveAnalysisResults_clicked\0"
    "on_pbConnectServer_clicked\0"
    "on_treeView_clicked\0index\0"
    "on_pbMakeFolder_clicked\0"
    "on_pbUploadFiles_clicked\0"
    "on_pbSetSystemFolder_clicked\0"
    "on_ckShowPassword_stateChanged\0on_bridge\0"
    "on_bridgeCalib\0on_cbBridges_activated\0"
    "on_cbBridgeGains_activated\0"
    "on_ckEnabled_stateChanged\0"
    "on_slRate_valueChanged\0on_leRate_editingFinished\0"
    "on_pbBridgeCalib_clicked\0on_pbSet_1_clicked\0"
    "on_pbSet_2_clicked\0on_pbSet_3_clicked\0"
    "on_pbSet_4_clicked\0on_pbSaveBridgeSetting_clicked\0"
    "on_pbReloadBridge_clicked\0"
    "on_pbMeasureWeight_clicked\0"
    "on_pbSet_5_clicked\0on_pbSet_6_clicked\0"
    "comBineImages\0cv::Mat&\0image1\0image2\0"
    "on_pbOldCustomer_clicked\0"
    "on_leCustomerHeight_returnPressed\0"
    "on_leCustomerWeight_returnPressed\0"
    "processing_leftFoot\0processing_rightFoot\0"
    "on_radioButton_left_toggled\0"
    "on_radioButton_right_toggled\0"
    "measureDistance_left\0measureDistance_right"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      91,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  469,    2, 0x06 /* Public */,
       4,    1,  472,    2, 0x06 /* Public */,
       5,    0,  475,    2, 0x06 /* Public */,
       6,    0,  476,    2, 0x06 /* Public */,
       7,    0,  477,    2, 0x06 /* Public */,
       8,    0,  478,    2, 0x06 /* Public */,
       9,    0,  479,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  480,    2, 0x08 /* Private */,
      11,    0,  481,    2, 0x08 /* Private */,
      12,    0,  482,    2, 0x08 /* Private */,
      13,    0,  483,    2, 0x08 /* Private */,
      14,    0,  484,    2, 0x08 /* Private */,
      15,    1,  485,    2, 0x08 /* Private */,
      17,    1,  488,    2, 0x08 /* Private */,
      18,    1,  491,    2, 0x08 /* Private */,
      20,    0,  494,    2, 0x08 /* Private */,
      21,    0,  495,    2, 0x08 /* Private */,
      22,    0,  496,    2, 0x08 /* Private */,
      23,    0,  497,    2, 0x08 /* Private */,
      24,    0,  498,    2, 0x08 /* Private */,
      25,    0,  499,    2, 0x08 /* Private */,
      26,    0,  500,    2, 0x08 /* Private */,
      27,    0,  501,    2, 0x08 /* Private */,
      28,    0,  502,    2, 0x08 /* Private */,
      29,    0,  503,    2, 0x08 /* Private */,
      30,    0,  504,    2, 0x08 /* Private */,
      31,    0,  505,    2, 0x08 /* Private */,
      32,    0,  506,    2, 0x08 /* Private */,
      33,    0,  507,    2, 0x08 /* Private */,
      34,    0,  508,    2, 0x08 /* Private */,
      35,    0,  509,    2, 0x08 /* Private */,
      36,    0,  510,    2, 0x08 /* Private */,
      37,    0,  511,    2, 0x08 /* Private */,
      38,    0,  512,    2, 0x08 /* Private */,
      39,    0,  513,    2, 0x08 /* Private */,
      40,    0,  514,    2, 0x08 /* Private */,
      41,    0,  515,    2, 0x08 /* Private */,
      42,    0,  516,    2, 0x08 /* Private */,
      43,    0,  517,    2, 0x08 /* Private */,
      44,    0,  518,    2, 0x08 /* Private */,
      45,    0,  519,    2, 0x08 /* Private */,
      46,    0,  520,    2, 0x08 /* Private */,
      47,    0,  521,    2, 0x08 /* Private */,
      48,    0,  522,    2, 0x08 /* Private */,
      49,    0,  523,    2, 0x08 /* Private */,
      50,    0,  524,    2, 0x08 /* Private */,
      51,    0,  525,    2, 0x08 /* Private */,
      52,    0,  526,    2, 0x08 /* Private */,
      53,    0,  527,    2, 0x08 /* Private */,
      54,    0,  528,    2, 0x08 /* Private */,
      55,    0,  529,    2, 0x08 /* Private */,
      56,    0,  530,    2, 0x08 /* Private */,
      57,    0,  531,    2, 0x08 /* Private */,
      58,    0,  532,    2, 0x08 /* Private */,
      59,    0,  533,    2, 0x08 /* Private */,
      60,    0,  534,    2, 0x08 /* Private */,
      61,    0,  535,    2, 0x08 /* Private */,
      62,    0,  536,    2, 0x08 /* Private */,
      63,    0,  537,    2, 0x08 /* Private */,
      64,    1,  538,    2, 0x08 /* Private */,
      66,    0,  541,    2, 0x08 /* Private */,
      67,    0,  542,    2, 0x08 /* Private */,
      68,    0,  543,    2, 0x08 /* Private */,
      69,    0,  544,    2, 0x08 /* Private */,
      70,    0,  545,    2, 0x08 /* Private */,
      71,    0,  546,    2, 0x08 /* Private */,
      72,    0,  547,    2, 0x08 /* Private */,
      73,    0,  548,    2, 0x08 /* Private */,
      74,    0,  549,    2, 0x08 /* Private */,
      75,    0,  550,    2, 0x08 /* Private */,
      76,    0,  551,    2, 0x08 /* Private */,
      77,    0,  552,    2, 0x08 /* Private */,
      78,    0,  553,    2, 0x08 /* Private */,
      79,    0,  554,    2, 0x08 /* Private */,
      80,    0,  555,    2, 0x08 /* Private */,
      81,    0,  556,    2, 0x08 /* Private */,
      82,    0,  557,    2, 0x08 /* Private */,
      83,    0,  558,    2, 0x08 /* Private */,
      84,    0,  559,    2, 0x08 /* Private */,
      85,    0,  560,    2, 0x08 /* Private */,
      86,    0,  561,    2, 0x08 /* Private */,
      87,    2,  562,    2, 0x08 /* Private */,
      91,    0,  567,    2, 0x08 /* Private */,
      92,    0,  568,    2, 0x08 /* Private */,
      93,    0,  569,    2, 0x08 /* Private */,
      94,    0,  570,    2, 0x0a /* Public */,
      95,    0,  571,    2, 0x0a /* Public */,
      96,    0,  572,    2, 0x0a /* Public */,
      97,    0,  573,    2, 0x0a /* Public */,
      98,    0,  574,    2, 0x0a /* Public */,
      99,    0,  575,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, 0x80000000 | 19,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   65,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 19, 0x80000000 | 88, 0x80000000 | 88,   89,   90,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->sig_left_scanner_id_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sig_right_scanner_id_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->test_signal(); break;
        case 3: _t->measuring_left(); break;
        case 4: _t->measuring_right(); break;
        case 5: _t->distance_left(); break;
        case 6: _t->distance_right(); break;
        case 7: _t->on_toolButton_clicked(); break;
        case 8: _t->on_toolButton_2_clicked(); break;
        case 9: _t->on_toolButton_3_clicked(); break;
        case 10: _t->on_toolButton_4_clicked(); break;
        case 11: _t->on_toolButton_5_clicked(); break;
        case 12: _t->on_scanner_status_changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->on_scanner_error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->on_scanner_image_captured((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 15: _t->on_actionNewCustomer_triggered(); break;
        case 16: _t->on_actionExit_triggered(); break;
        case 17: _t->on_actionAbout_triggered(); break;
        case 18: _t->on_actionCalib_Scale_triggered(); break;
        case 19: _t->on_pbBodyMeasurement_clicked(); break;
        case 20: _t->on_pbFootAnalysis_clicked(); break;
        case 21: _t->on_pbUpload_clicked(); break;
        case 22: _t->on_pbSettings_clicked(); break;
        case 23: _t->on_updateSettings(); break;
        case 24: _t->on_pbSelectUpperCamera_clicked(); break;
        case 25: _t->on_pbSelectBodyCamera_clicked(); break;
        case 26: _t->on_pbUpperCapture_clicked(); break;
        case 27: _t->on_pbFrontCapture_clicked(); break;
        case 28: _t->on_pbBackCapture_clicked(); break;
        case 29: _t->on_pbSideCapture_clicked(); break;
        case 30: _t->on_webcamera(); break;
        case 31: _t->on_cbWebcamSelect_activated(); break;
        case 32: _t->on_pbSetUpperWebcam_clicked(); break;
        case 33: _t->on_pbSetSideWebcam_clicked(); break;
        case 34: _t->on_pbReSetWebcam_clicked(); break;
        case 35: _t->on_pbReloadScannerDrivers_clicked(); break;
        case 36: _t->on_pbLeftScan_clicked(); break;
        case 37: _t->on_pbRightScan_clicked(); break;
        case 38: _t->on_tbLeftFootMeasure_clicked(); break;
        case 39: _t->on_tbRightFootMeasure_clicked(); break;
        case 40: _t->on_leftDraw(); break;
        case 41: _t->on_rightDraw(); break;
        case 42: _t->on_pbSelectFootScanner_clicked(); break;
        case 43: _t->on_pbFootPrintCapture_clicked(); break;
        case 44: _t->on_cbLeftScanner_activated(); break;
        case 45: _t->on_cbRightScanner_activated(); break;
        case 46: _t->on_leLeftScannerScale_editingFinished(); break;
        case 47: _t->on_leRightScannerScale_editingFinished(); break;
        case 48: _t->on_pbSaveScannerSetting_clicked(); break;
        case 49: _t->on_tbLeftFootReload_clicked(); break;
        case 50: _t->on_tbRightFootReload_clicked(); break;
        case 51: _t->on_tbLeftFootDetect_clicked(); break;
        case 52: _t->on_tbRightFootDetect_clicked(); break;
        case 53: _t->on_tbLeftFootSave_clicked(); break;
        case 54: _t->on_tbRightFootSave_clicked(); break;
        case 55: _t->on_leftDetect(); break;
        case 56: _t->on_rightDetect(); break;
        case 57: _t->on_pbSaveAnalysisResults_clicked(); break;
        case 58: _t->on_pbConnectServer_clicked(); break;
        case 59: _t->on_treeView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 60: _t->on_pbMakeFolder_clicked(); break;
        case 61: _t->on_pbUploadFiles_clicked(); break;
        case 62: _t->on_pbSetSystemFolder_clicked(); break;
        case 63: _t->on_ckShowPassword_stateChanged(); break;
        case 64: _t->on_bridge(); break;
        case 65: _t->on_bridgeCalib(); break;
        case 66: _t->on_cbBridges_activated(); break;
        case 67: _t->on_cbBridgeGains_activated(); break;
        case 68: _t->on_ckEnabled_stateChanged(); break;
        case 69: _t->on_slRate_valueChanged(); break;
        case 70: _t->on_leRate_editingFinished(); break;
        case 71: _t->on_pbBridgeCalib_clicked(); break;
        case 72: _t->on_pbSet_1_clicked(); break;
        case 73: _t->on_pbSet_2_clicked(); break;
        case 74: _t->on_pbSet_3_clicked(); break;
        case 75: _t->on_pbSet_4_clicked(); break;
        case 76: _t->on_pbSaveBridgeSetting_clicked(); break;
        case 77: _t->on_pbReloadBridge_clicked(); break;
        case 78: _t->on_pbMeasureWeight_clicked(); break;
        case 79: _t->on_pbSet_5_clicked(); break;
        case 80: _t->on_pbSet_6_clicked(); break;
        case 81: { cv::Mat _r = _t->comBineImages((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< cv::Mat*>(_a[0]) = _r; }  break;
        case 82: _t->on_pbOldCustomer_clicked(); break;
        case 83: _t->on_leCustomerHeight_returnPressed(); break;
        case 84: _t->on_leCustomerWeight_returnPressed(); break;
        case 85: _t->processing_leftFoot(); break;
        case 86: _t->processing_rightFoot(); break;
        case 87: _t->on_radioButton_left_toggled(); break;
        case 88: _t->on_radioButton_right_toggled(); break;
        case 89: _t->measureDistance_left(); break;
        case 90: _t->measureDistance_right(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sig_left_scanner_id_changed)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sig_right_scanner_id_changed)) {
                *result = 1;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::test_signal)) {
                *result = 2;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::measuring_left)) {
                *result = 3;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::measuring_right)) {
                *result = 4;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::distance_left)) {
                *result = 5;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::distance_right)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 91)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 91;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 91)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 91;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sig_left_scanner_id_changed(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::sig_right_scanner_id_changed(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::test_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainWindow::measuring_left()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainWindow::measuring_right()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MainWindow::distance_left()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void MainWindow::distance_right()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
