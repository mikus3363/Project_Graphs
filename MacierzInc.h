//
// Created by mikus on 29.05.2024.
//

#ifndef PROJEKTAIZO2_MACIERZINC_H
#define PROJEKTAIZO2_MACIERZINC_H
#include "Data.h"

class MacierzInc {
public:
    void createMatrix(vector<Data::struktura>& tab, int e, int param, vector<vector<int>>& macierz,vector<int>& wagi);
    void wysMacierz(const vector<vector<int>>& array, int rows, int cols);
    void wysWagi(vector<int>& wagi);
};


#endif //PROJEKTAIZO2_MACIERZINC_H
