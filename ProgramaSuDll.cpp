// ProgramaSuDll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../Dll/dllmain.h"

int main()
{
	paleistiesLaikas();
	uzbaigimoLaikas();
	cout << "Jusu studento funkcija igyvendinimui: " << 
		studentoFunkcija(2314011) << endl;
}