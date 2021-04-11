#include <iostream>
#include <ctime>
#include "obiekt.h"
#include <cstdlib>
#include <stdio.h>

using namespace std;

void instrukcja();
void czyszczenie();
void losowanie(int losy[], int ilosc);

int main()
{
    int pieniadze=1000000;
    int il_pytan=17;
    Pytanie p[il_pytan];
    int tab[8];

    for (int i=0; i<il_pytan; i++)
        p[i].wczytaj(i);

    losowanie(tab, il_pytan);
    instrukcja();

    for (int i=0; i<8; i++)
    {
        //system("cls");
        czyszczenie();
        pieniadze=p[tab[i]].zadaj(pieniadze, i+1);
        if (pieniadze==0)
        {
            cout<<"Koniec gry. Niestety nie wygrywasz nic. Moze nastepnym razem sie uda!";
            //getchar();
            cin.ignore();
            cin.get();
            exit(0);
        }
    }
    cout<<endl<<"Koniec gry. Twoja wygrana: "<<pieniadze<<" zl. Gratulacje!";
    //getchar();
    cin.ignore();
    cin.get();
    return 0;
}
