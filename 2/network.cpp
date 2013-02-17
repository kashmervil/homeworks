#include "network.h"

Network::Network(int testQuant, int **testMap, OS **testConfig)
{
    quantity = testQuant;
    comp = new OS*[quantity];
    curMap = new MapOfNet(quantity);
    curMap->setMap(testMap);
    setNetWorkConfig();
}
void Network::setNetWorkConfig(OS **testConfig)
{
    comp = testConfig;

}

void Network::setNetWorkConfig()
{
    srand(time(NULL));
    int j;
    for (int i = 0 ; i < quantity ; i++)
    {
        cout<<"\nComputer #"<<i+1;
        j = rand()%3 + 1;
        switch(j){
        case(1):
            {
            comp[i] = new MacOS(false);
                cout<<" is Mac";
                break;
            }
        case(2):
            {
            comp[i] = new Linux(false);
                cout<<" is Linux";
                break;
            }
        case(3):
            {
            comp[i] = new Windows(false);
                cout<<" is Windows";
                break;
            }
        }
    }
    cout<<"\n\n";
}
void Network::virusAttack()
{

    for (int i = 0 ; i < quantity ; i++)
        {
            if (!comp[i]->getInfect())
            {
                continue;
            }
            int a = random->randomize();
            for (int j = 0 ; j < quantity ; j++)
                {
                    if (curMap->get(i,j) == 0)
                    {
                        continue;
                    }
                    if ((!comp[j]->getInfect())&&(a > comp[j]->getSec()))
                            {
                                comp[j]->setInfect(true);
                            }
                }
        }
}
void Network::virusAttack(int i,bool l)
{
    comp[i]->setInfect(l);
}
bool Network::networkCheck()
    {
        int quantityOfVictims = 0;
        for (int i = 0 ; i < quantity ; i++)
        {
            if (comp[i]->getInfect())
            {
                quantityOfVictims += 1;
            }
        }
            cout<<"SystemTest:\n";
            if (quantityOfVictims == 1)
                cout<<"\n1 -Computer is infected\n\n";
            else
                if (quantityOfVictims == quantity)
                     cout<<"\nNetwork is destroyed!!!\n\n";
                else
                cout<<"\n"<<quantityOfVictims<<" -Computers are infected\n\n";
        QTest::qSleep(3000);
        return quantityOfVictims != quantity;
    }
int Network::getQuantity(){
    return quantity;
}
void Network::changeRand(RandState *state)
{
    random = state;
}
