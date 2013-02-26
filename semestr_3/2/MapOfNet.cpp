#include "MapOfNet.h"
MapOfNet::MapOfNet(int quantity)
{
    quant = quantity;
    map = new int*[quant];
    for (int i = 0 ; i < quant ; i++)
        map[i] = new int[quant];
}
void MapOfNet::setMap()
{
    srand(time(NULL));
    for (int i = 0 ; i < quant ; i++)
    {
        int k = 0;
        for (int j = i ; j < quant ; j++)
        {
            int g = rand()%100 + 1;
            if ((g > 80)&&(i != j))
            {
                map[i][j] = map[j][i] = 1;//matrix of cooperation is symmetric
            }
            else
                map[i][j] = map[j][i] = 0;
        }
        for(int j = 0 ; j < quant ; j++)//we should check the exsistance of separeted computers
        {				//research of 2, 3, 4 separeted groups goes deeper
                        //in graphs and state machines theory
                        //generation of Network matrix is extra feature,
                        //let's think that we are lucky and can restart program if we need to.
            if (map[i][j] == 1)
                k++;
        }
        if (k == 0)
        {
            int r = 0;
            do
            {
                r = rand()%quant;
            }
             while(i == r);
            map[i][r]=map[r][i] = 1;
        }
    }
}
void MapOfNet::setMap(int** m)
{
            map = m;
}

void MapOfNet::showMap()
{
    cout<<"\nCurrent map of cooperation in this network\n";
    for (int i=0 ; i < quant ; i++)
    {
        for (int j = 0 ; j < quant ; j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }

}
int MapOfNet::get(int i, int j)
{
    return map[i][j];
}
