#ifndef WORKER_H
#define WORKER_H
#include <QString>
#include <QObject>
class Worker : public QObject
{
    Q_OBJECT
Q_SIGNALS:
    void finished();
public slots:
    void doWork();
public:
    QString qTag;
    QString qName;
    QString qStatus;
    QString qHours;
};

#endif // WORKER_H
