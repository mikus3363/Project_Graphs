//
// Created by mikus on 29.05.2024.
//

#ifndef PROJEKTAIZO2_INITTAB_H
#define PROJEKTAIZO2_INITTAB_H

class InitTab {
public:
    void dodajStrukturySkierowane(vector<Data::struktura>& tablica, int e, int v);
    void dodajStrukturyNieskierowane(vector<Data::struktura>& tablica,int e, int v);
private:
    bool istniejeStruktura(const vector<Data::struktura>& tablica, const Data::struktura& nowaStruktura);
};


#endif //PROJEKTAIZO2_INITTAB_H
