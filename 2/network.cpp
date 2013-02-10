#include "network.h"

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
    srand(int(time(NULL)));
    int a = 0;
    for (int i = 0 ; i < quantity ; i++)
        {
            if (!comp[i]->getInfect())
            {
                continue;
            }
            for (int j = 0 ; j < quantity ; j++)
                {
                    if (curMap->get(i,j) == 0)
                    {
                        continue;
                    }
                    a = rand() % 5 + 1;
                    if ((!comp[j]->getInfect())&&(a >= comp[j]->getSec()))
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
                quantityOfVictims = quantityOfVictims + 1;
            }
        }
            cout<<"SystemTest:\n";
            if (quantityOfVictims == 1)
                cout<<"\n1 -Computer is infected\n\n";
            else
                if (quantityOfVictims==9)
                     cout<<"\nNetwork is destroyed!!!\n\n";
                else
                cout<<"\n"<<quantityOfVictims<<" -Computers are infected\n\n";
        QTest::qSleep(3000);
        return quantityOfVictims != quantity;
    }
int Network::getQuantity(){
    return quantity;
}

