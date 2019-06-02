#ifndef PARDZIA_H_INCLUDED
#define PARDZIA_H_INCLUDED
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
using namespace std;
struct studentas
{
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    double vid, mediana, suma, galutinis;
};
void skaiciuoti (vector<int> studentoPazymiai) {
    ofstream file2("Rezultatai.txt");
    int suma = 0;
    int i = 0;
    double mediana = 0, vid=0, galutinis=0;

    for (i ; i < studentoPazymiai.size() - 1; i++){
        suma += studentoPazymiai[i];

    };

    if (i % 2 == 0)
      mediana = (studentoPazymiai[i / 2 - 1] + studentoPazymiai[i / 2]) / 2;
    else
      mediana =  studentoPazymiai[i / 2];
      vid=(double)suma/i;
      galutinis=0.4*vid+0.6*studentoPazymiai[i];
      file2<<setw(15)<<right<<setprecision(2)<<fixed<<galutinis;
      file2<<setw(20)<<right<<setprecision(2)<<fixed<<mediana<<endl;

};
#endif // PARDZIA_H_INCLUDED
