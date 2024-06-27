//
// Created by mikus on 29.05.2024.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "Data.h"
#include "InitTab.h"

using namespace std;


void InitTab::dodajStrukturySkierowane(vector<Data::struktura>& tablica,int e, int v) {
    srand((unsigned )time(NULL));
    Data::struktura nowaStruktura;
    int tempstart;
    int tempend;
    int circle = 0;
    for (int i = 0; i < v; ++i) {
        if(i==0){
            nowaStruktura.started = 0;
            nowaStruktura.ended = e-1;
            nowaStruktura.weight = (rand()%10)+1;
            tempend = e-1;
        }
        else{
            nowaStruktura.started = tempstart;
            nowaStruktura.ended = tempend;
            nowaStruktura.weight = (rand()%10)+1;

            while (istniejeStruktura(tablica, nowaStruktura) || nowaStruktura.started==nowaStruktura.ended) {
                if(circle==e){
                    nowaStruktura.started = (rand()%e);
                    nowaStruktura.ended = (rand()%e);
                    nowaStruktura.weight = (rand()%10)+1;
                    circle = 0;
                }
                else{
                    nowaStruktura.started = tempstart;
                    nowaStruktura.ended = (rand()%e);
                    nowaStruktura.weight = (rand()%10)+1;
                    circle+=1;
                }
            }
        }
        tempstart = nowaStruktura.ended;
        if(tempend-1!=-1){
            tempend-=1;
        }
        else{
            tempend = (rand()%e);
        }

        tablica.push_back(nowaStruktura);
    }
}

void InitTab::dodajStrukturyNieskierowane(vector<Data::struktura>& tablica,int e, int v) {
    dodajStrukturySkierowane(tablica,e,v);
    Data::struktura nowaStruktura;
    for (auto& struktura : tablica) {
        nowaStruktura.started = struktura.ended;
        nowaStruktura.ended = struktura.started;
        nowaStruktura.weight = struktura.weight;
        tablica.push_back(nowaStruktura);
    }

}

bool InitTab::istniejeStruktura(const vector<Data::struktura>& tablica, const Data::struktura& nowaStruktura) {
    return any_of(tablica.begin(), tablica.end(), [&nowaStruktura](const Data::struktura& struktura) {
        return (struktura.started == nowaStruktura.started && struktura.ended == nowaStruktura.ended) ||
               (struktura.started == nowaStruktura.ended && struktura.ended == nowaStruktura.started);
    });
}

