//
// Created by mikus on 29.05.2024.
//

#ifndef PROJEKTAIZO2_LISTAKRAW_H
#define PROJEKTAIZO2_LISTAKRAW_H
#include "Data.h"

class ListaKraw {
public:
    void createList(vector<Data::struktura>& tab, int e, int param,vector<vector<int>>& lista,vector<int>& wagi);
    void wysListe(const vector<vector<int>>& array);
    void wysWagi(vector<int>& wagi);
};


#endif //PROJEKTAIZO2_LISTAKRAW_H
