#include <iostream>
#include <fstream>
#include <cstdlib>
#include "obiekt.h"
//#include <conio.h>
#include <stdio.h>
#include <ctime>

using namespace std;

void czyszczenie()
{
    for(int p=0; p<15; p++)
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void instrukcja()
{
    cout << "Witaj w grze postaw na milion!" << endl;
    cout << "Masz przed soba 8 pytan i milion zlotych do wygrania." << endl;
    cout << "Pytania sa z dziedziny fizyki, matematyki i informatyki, czyli przedmiotow rozszerzonych na profilu politechnicznym." << endl;
    cout << "Aby obstawic kwote na dane pytanie, wcisnij jego litere A, B, C lub D, wprowadz kwote i zatwierdz enterem." << endl;
    cout << "Mozesz postawic na maksymalnie 3 odpowiedzi naraz." << endl;
    cout << "Pieniadze, ktorych nie postawisz, przepadna, wiec staraj sie obstawic wszystko." << endl;
    cout << "Do nastepnego pytania przechodza tylko te pieniadze, ktore postawiles na prawidlowa odpowiedz." << endl;
    cout << "Aby zmienic kwote obstawiona na dane pytanie, wprowadz kwote jeszcze raz, kwota zmieni sie, a nie doda." << endl;
    cout << "Jezeli niechcacy wcisnales przycisk odpowiedzi na ktora nie chcesz nic obstawiac, po prostu wpisz 0." << endl;
    cout << "Aby zakonczyc obstawianie wcisnij litere \"K\" jak koniec i zatwierdz swoj wybor." << endl;
    cout << "Powodzenia!\nWcisnij enter aby zaczac"<<endl;
    //getchar();
    cin.ignore();
    cin.get();
}

void losowanie(int losy[], int ilosc)
{
    int los;
    srand(time(NULL));
    for (int i=0; i<8; i++)
    {
        los=rand()%ilosc+1;
        for (int j=0; j<8; j++)
        {
            if (losy[j]==los)
            {
                j=8;
                i--;
            }
            else if (j==7)
                losy[i]=los;
        }
    }
}
void Pytanie::wczytaj(int nr)
{
    nrpytania=nr+1;
    string linia;
    int nrlinii=(nrpytania-1)*6+1; //numer linii, od której trzeba zaczac wczytywanie pytania
    int aktualnynr=1; //numer aktualnie czytanej linii
    ifstream plik;
    plik.open("Pytania.txt");
    if(plik.good()==false)
    {
        cout<<"Nie udalo sie otworzyc pliku!";
        exit(0);
    }
    while(aktualnynr<nrlinii+6)
    {
        getline(plik, linia);
        if(aktualnynr==nrlinii)
            tresc=linia;
        if(aktualnynr==nrlinii+1)
            a=linia;
        if(aktualnynr==nrlinii+2)
            b=linia;
        if(aktualnynr==nrlinii+3)
            c=linia;
        if(aktualnynr==nrlinii+4)
            d=linia;
        if(aktualnynr==nrlinii+5)
            poprawna=linia[0];
        aktualnynr++;
    }
    plik.close();
}

int obstaw_a(int &hajs, int obsta, int obstb, int obstc, int obstd, bool &pokaz);
int obstaw_b(int &hajs, int obsta, int obstb, int obstc, int obstd, bool &pokaz);
int obstaw_c(int &hajs, int obsta, int obstb, int obstc, int obstd, bool &pokaz);
int obstaw_d(int &hajs, int obsta, int obstb, int obstc, int obstd, bool &pokaz);

int Pytanie::zadaj(int pozostale, int nr)
{
    //char litera, na_pewno;
    string litera, na_pewno;
    bool pokazac;
    int obstawionea=0, obstawioneb=0, obstawionec=0, obstawioned=0;
    while ((litera!="k")||(litera!="K"))
    {
        pokazac=false;
        //system("cls");
        czyszczenie();
        cout<<"Pytanie nr "<<nr<<":"<<endl;
        cout<<tresc<<endl<<"A. "<<a<<endl<<"B. "<<b<<endl<<"C. "<<c<<endl<<"D. "<<d<<endl<<endl;
        cout<<"Pozostale pieniadze: "<<pozostale<<endl;
        cout<<"Postawione na odpowiedz A: "<<obstawionea<<endl;
        cout<<"Postawione na odpowiedz B: "<<obstawioneb<<endl;
        cout<<"Postawione na odpowiedz C: "<<obstawionec<<endl;
        cout<<"Postawione na odpowiedz D: "<<obstawioned<<endl;
        cout<<"Wcisnij K aby zakonczyc."<<endl;
        /*while(pokazac==false)
        {
            cout<<"Wcisnij litere: ";
            litera=getch();
            cout<<litera<<endl;
            switch(litera)
            {
            case 'a':
            {
                obstawionea=obstaw_a(pozostale, obstawionea, obstawioneb, obstawionec, obstawioned, pokazac);
                break;
            }
            case 'A':
            {
                obstawionea=obstaw_a(pozostale, obstawionea, obstawioneb, obstawionec, obstawioned, pokazac);
                break;
            }
            case 'b':
            {
                obstawioneb=obstaw_b(pozostale, obstawionea, obstawioneb, obstawionec, obstawioned, pokazac);
                break;
            }
            case 'B':
            {
                obstawioneb=obstaw_b(pozostale, obstawionea, obstawioneb, obstawionec, obstawioned, pokazac);
                break;
            }
            case 'c':
            {
                obstawionec=obstaw_c(pozostale, obstawionea, obstawioneb, obstawionec, obstawioned, pokazac);
                break;
            }
            case 'C':
            {
                obstawionec=obstaw_c(pozostale, obstawionea, obstawioneb, obstawionec, obstawioned, pokazac);
                break;
            }
            case 'd':
            {
                obstawioned=obstaw_d(pozostale, obstawionea, obstawioneb, obstawionec, obstawioned, pokazac);
                break;
            }
            case 'D':
            {
                obstawioned=obstaw_d(pozostale, obstawionea, obstawioneb, obstawionec, obstawioned, pokazac);
                break;
            }
            case 'k':
            {
                cout<<"Czy na pewno chcesz zakonczyc obstawianie?"<<endl;
                cout<<"Jesli tak, wcisnij T"<<endl;
                cout<<"Jesli nie, wcisnij inny klawisz"<<endl;
                cout<<"Twoj wybor: ";
                na_pewno=getch();
                cout<<na_pewno<<endl;
                switch (na_pewno)
                {
                case 't':
                {
                    return sprawdz(obstawionea, obstawioneb, obstawionec, obstawioned);
                    break;
                }
                case 'T':
                {
                    return sprawdz(obstawionea, obstawioneb, obstawionec, obstawioned);
                    break;
                }
                default:
                {
                    litera='n';
                    pokazac=true;
                    break;
                }
                }
                break;
            }
            case 'K':
            {
                cout<<"Czy na pewno chcesz zakonczyc obstawianie?"<<endl;
                cout<<"Jesli tak, wcisnij T"<<endl;
                cout<<"Jesli nie, wcisnij inny klawisz"<<endl;
                cout<<"Twoj wybor: ";
                na_pewno=getch();
                cout<<na_pewno<<endl;
                switch (na_pewno)
                {
                case 't':
                {
                    return sprawdz(obstawionea, obstawioneb, obstawionec, obstawioned);
                    break;
                }
                case 'T':
                {
                    return sprawdz(obstawionea, obstawioneb, obstawionec, obstawioned);
                    break;
                }
                default:
                {
                    litera='n';
                    pokazac=true;
                    break;
                }
                }
                break;
            }
            default:
            {
                cout<<"Nie ma takiej odpowiedzi!"<<endl;
                pokazac=false;
                break;
            }
            }
        }*/
        while(pokazac==false)
        {
            cout<<"Wcisnij litere: ";
            cin>>litera;
            if(litera=="a"||litera=="A")
                obstawionea=obstaw_a(pozostale, obstawionea, obstawioneb, obstawionec, obstawioned, pokazac);
            else if(litera=="b"||litera=="B")
                obstawioneb=obstaw_b(pozostale, obstawionea, obstawioneb, obstawionec, obstawioned, pokazac);
            else if(litera=="c"||litera=="C")
                obstawionec=obstaw_c(pozostale, obstawionea, obstawioneb, obstawionec, obstawioned, pokazac);
            else if(litera=="d"||litera=="D")
                obstawioned=obstaw_d(pozostale, obstawionea, obstawioneb, obstawionec, obstawioned, pokazac);

            else if(litera=="k"||litera=="K")
            {
                cout<<"Czy na pewno chcesz zakonczyc obstawianie?"<<endl;
                cout<<"Jesli tak, wcisnij T"<<endl;
                cout<<"Jesli nie, wcisnij inny klawisz"<<endl;
                cout<<"Twoj wybor: ";
                cin>>na_pewno;
                if(na_pewno=="t"||na_pewno=="T")
                    return sprawdz(obstawionea, obstawioneb, obstawionec, obstawioned);
                else
                {
                    litera="n";
                    pokazac=true;
                    break;
                }
            }
            else
            {
                cout<<"Nie ma takiej odpowiedzi!"<<endl;
                pokazac=false;
            }
        }
    }
}

int Pytanie::sprawdz(int oba, int obb,int obc,int obd)
{
    cout<<"Poprawna odpowiedz to "<<poprawna;
    if(poprawna=='A')
    {
        cout<<". "<<a<<endl;
        cout<<"Twoje pozostale pieniadze: "<<oba<<endl;
        cout<<"Wcisnij enter aby kontynuowac";
        cin.ignore();
        cin.get();
        return oba;
    }
    if(poprawna=='B')
    {
        cout<<". "<<b<<endl;
        cout<<"Twoje pozostale pieniadze: "<<obb<<endl;
        cout<<"Wcisnij enter aby kontynuowac";
        cin.ignore();
        cin.get();
        return obb;
    }
    if(poprawna=='C')
    {
        cout<<". "<<c<<endl;
        cout<<"Twoje pozostale pieniadze: "<<obc<<endl;
        cout<<"Wcisnij enter aby kontynuowac";
        cin.ignore();
        cin.get();
        return obc;
    }
    if(poprawna=='D')
    {
        cout<<". "<<d<<endl;
        cout<<"Twoje pozostale pieniadze: "<<obd<<endl;
        cout<<"Wcisnij enter aby kontynuowac";
        cin.ignore();
        cin.get();
        return obd;
    }
}

int obstaw_a(int &hajs, int obsta, int obstb, int obstc, int obstd, bool &pokaz)
{
    if (obstb!=0&&obstc!=0&&obstd!=0)
    {
        cout<<"Nie mozesz obstawic 4 odpowiedzi naraz! Najpierw wyzeruj jedna z odpowiedzi."<<endl;
        pokaz=false;
        return 0;
    }
    else
    {
        bool dobredane=false;
        hajs+=obsta;
        obsta=0;
        while (dobredane==false)
        {
            cout<<"Wpisz kwote na odpowiedz A: ";
            if(!(cin>>obsta))
            {
                cerr<<"Podaj liczbe!"<<endl;
                cin.clear(); //kasowanie flagi bledu strumienia
                cin.sync();  //kasowanie zbednych znaków z bufora
            }
            else if(obsta>hajs)
            {
                obsta=0;
                cerr<<"Podaj liczbe mniejsza od pozostalych pieniedzy!"<<endl;
            }
            else if(obsta<0)
            {
                obsta=0;
                cerr<<"Podaj liczbe wieksza od zera!"<<endl;
            }
            else
                dobredane=true;
        }
        hajs-=obsta;
        pokaz=true;
        return obsta;
    }
}
int obstaw_b(int &hajs, int obsta, int obstb, int obstc, int obstd, bool &pokaz)
{
    if (obsta!=0&&obstc!=0&&obstd!=0)
    {
        cout<<"Nie mozesz obstawic 4 odpowiedzi naraz! Najpierw wyzeruj jedna z odpowiedzi."<<endl;
        pokaz=false;
        return 0;
    }
    else
    {
        bool dobredane=false;
        hajs+=obstb;
        obstb=0;
        while (dobredane==false)
        {
            cout<<"Wpisz kwote na odpowiedz B: ";
            if(!(cin>>obstb))
            {
                cerr<<"Podaj liczbe!"<<endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync();  //kasowanie zbêdnych znaków z bufora
            }
            else if(obstb>hajs)
            {
                obstb=0;
                cerr<<"Podaj liczbe mniejsza od pozostalych pieniedzy!"<<endl;
            }
            else if(obstb<0)
            {
                obstb=0;
                cerr<<"Podaj liczbe wieksza od zera!"<<endl;
            }
            else
                dobredane=true;
        }
        pokaz=true;
        hajs-=obstb;
        return obstb;
    }
}
int obstaw_c(int &hajs, int obsta, int obstb, int obstc, int obstd, bool &pokaz)
{
    if (obsta!=0&&obstb!=0&&obstd!=0)
    {
        cout<<"Nie mozesz obstawic 4 odpowiedzi naraz! Najpierw wyzeruj jedna z odpowiedzi."<<endl;
        pokaz=false;
        return 0;
    }
    else
    {
        bool dobredane=false;
        hajs+=obstc;
        obstc=0;
        while (dobredane==false)
        {
            cout<<"Wpisz kwote na odpowiedz C: ";
            if(!(cin>>obstc))
            {
                cerr<<"Podaj liczbe!"<<endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync();  //kasowanie zbêdnych znaków z bufora
            }
            else if(obstc>hajs)
            {
                obstc=0;
                cerr<<"Podaj liczbe mniejsza od pozostalych pieniedzy!"<<endl;
            }
            else if(obstc<0)
            {
                obstc=0;
                cerr<<"Podaj liczbe wieksza od zera!"<<endl;
            }
            else
                dobredane=true;
        }
        pokaz=true;
        hajs-=obstc;
        return obstc;
    }
}
int obstaw_d(int &hajs, int obsta, int obstb, int obstc, int obstd, bool &pokaz)
{
    if (obsta!=0&&obstb!=0&&obstc!=0)
    {
        cout<<"Nie mozesz obstawic 4 odpowiedzi naraz! Najpierw wyzeruj jedna z odpowiedzi."<<endl;
        pokaz=false;
        return 0;
    }
    else
    {
        bool dobredane=false;
        hajs+=obstd;
        obstd=0;
        while (dobredane==false)
        {
            cout<<"Wpisz kwote na odpowiedz D: ";
            if(!(cin>>obstd))
            {
                cerr<<"Podaj liczbe!"<<endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync();  //kasowanie zbêdnych znaków z bufora
            }
            else if(obstd>hajs)
            {
                obstd=0;
                cerr<<"Podaj liczbe mniejsza od pozostalych pieniedzy!"<<endl;
            }
            else if(obstd<0)
            {
                obstd=0;
                cerr<<"Podaj liczbe wieksza od zera!"<<endl;
            }
            else
                dobredane=true;
        }
        pokaz=true;
        hajs-=obstd;
        return obstd;
    }
}
