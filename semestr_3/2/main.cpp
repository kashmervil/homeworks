#include "networktest.h"
int main()
{
    NetWorkTest network;
    QTest::qExec(&network);
    return 0;
}
