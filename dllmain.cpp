// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "dllmain.h"

using namespace std;
using namespace std::chrono;
namespace fs = std::filesystem;

static system_clock::time_point pradzia;

void paleistiesLaikas() {
    pradzia = system_clock::now();
    time_t laikas = system_clock::to_time_t(pradzia);
    tm sauguLaika;
    localtime_s(&sauguLaika, &laikas);
    cout << "Kodo paleidimas: " << put_time(&sauguLaika, "%Y-%m-%d %H:%M:%S") << endl;
}

void uzbaigimoLaikas() {
    auto pabaiga = system_clock::now();
    time_t laikas = system_clock::to_time_t(pabaiga);
    tm sauguLaika;
    localtime_s(&sauguLaika, &laikas);
    cout << "Kodo uzbaigimas: " << put_time(&sauguLaika, "%Y-%m-%d %H:%M:%S") << endl;

    auto skirtumas = duration_cast<seconds>(pabaiga - pradzia).count();
    cout << "Galutinai sugaistas laikas: " << (skirtumas/60) << "min " << (skirtumas%60) << "s" << endl;
}

int studentoFunkcija(int skaicius) {
    return skaicius % 3 + 1;
}

void laikoApribojimas(const char* vardas, const char* laikas) {
    string eilute = "net user ";
    eilute += vardas;
    eilute += " /time:";
    eilute += laikas;
    cout << "Vykdoma komanda: " << eilute << endl;
    system(eilute.c_str());
}

void aplankaluKurimas() {
    string vardas = "Adriana";
    string vardenio = "Adrianos";
    string pavarde = "Sirokyte";

    string pagrindinis_aplankalas = "mkdir " + pavarde;
    system(pagrindinis_aplankalas.c_str());

    for (int i = 1; i <= 3; i++) {
        string antras = "mkdir " + pavarde + "\\" + vardas + to_string(i);
        system(antras.c_str());

        for (int j = 1; j <= 3; j++) {
            string trecias = "mkdir " + pavarde + "\\" + vardas + to_string(i) + "\\" +
                vardenio + to_string(i) + vardas + to_string(j);
            system(trecias.c_str());
        }
    }
}

vector<fs::path> sugeneruotiFailus(const fs::path& aplankaliukas) {
    vector<fs::path> failai;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            fs::path kelias = aplankaliukas / ("Adriana" + to_string(i)) /
                ("Adrianos" + to_string(i) + "Adriana" + to_string(j)) /
                "duomenys.txt";
            failai.push_back(kelias);
        }
    }
    return failai;
}

double TsrinhausenoKilpa(double x, double F) {
    double y_kvadratu = pow(x, 3) + 3 * pow(x, 2) - F;
    return y_kvadratu;
}

void aplankaluTrinimas() {
    cout << "Trinamas aplankalas 'Sirokyte'..." << endl;
    string ateAplankalas = "rmdir /s /q Sirokyte";
    system(ateAplankalas.c_str());
}