#include "network.h"
int main()
{
    Network y;
    y.virusAttack(0,true);//The black sheep
    for (int i = 0 ; i < y.getQuantity() ; i++)
        cout<<"comp["<<i+1<<"].isInfected = "<<y.getInfect(i)<<"\n";
    while (y.networkCheck())
    {
        y.virusAttack();
    }

    return 0;
}
