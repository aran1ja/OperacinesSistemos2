// ProgramaSuDll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../Dll/dllmain.h"

int main() {
	paleistiesLaikas();
	cout << "Studento funkcija igyvendinimui: " << studentoFunkcija(2314011) << endl;
	laikoApribojimas("vaikas", "M-F,9:00-20:00;Sa-Su,14:00-20:00");
	cout << "Kuriami aplankalai..." << endl;
	aplankaluKurimas();
	cout << "Aplankalai sukurti" << endl;
	cout << "Vykdomi skaiciavimai..." << endl;
	skaiciavimas();
	cout << "Skaiciavimai baigti." << endl;
	cout << "Trinamas aplankalas 'Sirokyte'..." << endl;
	aplankaluTrinimas();
	uzbaigimoLaikas();
}