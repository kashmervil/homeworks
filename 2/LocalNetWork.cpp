// LocalNetWork.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
int const quantity = 9;


class OS{
public:
    bool infection;
	OS() : infection(false)
	{}
	OS(bool t) : infection(t)
	{}
	int getSec()
	{
		return security;
				//value from 1 to 5 of system's security efficient
				//1- system is totaly incapable for protection
				//5- none virus can destroy it
	}
protected:
	int security;

};


class MacOS : public OS {
public:
	MacOS() : OS()
	{
		infection = false;
		security = 3;
	}
};


class Linux : public OS {
public:
	Linux() : OS()
	{
		infection = false;
		security = 4;
	}
};


class Windows : public OS {
public:
	Windows() : OS()
	{
		infection = false;
		security = 2;
	}
};

void setNetWorkConfig(OS* computer[quantity])
{
	srand(time(NULL));
	int j;
	for (int i = 0 ; i < quantity ; i++)
	{
		j = rand()%3 + 1;
		cout<<"\nComputer #"<<i+1;
		switch(j){
		case(1):
			{
				computer[i] = new MacOS;
				cout<<" is Mac";
				break;
			}
		case(2):
			{
				computer[i] = new Linux;
				cout<<" is Linux";
				break;
			}
		case(3):
			{
				computer[i] = new Windows;
				cout<<" is Windows";
				break;
			}
		}
	}
	cout<<"\n\n";
}
void virusAttack(OS *victim[quantity] , int map[quantity][quantity])
{
	srand(int(time(NULL)));
	int a;
	for (int i = 0 ; i < quantity ; i++)
		{
			if (victim[i]->infection == true)
			{
				for (int j = 0 ; j < quantity ; j++)
				{
					if (map[i][j] == 1)
						if (victim[j]->infection == false)
						{
							a = rand() % 5 + 1;
							if  (a >= victim[j]->getSec())
							{
								victim[j]->infection = true;
							} 
						}
				}
			}
		}
}
bool systemCheck(OS *computers[quantity] )
	{
		int quantityOfVictims = 0;
		for (int i = 0 ; i < quantity ; i++)
		{
			if (computers[i]->infection == true)
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

void setMap(int map[quantity][quantity])
{
	int i,j,g,k;
	srand(time(NULL));
	for (i = 0 ; i < quantity ; i++)
	{
		k = 0;
		for (j = i ; j < quantity ; j++)
		{
			g = rand()%100 + 1;
			if ((g > 80)&&(i != j))
			{
				map[i][j] = map[j][i] = 1;//matrix of cooperation is symmetric
				k = 1;
			}
			else
				map[i][j] = map[j][i] = 0;
		}
		for(j = 0 ; j < quantity ; j++)//we should check the exsistance of separeted computers
		{							   //research of 2, 3, 4 separeted groups goes deeper
									   //in graphs and state machines theory
									   //generation of Network matrix is extra feature,
			                           //let's think that we are lucky
									   //and can restart program if we need to.
			if (map[i][j] == 1)
				k++;
		}
		if (k == 0)
		{
			do
			{
				j = rand()%9;
			}
			 while(i == j);
			map[i][j]=map[j][i] = 1;
		}
	}
}
void showMap(int map[quantity][quantity])
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

int main()
{
	int net[quantity][quantity];
	setMap(net);
	showMap(net);

	
	OS* comp[quantity];
	setNetWorkConfig(comp);
	comp[0]->infection = true;//The black sheep
	
	while (systemCheck(comp))
	{
		virusAttack(comp, net);
	}


	return 0;
}

