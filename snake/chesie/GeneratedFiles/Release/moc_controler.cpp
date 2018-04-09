/****************************************************************************
** Meta object code from reading C++ file 'controler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../controler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_controler_t {
    QByteArrayData data[9];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_controler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_controler_t qt_meta_stringdata_controler = {
    {
QT_MOC_LITERAL(0, 0, 9), // "controler"
QT_MOC_LITERAL(1, 10, 15), // "stopRepaintings"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "spawn"
QT_MOC_LITERAL(4, 33, 10), // "hideWindow"
QT_MOC_LITERAL(5, 44, 8), // "stopGame"
QT_MOC_LITERAL(6, 53, 9), // "stopHider"
QT_MOC_LITERAL(7, 63, 7), // "speedUp"
QT_MOC_LITERAL(8, 71, 9) // "speedDown"

    },
    "controler\0stopRepaintings\0\0spawn\0"
    "hideWindow\0stopGame\0stopHider\0speedUp\0"
    "speedDown"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_controler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void controler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        controler *_t = static_cast<controler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stopRepaintings(); break;
        case 1: _t->spawn(); break;
        case 2: _t->hideWindow(); break;
        case 3: _t->stopGame(); break;
        case 4: _t->stopHider(); break;
        case 5: _t->speedUp(); break;
        case 6: _t->speedDown(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (controler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&controler::stopRepaintings)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (controler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&controler::spawn)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (controler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&controler::hideWindow)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject controler::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_controler.data,
      qt_meta_data_controler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *controler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *controler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_controler.stringdata0))
        return static_cast<void*>(const_cast< controler*>(this));
    return QWidget::qt_metacast(_clname);
}

int controler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void controler::stopRepaintings()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void controler::spawn()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void controler::hideWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
