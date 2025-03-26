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
    string powershell = "powershell -Command \"Start-Process cmd -ArgumentList '/c "
        + eilute + "' -Verb RunAs\"";
    system(powershell.c_str());
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

void irasomiFailai(double F, const fs::path& aplankaliukas) {
    vector<fs::path> failai = sugeneruotiFailus(aplankaliukas);
    vector<ofstream> failiukai(failai.size());

    for (size_t i = 0; i < failai.size(); ++i) {
        fs::create_directories(failai[i].parent_path());
        failiukai[i].open(failai[i], ios::app);
    }

    double x0 = -1.0;
    double xn = 11.0;
    double dx = 0.000002314011;
    double x = x0;
    int esamasFailas = 0;

    while (x <= xn) {
        double y_kvadratu = pow(x, 3) + 3 * pow(x, 2) - F;
        if (y_kvadratu >= 0) {
            double y = sqrt(y_kvadratu);
            failiukai[esamasFailas] << x << " " << y << endl;
            esamasFailas = (esamasFailas + 1) % failai.size();
            if (y != 0) {
                failiukai[esamasFailas] << x << " " << -y << endl;
                esamasFailas = (esamasFailas + 1) % failai.size();
            }
        }
        x += dx;
    }

    for (auto& f : failiukai) {
        f.close();
    }

    vector<pair<double, double>> taskai;
    for (const auto& f : failai) {
        ifstream skaitome(f);
        double x, y;
        while (skaitome >> x >> y) 
            taskai.emplace_back(x, y);
        skaitome.close();
        fs::remove(f); // pasalinamas is disko
    }

    sort(taskai.begin(), taskai.end());
    ofstream irasome(aplankaliukas / (to_string((int)F) + "_F_sujungta.txt"));
    for (auto& [x, y] : taskai)
        irasome << x << " " << y << endl;
    irasome.close();
}

void skaiciavimas() {
    fs::path aplankaliukas = "Sirokyte";
    for (double F : {-2, -1, 0, 1, 2}) {
        irasomiFailai(F, aplankaliukas);
    }
}

void aplankaluTrinimas() {
    string ateAplankalas = "rmdir /s /q Sirokyte";
    system(ateAplankalas.c_str());
}