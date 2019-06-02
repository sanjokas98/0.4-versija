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
    int suma = 0;
    int i = 0;
    double mediana = 0, vid=0, galutinis=0;
    ofstream file2("Rezultatai.txt");
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
int main () {
     ifstream file("Kursiokai.txt"); //skaitysime duomenis iğ failo
     ofstream file2("Rezultatai.txt");
     file2.fill('-');
     file2.width(71);
     file2<<" ";
     file2.fill(' ');
     file2<<" "<<endl;
     file2<<setw(8)<<right<<"Vardas"<<'\t'<<setw(8)<<left<<"Pavarde"<<'\t'<<setw(20)<<left<<"Galutinis (Vid.)"<<setw(10)<<left<<"Galutinis (Med.)"<<endl;
     file2.fill('-');
     file2.width(68);
     file2<<" ";
     file2.fill(' ');
     file2<<" "<<endl;
    string eilute;
    string pradzia;
    vector<studentas> studentai;
    vector<string> vardas;
    getline(file, pradzia);
    while (getline(file, eilute))
    {
        istringstream iss(eilute);//panaudoju iss, kad faile esancias eilutes galeciau skaidyti dalimis
        studentas *naujasStudentas = new studentas();
        vector<int> pazymiai;
        int pazymys;
        iss >> naujasStudentas->vardas >> naujasStudentas->pavarde;//nusiskaitau pradzia
        while (!iss.eof())
        {   iss >> pazymys;//pabaigiu skaityti likusius pazymius
            pazymiai.push_back(pazymys);
        }
        naujasStudentas->pazymiai = pazymiai;
        studentai.push_back(*naujasStudentas);
    };

while(!file.eof())
	{
		string line;
		getline(file, line);
		vardas.push_back(line);
	}
	sort(vardas.begin(), vardas.end());
    vector<string>::iterator iterator = vardas.begin();
	for(; iterator != vardas.end(); ++iterator)
        file2<< *iterator <<endl;//isrusiuojame pagal vardus
    for( vector<studentas>::const_iterator i = studentai.begin(); i != studentai.end(); ++i ){

        file2<<setw(8)<<right<<i->vardas<<'\t'<<setw(4)<<right<<i->pavarde;
        skaiciuoti(i->pazymiai);
        file2 << endl;//issivedame tai kas buvo suskaiciuota ir isrusiuota.
    }
     file2.fill('-');
     file2.width(68);
     file2<<" ";
     file2.fill(' ');
     file2<<" "<<endl;
     file2<<setw(20)<<left<<""<<"Studentu saraso pabaiga"<<endl;
    file.close();
    file2.close();
    return 0;
}
