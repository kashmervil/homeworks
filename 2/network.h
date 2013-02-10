#ifndef NETWORK_H
#define NETWORK_H
#include "Windows.h"
#include "Linux.h"
#include "MacOS.h"
#include "MapOfNet.h"
using namespace std;

class Network {
public:
    Network()
    {
        cout<<"\nPut the Quantity of computers of this Network\n"<<endl;
        cin>>quantity;
        comp = new OS*[quantity];
        curMap = new MapOfNet(quantity);
        curMap->setMap();
        setNetWorkConfig();

    }
    int getQuantity();
    void setNetWorkConfig();
    void virusAttack();
    void virusAttack(int i,bool l);
    bool getInfect(int i)
    {
        return comp[i]->getInfect();
    }
    bool networkCheck();
private:
    int quantity;
    OS** comp;
    MapOfNet *curMap;
};


#endif // NETWORK_H
