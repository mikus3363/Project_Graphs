//
// Created by mikus on 29.05.2024.
//

#ifndef PROJEKTAIZO2_DATA_H
#define PROJEKTAIZO2_DATA_H

#include <vector>
using namespace std;

class Data {
public:
    struct struktura { //struktura grafu
        int started; //z jakiego wierzcholka
        int ended; //do jakiego wierzcholka
        int weight; //jaka waga relacji
    };
    struct subnet { //zbiór dla struktury
        int parent; //obiekt badany
        int rank; //wysokosc drzewa
    };
    static void wyswietlStrukture(vector<struktura>& tab);
};


#endif //PROJEKTAIZO2_DATA_H
