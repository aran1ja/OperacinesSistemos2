#pragma once
#ifndef _DLL_H_
#define _DLL_H_

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <filesystem>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

using std::cout;
using std::endl;
using std::wcout;
using std::wstring;

extern "C" {
	DLL_API void paleistiesLaikas();
	DLL_API void uzbaigimoLaikas();
	DLL_API void laikoApribojimas(const char*, const char*);
	DLL_API void aplankaluKurimas();
	DLL_API void aplankaluTrinimas();
	DLL_API int studentoFunkcija(int);
}

#endif

