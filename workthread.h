#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QThread>

class WorkThread : public QThread
{
public:
    WorkThread();

    // QThread interface
protected:
    void run();
};

#endif // WORKTHREAD_H
