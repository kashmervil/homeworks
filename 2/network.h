#ifndef NETWORK_H
#define NETWORK_H
#include "Windows.h"
#include "Linux.h"
#include "MacOS.h"
#include "MapOfNet.h"
#include "RandState.h"
using namespace std;

class TrueRand : public RandState {
public:
    int randomize()
    {
        srand(int(time(NULL)));
        return rand()%5 +1;
    }
};
class TestRand1 : public RandState {
public:
    int randomize()
    {
        return 1;
    }
};
class TestRand2 : public RandState {
public:
    int randomize()
    {
        return 2;
    }
};
class TestRand3 : public RandState {
public:
    int randomize()
    {
        return 3;
    }
};
class TestRand4 : public RandState {
public:
    int randomize()
    {
        return 4;
    }
};
class TestRand5 : public RandState {
public:
    int randomize()
    {
        return 5;
    }
};

class Network {
public:
    Network()
    {
        random = new TrueRand;
        cout<<"\nPut the Quantity of computers of this Network\n"<<endl;
        cin>>quantity;
        comp = new OS*[quantity];
        curMap = new MapOfNet(quantity);
        curMap->setMap();
        setNetWorkConfig();
    }
    Network(int testQuant, int **testMap, OS **testConfig);
    int getQuantity();
    void setNetWorkConfig();
    void setNetWorkConfig(OS **conf);
    void virusAttack();
    void virusAttack(int i,bool l);
    bool getInfect(int i)
    {
        return comp[i]->getInfect();
    }
    bool networkCheck();
    void changeRand(RandState *RandState);
private:
    int quantity;
    OS** comp;
    MapOfNet *curMap;
    RandState *random;
};


#endif // NETWORK_H
