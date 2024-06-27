//
// Created by mikus on 29.05.2024.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "Data.h"
#include "WczytTab.h"
using namespace std;

void WczytTab::wczytajZPliku(const string& nazwaPliku, vector<Data::struktura>& tablica) {
    ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        cerr << "Nie można otworzyć pliku: " << nazwaPliku << endl;
        return;
    }
    string linia;
    // Wczytanie pierwszej linii pliku z zakresem i liczbą struktur
    if (getline(plik, linia)) {
        istringstream iss(linia);
        if (!(iss >> zakres >> liczbaStruktur)) {
            cerr << "Błąd wczytywania zakresu i liczby struktur z pliku." << endl;
            return;
        }
        // Wczytanie kolejnych linii z danymi struktur
        for (int i = 0; i < liczbaStruktur; ++i) {
            if (getline(plik, linia)) {
                Data::struktura struktura;
                istringstream issStruktura(linia);
                if (!(issStruktura >> struktura.started >> struktura.ended >> struktura.weight)) {
                    cerr << "Błąd wczytywania struktury z pliku w linii: " << i + 1 << endl;
                    return;
                }
                // Dodanie struktury do tablicy
                tablica.push_back(struktura);
            } else {
                cerr << "Błąd: za mało linii w pliku." << endl;
                return;
            }
        }
    } else {
        cerr << "Błąd wczytywania pierwszej linii z pliku." << endl;
        return;
    }

    plik.close();
}

int WczytTab::wczytajZakres(const string& nazwaPliku) {
    ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        cerr << "Nie można otworzyć pliku: " << nazwaPliku << endl;
        return -1;
    }

    string linia;
    // Wczytanie pierwszej linii pliku z zakresem
    if (getline(plik, linia)) {
        istringstream iss(linia);
        if (!(iss >> zakres)) {
            cerr << "Błąd wczytywania zakresu z pliku." << endl;
            return -1;
        }
    } else {
        cerr << "Błąd wczytywania pierwszej linii z pliku." << endl;
        return -1;
    }

    plik.close();
    return zakres;
}

int WczytTab::wczytajLiczbeStruktur(const string& nazwaPliku) {
    ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        std::cerr << "Nie można otworzyć pliku: " << nazwaPliku << std::endl;
        return -1;
    }

    string linia;
    if (getline(plik, linia)) {
        istringstream iss(linia);
        string token;
        if (!(iss >> token >> liczbaStruktur)) {
            std::cerr << "Błąd wczytywania danych z pliku." << std::endl;
            return -1;
        }
        return liczbaStruktur;
    } else {
        std::cerr << "Plik jest pusty." << std::endl;
        return -1;
    }
    plik.close();
}