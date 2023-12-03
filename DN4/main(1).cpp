#include <iostream>
#include <fstream>
#include <vector>

int main() {

    // Imena datotek za vhod in izhod
    std::string vhodnaDatoteka = "poly.txt";
    std::string izhodnaDatoteka = "diff_poly.txt";

    // Ustvarimo izhodno datoteko
    std::ofstream izhodnaDatotekaObj(izhodnaDatoteka);
    std::ifstream vhodnaDatotekaObj;

    // Odpremo vhodno datoteko
    vhodnaDatotekaObj.open(vhodnaDatoteka);

    // Preberemo prvo vrstico, ki vsebuje število točk
    int steviloTock = 0;
    vhodnaDatotekaObj >> steviloTock;

    // Ustvarimo vektorja za shranjevanje vrednosti x in f
    std::vector<double> xVrednosti;
    std::vector<double> fVrednosti;

    // Zanka za branje vrednosti iz vhodne datoteke
    for (int i = 0; i < steviloTock; i++) {
        double vrednostX, vrednostF, ID;

        char dvopicje; 
        vhodnaDatotekaObj >> ID >> dvopicje >> vrednostX >> vrednostF;  // Ločimo vrednosti
        xVrednosti.push_back(vrednostX);
        fVrednosti.push_back(vrednostF);
    }
    // Zapremo vhodno datoteko, ker je ne potrebujemo več
    vhodnaDatotekaObj.close();

    // Izračunamo vrednost delta x, ki mora biti povsod enaka
    double h = abs(xVrednosti[1] - xVrednosti[2]);  

    // Izračunamo prvo vrednost odvoda (naprej)
    double odvodNaprej = (-3 * fVrednosti[0] + 4 * fVrednosti[1] - fVrednosti[2]) / abs(xVrednosti[2] - xVrednosti[0]);  
    std::vector<double> odvodi;
    odvodi.push_back(odvodNaprej);  

    // Zanka za izračun odvodov za vse vrednosti, razen prve in zadnje
    for (int i = 1; i < (steviloTock - 1); i++) {
        double srednjaVrednost = (fVrednosti[i + 1] - fVrednosti[i - 1]) / (2 * h);
        odvodi.push_back(srednjaVrednost);  
    }

    // Izračunamo zadnjo vrednost odvoda (nazaj)
    double odvodNazaj = (3 * fVrednosti[steviloTock - 1] - 4 * fVrednosti[steviloTock - 2] + fVrednosti[steviloTock - 3]) / (2 * abs(xVrednosti[steviloTock - 1] - xVrednosti[steviloTock - 2]));  
    odvodi.push_back(odvodNazaj);  

    // Zapisujemo vrednosti v izhodno datoteko
    for (double vrednost : odvodi) {
        izhodnaDatotekaObj << vrednost << '\n';
    }

    // Zapremo izhodno datoteko
    izhodnaDatotekaObj.close();

    return 0;
}
