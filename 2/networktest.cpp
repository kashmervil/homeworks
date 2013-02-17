#include "networktest.h"
void NetWorkTest::setUpTest()
{
    int map[9][9] =
    {
        {0, 1, 0, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0},
    };
    m = new int*[9];
    for (int i = 0; i < 9; i++)
        m[i] = new int[9];
    for (int i = 0; i < 9 ; i++)
        for (int j = 0; j < 9; j++)
            m[i][j] = map[i][j];
    conf = new OS*[9];
    conf[0] = conf[3] = conf[6] = new Linux;
    conf[1] = conf[4] = conf[7] = new MacOS;
    conf[2] = conf[5] = conf[8] = new Windows;
    testNetwork = new Network(9, m, conf);
}
void NetWorkTest::attackTest()
{
    RandState *r = new TestRand1;
    testNetwork->changeRand(r);//the weekest virus ever;
    testNetwork->virusAttack(0,true);
    testNetwork->virusAttack();
    QVERIFY(!testNetwork->getInfect(1));
    QVERIFY(testNetwork->getInfect(3));
    r = new TestRand4;//strong enough but not for Linux
    testNetwork->changeRand(r);
    testNetwork->virusAttack();
    QVERIFY(!testNetwork->getInfect(3));
    QVERIFY(testNetwork->getInfect(1));
    testNetwork->virusAttack();
    QVERIFY(testNetwork->getInfect(2) == testNetwork->getInfect(4));
}
void NetWorkTest::quantityTest()
{
    QVERIFY(testNetwork->getQuantity() == 9);
}
void NetWorkTest::networkCheckTest()
{
    QCOMPARE(testNetwork->networkCheck(),true);
}

