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
    conf[0] = new Linux;
    conf[1] = new MacOS;
    conf[2] = new Windows;
    conf[3] = new Linux;
    conf[4] = new MacOS;
    conf[5] = new Windows;
    conf[6] = new Linux;
    conf[7] = new MacOS;
    conf[8] = new Windows;
    testNetwork = new Network(9, m, conf);
}
void NetWorkTest::attackTest()
{
    RandState *r = new TestRand<1>;
    testNetwork->changeRand(r);//the weekest virus ever;
    testNetwork->virusAttack(0,true);
    testNetwork->virusAttack();
    QVERIFY(!testNetwork->getInfect(1));
    QVERIFY(!testNetwork->getInfect(3));
    r = new TestRand<4>;//strong enough but not for Linux
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

