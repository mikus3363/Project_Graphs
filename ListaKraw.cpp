//
// Created by mikus on 29.05.2024.
//

#include "ListaKraw.h"
#include <iostream>
#include <vector>
using namespace std;

void ListaKraw::createList(vector<Data::struktura>& tab, int e, int param,vector<vector<int>>& lista,vector<int>& wagi) {
    for (int i = 0; i < e; i++) {
        lista.push_back(vector<int>());
        if(param == 1) {
            for (size_t j = 0; j < tab.size() ; ++j) {
                if (tab[j].started == i) {
                    lista[i].push_back(tab[j].ended);
                    wagi.insert(wagi.end(),tab[j].weight);
                }
            }

        }
        else{
            for (size_t j = 0; j < tab.size() ; ++j) {
                if (tab[j].started == i) {
                    lista[i].push_back(tab[j].ended);
                    wagi.insert(wagi.end(),tab[j].weight);
                }
            }
        }
    }
}

void ListaKraw::wysListe(const vector<vector<int>>& array) {
    for (size_t i = 0; i < array.size(); ++i) {
        cout<<i<<": ";
        for (size_t j = 0; j < array[i].size(); ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
void ListaKraw::wysWagi(vector<int>& wagi) {
    for (size_t i = 0; i < wagi.size(); ++i) {
        cout<<wagi[i]<<", ";
    }
}