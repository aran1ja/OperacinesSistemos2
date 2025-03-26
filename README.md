# Sprendimo su programa, DLL ir setup projektais kūrimas
## Šeštos užduoties aprašymas
Sukurkite programos sisteminį DLL failą ir programą kuri jį naudoja. Ir DLL ir programai sukurkite atitinkamus degiklius Setup failus. Užduoties sprendimas turi atitikti  reikalavimus aprašytus „Operacinės sistemos lygmens failų panaudojimas programose“ skyriuje.
•	Kadangi daugumą programų naudoja bibleotekas savo veikimui, Jums reikia moketi jas kurti. Sukurkite savo nuosavą dinaminės bibliotekos failą C++  (DLL) su jo diegimo programą (Setup.msi arba Setup.exe) į OS aplankalą (pvz. "C:\Program Files (x86)"). Jūsų DLL failas privalo turėti tokias funkcijas:
1.	Laiko matavimo funkciją;
2.	Funkcija atitinkančią Jūsų Stud_ID %3+1 ir naudojančią system(eilutė.c_str()); galimybės:
      1.	Naudotojo laiko prie kompiuterio apribojimo modifikavimo funkciją. Funkcijai paduodami duomenys: naudotojo vardas, savaitės dienos ir laiko intervalas. Funkciją turi suformuoti teksto eilutę su komandą (eilutės kaip pvz. "dir" ) ir tą eilutę paduoti system(); komandai (system("dir");).
      2.	Funkcija kuri paleidžia naudotojo įvestu adresu ping signalą įrašant rezultatą į laikiną failą, kuri po to atveria ir pademonstruoja naudotojui. Pabaigoje failas turi būti naikinamas. Failo kūrimui naudokite CMD nukreipimo į failą komandą (pvz. dir > mano.txt išveda esamo aplankalo failų sąrašą į tekstinį failą mano.txt).
      3.	Funkcija kuri pagal naudotojo poreikį atveria valdymo skydo atitinkamą komponentę: Display, Security, Power, Storage, Update (reikia rasti atitinkamas PowerShell komandas ir iškvėšti jas per system(" ");).
3.	Programos aplankalų kūrimo funkcija priklausomai nuo Jūsų vardo ir pavardės. Pvz. aplankalas „Pavardenis“ jame dar tris aplankalai „Vardenis1“, „Vardenis2“, „Vardenis3“ ir kiekviename iš jų dar po tris „Vardenio1Vardenis1“, „Vardenio1Vardenis2“, „Vardenio1Vardenis3“ (naudojant system(" ");, visi „Vardenis“, „Pavardenis“ duomenys turi būti užprogramuoti kode ir atitikti Jūsų realius duomenys). Vėliau visuose aplankaluose turi būti kuriami .txt failai duomenų įrašymui/nuskaitymui ir tą turi atlikti 4-ą funkciją;
4.	Funkcija skirta apskaičiuoti Tšrinhauseno kilpą (angl. Tschirnhausen cubic) F = x3+3x2-y2. Funkcijai paduodami duomenys: F, x0, xn, Δx; rezultatas turi būti įrašomas kaip X, Y pora į atitinkamus failus. Funkcija turi būti skaičiuojama tik taškuose kur ji egzistuoja, t.y x taškų intervalas turi būti mažinamas pagal poreikį. Funkcija turi aptiktus taškus rašyti cikliškai po vieną failą kiekviename 3-ioje funkcijoje sukurtose aplankaluose. T.y. pirma pora eina į pirmą failą, antra rasta pora į antrą ir t.t. Įrašius duomenys į paskutinį failą duomenys toliau daro įrašą į pirmą.
5.	Funkcija skirta sulieti visuose failuose surašytus taškus į vieną failą pagal atitinkamą F ir surūšiuojant duomenys pagal X ir atlikus suliejimą tarpiniai failai naikinami (failai pagal atitinkama F su sulietais duomenimis saugomi šakniniame programos kataloge);
6.	3-ios funkcijos sukurtų aplankalų ištrynimo funkcija;

Toliau sukurkite programą naudojančią tik Jūsų DLL (be header ir lib failų) įdiegtą į kompiuterį  prieš tai. Programa turi atlikti sekančius veiksmus:
1. Matuoti paleisties ir užbaigimo laiką.
2. Įvykdo Jums atitekusią funkciją (iš DLL 2 punkto).
3. Turi sukurti darbinių aplankalų struktūrą (iš DLL 3 punkto).
4. Toliau programa turi apskaičiuoti [X,Y] taškų poras, kai F=-2, F=-1, F=0, F=1 ir F=2; ir kai x keičiasi intervale nuo [-(student_ID % 19); student_ID % 25] žingsniu (student_ID/1000000000000). Visi rezultatai išvedami cikliškai po vieną porą į sukurtus failus iš eilės, t.y. pirmas taškas į pirmą failą, antras taškas į antrą ir taip toliau kol nepasieks paskutinį failą, po to įrašai vėl daromi į pirmą ir kartojame kol nebus rasta paskutinis taškas. Po to failai uždaromi.
5. Įvykdžius vieno F apskaičiavimą programa turi sulieti visų failų duomenys į vieną surūšiuojant juos x didėjimo tvarką (iš DLL 5 punkto).
6. Gavus visus rezultatus programa turi ištrinti visus jau nebereikalingus aplankalus ir failus (iš DLL 6 punkto).
7. Programa pateikia galutinai sugaištą laiką.
