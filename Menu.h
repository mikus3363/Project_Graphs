//
// Created by mikus on 02.06.2024.
//

#ifndef PROJEKTAIZO2_MENU_H
#define PROJEKTAIZO2_MENU_H

#include "Menu.h"
#include <iostream>
#include <vector>
#include <ctime>
#include "Data.h"
#include "InitTab.h"
#include "WczytTab.h"
#include "MacierzInc.h"
#include "ListaKraw.h"
#include "Kruskal.h"
#include "Prima.h"
#include "Dijkstra.h"
#include "BellmanFord.h"

class Menu {
public:
    vector<Data::struktura> tab;
    InitTab inittab;
    WczytTab wczyttab;
    MacierzInc macierzInc;
    ListaKraw listaKraw;
    Kruskal kruskal;
    Prima prima;
    Dijkstra dijkstra;
    BellmanFord bellmanFord;
    int e, v;
    float gestosc;
    clock_t started;
    clock_t ended;
    double duration;
    vector<vector<int>> macierz;
    vector<vector<int>> lista;
    vector<int> wagiMatrix;
    vector<int> wagiLista;
    void initMenu();
private:
    void enter();
    void inicjujMenuSkier();
    void end();
    void inicjujMenuNieSkier();

};


#endif //PROJEKTAIZO2_MENU_H
