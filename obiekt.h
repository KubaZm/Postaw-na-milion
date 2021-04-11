#include <iostream>

using namespace std;

class Pytanie
{
    public:
    string tresc, a, b, c, d;
    char poprawna;
    int nrpytania;

    void wczytaj(int nr);
    int zadaj(int pozostale, int nr);
    int sprawdz(int oba,int obb,int obc,int obd);
};
