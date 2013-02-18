#ifndef NETWORKTEST_H
#define NETWORKTEST_H

#include <QObject>
#include "network.h"

class NetWorkTest : public QObject
{
    Q_OBJECT
private slots:
    void setUpTest();
    void attackTest();
    void quantityTest();
    void networkCheckTest();
private:
    int **m;
    OS **conf;
    Network *testNetwork;

    
};

#endif // NETWORKTEST_H
