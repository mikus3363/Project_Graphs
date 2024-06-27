//
// Created by mikus on 31.05.2024.
//

#ifndef PROJEKTAIZO2_KRUSKAL_H
#define PROJEKTAIZO2_KRUSKAL_H

#include "Data.h"

class Kruskal {
public:
    void mstKruskalMatrix(vector<vector<int>>& macierz,vector<int>& wagi);
    void mstKruskalList(const vector<vector<int>>& lista,vector<int>& wagi);
private:
    int szukaj(std::vector<Data::subnet>& subsets, int i);
    void laczZbiory(std::vector<Data::subnet>& subsets, int x, int y);
};


#endif //PROJEKTAIZO2_KRUSKAL_H
