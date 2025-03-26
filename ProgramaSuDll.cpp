// ProgramaSuDll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../Dll/dllmain.h"

int main() 
{
	int studentoNr = 2314011;
	paleistiesLaikas();
	
	cout << "Jusu studento funkcija igyvendinimui: " << studentoFunkcija(studentoNr) << endl;
	laikoApribojimas("vaikas", "M-F,9:00-20:00;Sa-Su,14:00-20:00");
	cout << "Kuriami aplankalai..." << endl;
	aplankaluKurimas();
	cout << "Vykdomi skaiciavimai..." << endl;
	//skaiciavimai
	cout << "Skaiciavimai baigti." << endl;
	aplankaluTrinimas();
	uzbaigimoLaikas();
}