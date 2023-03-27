/****************************************************************************
** Meta object code from reading C++ file 'Windows.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Windows.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Windows.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Windows_t {
    QByteArrayData data[14];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Windows_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Windows_t qt_meta_stringdata_Windows = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Windows"
QT_MOC_LITERAL(1, 8, 7), // "newGame"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 5), // "gagne"
QT_MOC_LITERAL(4, 23, 5), // "Color"
QT_MOC_LITERAL(5, 29, 6), // "joueur"
QT_MOC_LITERAL(6, 36, 10), // "addPieceOk"
QT_MOC_LITERAL(7, 47, 3), // "col"
QT_MOC_LITERAL(8, 51, 14), // "addPieceReseau"
QT_MOC_LITERAL(9, 66, 1), // "i"
QT_MOC_LITERAL(10, 68, 20), // "nouvellePartieReseau"
QT_MOC_LITERAL(11, 89, 11), // "updateTimer"
QT_MOC_LITERAL(12, 101, 15), // "changeModeTimer"
QT_MOC_LITERAL(13, 117, 4) // "mode"

    },
    "Windows\0newGame\0\0gagne\0Color\0joueur\0"
    "addPieceOk\0col\0addPieceReseau\0i\0"
    "nouvellePartieReseau\0updateTimer\0"
    "changeModeTimer\0mode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Windows[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    1,   50,    2, 0x0a /* Public */,
       6,    1,   53,    2, 0x0a /* Public */,
       8,    1,   56,    2, 0x0a /* Public */,
      10,    0,   59,    2, 0x0a /* Public */,
      11,    0,   60,    2, 0x0a /* Public */,
      12,    1,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void Windows::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Windows *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newGame(); break;
        case 1: _t->gagne((*reinterpret_cast< Color(*)>(_a[1]))); break;
        case 2: _t->addPieceOk((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->addPieceReseau((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->nouvellePartieReseau(); break;
        case 5: _t->updateTimer(); break;
        case 6: _t->changeModeTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Windows::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Windows.data,
    qt_meta_data_Windows,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Windows::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Windows::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Windows.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Windows::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
