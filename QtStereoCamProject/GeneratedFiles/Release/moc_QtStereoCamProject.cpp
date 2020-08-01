/****************************************************************************
** Meta object code from reading C++ file 'QtStereoCamProject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtStereoCamProject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtStereoCamProject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtStereoCamProject_t {
    QByteArrayData data[16];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtStereoCamProject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtStereoCamProject_t qt_meta_stringdata_QtStereoCamProject = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QtStereoCamProject"
QT_MOC_LITERAL(1, 19, 16), // "startStopCapture"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 5), // "start"
QT_MOC_LITERAL(4, 43, 12), // "imageCapture"
QT_MOC_LITERAL(5, 56, 17), // "cameraCalibration"
QT_MOC_LITERAL(6, 74, 19), // "computeDisparityMap"
QT_MOC_LITERAL(7, 94, 10), // "takeAPhoto"
QT_MOC_LITERAL(8, 105, 13), // "setBrightness"
QT_MOC_LITERAL(9, 119, 5), // "value"
QT_MOC_LITERAL(10, 125, 8), // "setFocus"
QT_MOC_LITERAL(11, 134, 7), // "saveXYZ"
QT_MOC_LITERAL(12, 142, 11), // "const char*"
QT_MOC_LITERAL(13, 154, 8), // "filename"
QT_MOC_LITERAL(14, 163, 3), // "Mat"
QT_MOC_LITERAL(15, 167, 3) // "mat"

    },
    "QtStereoCamProject\0startStopCapture\0"
    "\0start\0imageCapture\0cameraCalibration\0"
    "computeDisparityMap\0takeAPhoto\0"
    "setBrightness\0value\0setFocus\0saveXYZ\0"
    "const char*\0filename\0Mat\0mat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtStereoCamProject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    0,   57,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    1,   61,    2, 0x08 /* Private */,
      10,    1,   64,    2, 0x08 /* Private */,
      11,    2,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 14,   13,   15,

       0        // eod
};

void QtStereoCamProject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtStereoCamProject *_t = static_cast<QtStereoCamProject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startStopCapture((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: { int _r = _t->imageCapture();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->cameraCalibration(); break;
        case 3: _t->computeDisparityMap(); break;
        case 4: _t->takeAPhoto(); break;
        case 5: _t->setBrightness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setFocus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->saveXYZ((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< const Mat(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QtStereoCamProject::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QtStereoCamProject.data,
      qt_meta_data_QtStereoCamProject,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtStereoCamProject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtStereoCamProject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtStereoCamProject.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QtStereoCamProject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
