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

