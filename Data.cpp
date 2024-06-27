//
// Created by mikus on 29.05.2024.
//


#include <iostream>
#include <vector>
#include "Data.h"

using namespace std;

void Data::wyswietlStrukture(vector<struktura>& tab) {
    for (auto& struktura : tab) {
        cout << struktura.started << " " << struktura.ended << " " << struktura.weight<<endl;
    }
}