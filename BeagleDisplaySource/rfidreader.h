#ifndef RFIDREADER_H
#define RFIDREADER_H
#include "Worker.h"
#include <QThread>
#include <QMainWindow>

namespace Ui {
class RFIDReader;
}

class RFIDReader : public QMainWindow
{
    Q_OBJECT

public:
    explicit RFIDReader(QWidget *parent = 0);
    ~RFIDReader();
private slots:
    void display();
private:
    Ui::RFIDReader *ui;
    Worker* worker;
    int numScans;
};

#endif // RFIDREADER_H
