#include "pradzia.h"
void programa(){
     ofstream file2("Rezultatai.txt");
     int start = clock();
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
    ifstream file("Kursiokai.txt");//skaitysime duomenis iğ failo
    vector<string> vardas;
    getline(file, pradzia);
    while (getline(file, eilute))
    {
        istringstream iss(eilute); //panaudoju iss, kad faile esancias eilutes galeciau skaidyti dalimis
        studentas *naujasStudentas = new studentas();
        vector<int> pazymiai;
        int pazymys;
        iss >> naujasStudentas->vardas >> naujasStudentas->pavarde;//nusiskaitau pradzia
        while (!iss.eof())
        {
            iss >> pazymys;//pabaigiu skaityti likusius pazymius
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
         cout << *iterator <<endl; //isrusiuojame pagal vardus
    for( vector<studentas>::const_iterator i = studentai.begin(); i != studentai.end(); ++i ){
        file2<<setw(8)<<right<<i->vardas<<'\t'<<setw(4)<<right<<i->pavarde;
        skaiciuoti(i->pazymiai);
        file2<< endl; //issivedame tai kas buvo suskaiciuota ir isrusiuota.
    }
     file2.fill('-');
     file2.width(68);
     file2<<" ";
     file2.fill(' ');
     file2<<" "<<endl;
     file2<<setw(20)<<left<<""<<"Studentu saraso pabaiga"<<endl;
     file2<<" "<<endl;
    file.close();
    int end = clock();
    cout<< "Programos darbo laikas "<<setprecision(4)<<((float)end - start)/CLOCKS_PER_SEC <<" sekundes." <<endl;
}
