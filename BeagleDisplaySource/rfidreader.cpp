#include "rfidreader.h"
#include "ui_rfidreader.h"

RFIDReader::RFIDReader(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RFIDReader)
{
    numScans=0;
    ui->setupUi(this);
    QThread* thread = new QThread();
    worker = new Worker();
    worker->moveToThread(thread);
    thread->start();
    QMetaObject::invokeMethod(worker, "doWork", Qt::QueuedConnection);

    QObject::connect(worker, SIGNAL(finished()),
                     this, SLOT(display()));
}

RFIDReader::~RFIDReader()
{
    delete ui;
}

void RFIDReader::display()
{
    numScans++;
    ui->tagEdit->setText(worker->qTag);
    ui->nameEdit->setText(worker->qName);
    ui->statusEdit->setText(worker->qStatus);
    ui->hoursEdit->setText(worker->qHours);

    ui->lcdNumber->display(numScans);

}
