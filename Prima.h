//
// Created by mikus on 01.06.2024.
//

#ifndef PROJEKTAIZO2_PRIMAL_H
#define PROJEKTAIZO2_PRIMAL_H

#include "Data.h"

class Prima {
public:
    void mstPrimaMatrix(vector<vector<int>>& macierz, vector<int>& wagi);
    void mstPrimaList(const vector<vector<int>>& lista, vector<int>& wagi);
};


#endif //PROJEKTAIZO2_PRIMAL_H
