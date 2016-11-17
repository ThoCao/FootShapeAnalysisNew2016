/****************************************************************************
** Meta object code from reading C++ file 'IBackgroundWorker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IBackgroundWorker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IBackgroundWorker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IBackgroundWorker_t {
    QByteArrayData data[14];
    char stringdata[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IBackgroundWorker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IBackgroundWorker_t qt_meta_stringdata_IBackgroundWorker = {
    {
QT_MOC_LITERAL(0, 0, 17), // "IBackgroundWorker"
QT_MOC_LITERAL(1, 18, 18), // "sig_status_changed"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 3), // "msg"
QT_MOC_LITERAL(4, 42, 9), // "sig_error"
QT_MOC_LITERAL(5, 52, 20), // "sig_progress_changed"
QT_MOC_LITERAL(6, 73, 3), // "val"
QT_MOC_LITERAL(7, 77, 18), // "sig_image_captured"
QT_MOC_LITERAL(8, 96, 7), // "cv::Mat"
QT_MOC_LITERAL(9, 104, 3), // "img"
QT_MOC_LITERAL(10, 108, 7), // "do_work"
QT_MOC_LITERAL(11, 116, 21), // "on_scanner_id_changed"
QT_MOC_LITERAL(12, 138, 3), // "idx"
QT_MOC_LITERAL(13, 142, 9) // "test_slot"

    },
    "IBackgroundWorker\0sig_status_changed\0"
    "\0msg\0sig_error\0sig_progress_changed\0"
    "val\0sig_image_captured\0cv::Mat\0img\0"
    "do_work\0on_scanner_id_changed\0idx\0"
    "test_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IBackgroundWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       5,    1,   55,    2, 0x06 /* Public */,
       7,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   61,    2, 0x0a /* Public */,
      11,    1,   62,    2, 0x0a /* Public */,
      13,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,

       0        // eod
};

void IBackgroundWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IBackgroundWorker *_t = static_cast<IBackgroundWorker *>(_o);
        switch (_id) {
        case 0: _t->sig_status_changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sig_error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sig_progress_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sig_image_captured((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 4: _t->do_work(); break;
        case 5: _t->on_scanner_id_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->test_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IBackgroundWorker::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IBackgroundWorker::sig_status_changed)) {
                *result = 0;
            }
        }
        {
            typedef void (IBackgroundWorker::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IBackgroundWorker::sig_error)) {
                *result = 1;
            }
        }
        {
            typedef void (IBackgroundWorker::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IBackgroundWorker::sig_progress_changed)) {
                *result = 2;
            }
        }
        {
            typedef void (IBackgroundWorker::*_t)(cv::Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IBackgroundWorker::sig_image_captured)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject IBackgroundWorker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IBackgroundWorker.data,
      qt_meta_data_IBackgroundWorker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IBackgroundWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IBackgroundWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IBackgroundWorker.stringdata))
        return static_cast<void*>(const_cast< IBackgroundWorker*>(this));
    return QObject::qt_metacast(_clname);
}

int IBackgroundWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void IBackgroundWorker::sig_status_changed(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IBackgroundWorker::sig_error(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void IBackgroundWorker::sig_progress_changed(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void IBackgroundWorker::sig_image_captured(cv::Mat _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
