#pragma once
#ifndef _DLL_H_
#define _DLL_H_

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <chrono>
#include <ctime>

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
}

extern "C" {
	DLL_API int studentoFunkcija(int);
}

#endif

