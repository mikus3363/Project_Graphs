//
// Created by mikus on 29.05.2024.
//

#include "MacierzInc.h"
#include <iostream>
#include <vector>
using namespace std;

void MacierzInc::createMatrix(vector<Data::struktura>& tab, int e, int param,vector<vector<int>>& macierz,vector<int>& wagi) {
    if(param==1) {
        for (size_t k = 0; k < tab.size(); ++k) {
            wagi.insert(wagi.end(),tab[k].weight);
        }
        for (int i = 0; i < e; i++) {
            for (size_t j = 0; j < tab.size(); ++j) {
                if (tab[j].started == i) {
                    macierz[i][j] = 1;
                } else if (tab[j].ended == i) {
                    macierz[i][j] = -1;
                } else {
                    macierz[i][j] = 0;
                }
            }
        }
    }
    else{
        for (size_t k = 0; k < tab.size()/2; ++k) {
            wagi.insert(wagi.end(),tab[k].weight);
        }
        for (int i = 0; i < e; i++) {
            for (size_t j = 0; j < tab.size()/2; ++j) {
                if (tab[j].started == i || tab[j].ended == i) {
                    macierz[i][j] = 1;

                } else {
                    macierz[i][j] = 0;
                }
            }
        }
    }
}
void MacierzInc::wysMacierz(const vector<vector<int>>& array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
void MacierzInc::wysWagi(vector<int>& wagi) {
    for (size_t i = 0; i < wagi.size(); ++i) {
        cout<<wagi[i]<<" ";
    }
}