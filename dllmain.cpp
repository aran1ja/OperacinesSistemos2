// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "dllmain.h"

using namespace std;
using namespace std::chrono;

static high_resolution_clock::time_point pradzia;

void paleistiesLaikas()
{
	pradzia = high_resolution_clock::now();
}

void uzbaigimoLaikas()
{
	auto pabaiga = high_resolution_clock::now();
	auto skirtumas = duration_cast<seconds>(pabaiga - pradzia).count();
	
	cout << "Galutinai sugaistas laikas: " << skirtumas << "s." << endl;
}

int studentoFunkcija(int skaicius) {
	return skaicius % 3 + 1;
}

void laikoApribojimas(const char* vardas, const char* laikas)
{
	string eilute = "net user ";
	eilute += vardas;
	eilute += " /time:";
	eilute += laikas;
	cout << "Vykdoma komanda: " << eilute << endl;
	system(eilute.c_str());
}

void aplankaluKurimas()
{
	string vardas = "Adriana";
	string vardenio = "Adrianos";
	string pavarde = "Sirokyte";

	string pagrindinis_aplankalas = "mkdir " + pavarde;
	system(pagrindinis_aplankalas.c_str());

	for (int i = 1; i <= 3; i++) {
		string antro_aplankalo_pavadinimas = vardas + to_string(i);
		string antras_aplankalas = "mkdir " + pavarde + "\\" + antro_aplankalo_pavadinimas;
		system(antras_aplankalas.c_str());

		for (int j = 1; j <= 3; j++) {
			string trecio_aplankalo_pavadinimas = vardenio + to_string(i) + vardas + to_string(j);
			string trecias_aplankalas = "mkdir " + pavarde + "\\" + antro_aplankalo_pavadinimas + "\\" + trecio_aplankalo_pavadinimas;
			system(trecias_aplankalas.c_str());
		}
	}
}

