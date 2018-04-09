/****************************************************************************
** Meta object code from reading C++ file 'rightCornerWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../rightCornerWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rightCornerWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_small_t {
    QByteArrayData data[7];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_small_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_small_t qt_meta_stringdata_small = {
    {
QT_MOC_LITERAL(0, 0, 5), // "small"
QT_MOC_LITERAL(1, 6, 15), // "startRepainting"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "hidden"
QT_MOC_LITERAL(4, 30, 6), // "string"
QT_MOC_LITERAL(5, 37, 7), // "message"
QT_MOC_LITERAL(6, 45, 14) // "stopRepainting"

    },
    "small\0startRepainting\0\0hidden\0string\0"
    "message\0stopRepainting"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_small[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x08 /* Private */,
       6,    0,   29,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void,

       0        // eod
};

void small::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        small *_t = static_cast<small *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startRepainting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const string(*)>(_a[2]))); break;
        case 1: _t->stopRepainting(); break;
        default: ;
        }
    }
}

const QMetaObject small::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_small.data,
      qt_meta_data_small,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *small::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *small::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_small.stringdata0))
        return static_cast<void*>(const_cast< small*>(this));
    return QWidget::qt_metacast(_clname);
}

int small::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
