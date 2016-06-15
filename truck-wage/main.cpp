#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <math.h>

using namespace std;

double godziny,minuty,euro,centy;
double kursEuro = 0;

double dwaOkraglij(double val) {
    return roundf(val * 100) / 100;
}

void policz() {
    //liczmy ilosc euro
    double euroCentynaMinute = (euro * 100 + centy)/60;

    double czas = godziny * 60 + minuty;

    double placa = czas * euroCentynaMinute;

    double placaEuro = placa / 100;
    //zaokr¹gloamy do dwóch
    placaEuro = dwaOkraglij(placaEuro);

    printf("Placa w euro %.2f\n", placaEuro);

    double placaZloty = kursEuro * placaEuro;
    placaZloty = dwaOkraglij(placaZloty);

    printf("Placa w zlotowkach %.2f\n", placaZloty);

}

void glowaPetla() {

    while(1) {
        system("CLS");
        cout<<"Kurs : "<<kursEuro<<"   Stawka : "<<euro<<" "<<centy<<"\n";
        cout<<"Wpisz iloœæ godzin minut.\n";
        cout<<"Na przyk³ad : 2 40\n";
        cout<<"Wpisz : ";
        cin>>godziny>>minuty;

        policz();

        system("PAUSE");
    }

}

int main()
{
    string kursString;

    ifstream myfile ("kurs_euro.txt");
    string linijka;
    if (myfile.is_open())
    {
        getline (myfile,kursString);
        kursEuro = atof(kursString.c_str());

        getline(myfile,linijka);
        euro = atoi(linijka.c_str());

        getline(myfile,linijka);
        centy = atoi(linijka.c_str());
        myfile.close();
    }

    glowaPetla();

    return 0;
}
