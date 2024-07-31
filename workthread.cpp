#include "workthread.h"
#include <QDateTime>
#include <QDebug>

WorkThread::WorkThread() {}

void WorkThread::run()
{

    QDateTime dateTime = QDateTime::currentDateTime();
    qDebug().noquote().nospace()<<"["<< dateTime.toString("yyyy-MM-dd hh:mm:ss.zzz")<<"]";

    qDebug()<<"WorkThread in run() "<<"isRunning:"<<this->isRunning()<<",isFinished:"<<this->isFinished();

    QThread::msleep(5000);




}
