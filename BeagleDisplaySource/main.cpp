#include "rfidreader.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RFIDReader w;
    w.show();

    return a.exec();
}
