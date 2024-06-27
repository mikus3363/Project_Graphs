//
// Created by mikus on 29.05.2024.
//

#ifndef PROJEKTAIZO2_WCZYTTAB_H
#define PROJEKTAIZO2_WCZYTTAB_H

using namespace std;

class WczytTab {
public:
    void wczytajZPliku(const string& nazwaPliku, vector<Data::struktura>& tablica);
    int wczytajZakres(const string& nazwaPliku);
    int wczytajLiczbeStruktur(const string& nazwaPliku);
    int zakres;
    int liczbaStruktur;
};


#endif //PROJEKTAIZO2_WCZYTTAB_H
