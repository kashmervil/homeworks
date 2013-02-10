#ifndef MAPOFNET_H
#define MAPOFNET_H
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include "QTest"
using namespace std;
class MapOfNet
{
public:
    MapOfNet(int quantity);
    void setMap();
    void showMap();
    int get(int i, int j);
private:
    int** map;
    int quant;
};
#endif // MAPOFNET_H
