/****************************************************************************
** Meta object code from reading C++ file 'QtImageManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtImageManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtImageManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CQtImageManager_t {
    QByteArrayData data[8];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CQtImageManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CQtImageManager_t qt_meta_stringdata_CQtImageManager = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CQtImageManager"
QT_MOC_LITERAL(1, 16, 12), // "updateViewGL"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 18), // "setVisualicedImage"
QT_MOC_LITERAL(4, 49, 7), // "cv::Mat"
QT_MOC_LITERAL(5, 57, 3), // "img"
QT_MOC_LITERAL(6, 61, 24), // "resetGL_PROJECTIONMatrix"
QT_MOC_LITERAL(7, 86, 9) // "videoLoop"

    },
    "CQtImageManager\0updateViewGL\0\0"
    "setVisualicedImage\0cv::Mat\0img\0"
    "resetGL_PROJECTIONMatrix\0videoLoop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CQtImageManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x0a /* Public */,
       6,    0,   38,    2, 0x0a /* Public */,
       7,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CQtImageManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CQtImageManager *_t = static_cast<CQtImageManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateViewGL(); break;
        case 1: _t->setVisualicedImage((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 2: _t->resetGL_PROJECTIONMatrix(); break;
        case 3: _t->videoLoop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CQtImageManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CQtImageManager::updateViewGL)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CQtImageManager::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_CQtImageManager.data,
      qt_meta_data_CQtImageManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CQtImageManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CQtImageManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CQtImageManager.stringdata0))
        return static_cast<void*>(this);
    return QGLWidget::qt_metacast(_clname);
}

int CQtImageManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CQtImageManager::updateViewGL()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
