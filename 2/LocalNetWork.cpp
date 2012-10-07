#include "stdafx.h"
class OS{
public:
	int getSec()
	{
		return security;//value from 1 to 5 of system's security efficient
				//1- system is totaly incapable for protection
				//5- none virus can destroy it
	}
	bool getInfect()
	{
		return isInfected;
	}
	void setInfect(bool l)
	{
		isInfected = l;
	}
	OS() : isInfected(false)
	{}
	OS(bool t) : isInfected(t)
	{}
protected:
    bool isInfected;
    int security;
	
};


class MacOS : public OS {
public:
	MacOS() : OS()
	{
		isInfected = false;
		security = 3;
	}
	MacOS(bool l) : OS(l)
	{
		security = 3;
	}
};


class Linux : public OS {
public:
	Linux() : OS()
	{
		isInfected = false;
		security = 4;
	}
	Linux(bool l) : OS(l)
	{
		security = 4;
	}
};


class Windows : public OS {
public:
	Windows() : OS()
	{
		security = 2;
	}
	Windows(bool l) : OS(l)
	{
		security = 2;
	}
};

class Network {
public:
	Network() 
	{
		cout<<"\nPut the Quantity of computers in this Network\n";
		cin>>quantity;
		comp = new OS[quantity];
		map = new int*[quantity];
		for (int i = 0 ; i < quantity ; i++)
			map[i] = new int[quantity];
		setNetWorkConfig();
		setMap();

	}
	int getQuantity();
	void setNetWorkConfig();
	void setMap();
	void showMap();
	void virusAttack();
	void virusAttack(int i,bool l);
	bool getInfect(int i)
	{
		return comp[i].getInfect();
	}
	bool networkCheck();
private:
	int quantity;
	OS* comp;
	int** map;
};
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
				comp[i] = new MacOS;
				cout<<" is Mac";
				break;
			}
		case(2):
			{
				comp[i] = new Linux;
				cout<<" is Linux";
				break;
			}
		case(3):
			{
				comp[i] = new Windows;
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
			if (!comp[i].getInfect())
			{
				continue;
			}	
			for (int j = 0 ; j < quantity ; j++)
				{
					if (map[i][j] == 0)
					{
						continue;
					}
					a = rand() % 5 + 1;
					if ((!comp[j].getInfect())&&(a >= comp[j].getSec()))
							{
								comp[j].setInfect(true);
							} 
				}
		}
}
void Network::virusAttack(int i,bool l)
{
	comp[i].setInfect(l);
}
bool Network::networkCheck()
	{
		int quantityOfVictims = 0;
		for (int i = 0 ; i < quantity ; i++)
		{
			if (comp[i].getInfect())
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
		Sleep(3000);
		return quantityOfVictims != quantity;
	}
void Network::setMap()
{
	srand(time(NULL));
	for (int i = 0 ; i < quantity ; i++)
	{
		int k = 0;
		for (int j = i ; j < quantity ; j++)
		{
			int g = rand()%100 + 1;
			if ((g > 80)&&(i != j))
			{
				map[i][j] = map[j][i] = 1;//matrix of cooperation is symmetric
			}
			else
				map[i][j] = map[j][i] = 0;
		}
		for(int j = 0 ; j < quantity ; j++)//we should check the exsistance of separeted computers
		{				//research of 2, 3, 4 separeted groups goes deep
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
				r = rand()%quantity;
			}
			 while(i == r);
			map[i][r]=map[r][i] = 1;
		}
	}
}
void Network::showMap()
{
	cout<<"\nCurrent map of cooperation in this network\n";
	for (int i=0 ; i < quantity ; i++)
	{
		for (int j = 0 ; j < quantity ; j++)
		{
			cout<<map[i][j]<<" ";
		}
		cout<<"\n";
	}

}
int Network::getQuantity(){
	return quantity;
}


int main()
{
	Network y;
	y.virusAttack(0,true);//The black sheep
	y.showMap();
	for (int i = 0 ; i < y.getQuantity() ; i++)
		cout<<"comp["<<i+1<<"].isInfected= "<<y.getInfect(i)<<"\n";
	while (y.networkCheck())
	{
		y.virusAttack();
	}

	return 0;
}
