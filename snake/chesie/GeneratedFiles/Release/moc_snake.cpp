/****************************************************************************
** Meta object code from reading C++ file 'snake.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../snake.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'snake.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_da_t {
    QByteArrayData data[13];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_da_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_da_t qt_meta_stringdata_da = {
    {
QT_MOC_LITERAL(0, 0, 2), // "da"
QT_MOC_LITERAL(1, 3, 8), // "gameOver"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 15), // "scoreHasChanged"
QT_MOC_LITERAL(4, 29, 5), // "hiden"
QT_MOC_LITERAL(5, 35, 11), // "startWindow"
QT_MOC_LITERAL(6, 47, 6), // "string"
QT_MOC_LITERAL(7, 54, 10), // "stopWindow"
QT_MOC_LITERAL(8, 65, 12), // "modifySpeedU"
QT_MOC_LITERAL(9, 78, 12), // "modifySpeedD"
QT_MOC_LITERAL(10, 91, 13), // "noRepaintings"
QT_MOC_LITERAL(11, 105, 9), // "spawnGift"
QT_MOC_LITERAL(12, 115, 10) // "timeToHide"

    },
    "da\0gameOver\0\0scoreHasChanged\0hiden\0"
    "startWindow\0string\0stopWindow\0"
    "modifySpeedU\0modifySpeedD\0noRepaintings\0"
    "spawnGift\0timeToHide"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_da[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    1,   65,    2, 0x06 /* Public */,
       4,    0,   68,    2, 0x06 /* Public */,
       5,    2,   69,    2, 0x06 /* Public */,
       7,    0,   74,    2, 0x06 /* Public */,
       8,    0,   75,    2, 0x06 /* Public */,
       9,    0,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 6,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void da::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        da *_t = static_cast<da *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gameOver(); break;
        case 1: _t->scoreHasChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->hiden(); break;
        case 3: _t->startWindow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const string(*)>(_a[2]))); break;
        case 4: _t->stopWindow(); break;
        case 5: _t->modifySpeedU(); break;
        case 6: _t->modifySpeedD(); break;
        case 7: _t->noRepaintings(); break;
        case 8: _t->spawnGift(); break;
        case 9: _t->timeToHide(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (da::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&da::gameOver)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (da::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&da::scoreHasChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (da::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&da::hiden)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (da::*_t)(int , const string & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&da::startWindow)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (da::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&da::stopWindow)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (da::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&da::modifySpeedU)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (da::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&da::modifySpeedD)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject da::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_da.data,
      qt_meta_data_da,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *da::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *da::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_da.stringdata0))
        return static_cast<void*>(const_cast< da*>(this));
    return QWidget::qt_metacast(_clname);
}

int da::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void da::gameOver()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void da::scoreHasChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void da::hiden()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void da::startWindow(int _t1, const string & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void da::stopWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void da::modifySpeedU()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void da::modifySpeedD()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
