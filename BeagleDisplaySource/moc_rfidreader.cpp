/****************************************************************************
** Meta object code from reading C++ file 'rfidreader.h'
**
** Created: Wed Jan 22 19:48:54 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "rfidreader.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rfidreader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RFIDReader[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RFIDReader[] = {
    "RFIDReader\0\0display()\0"
};

const QMetaObject RFIDReader::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RFIDReader,
      qt_meta_data_RFIDReader, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RFIDReader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RFIDReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RFIDReader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RFIDReader))
        return static_cast<void*>(const_cast< RFIDReader*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RFIDReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: display(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
