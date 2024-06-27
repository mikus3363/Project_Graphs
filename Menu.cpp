//
// Created by mikus on 02.06.2024.
//

#include "Menu.h"
#include <iostream>
#include <cstdlib>
#include <chrono>

void Menu::initMenu(){
    cout << "Autor : Mikolaj Lipinski \n" << endl;
    int x = 0, kon = 1;
    do
    {
        cout << "MENU Glowne" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1.Wczytanie struktury grafu z pliku tekstowego dane.txt jako graf skierowany" << endl;
        cout << "2.Wczytanie struktury grafu z pliku tekstowego dane.txt jako graf nieskierowany" << endl;
        cout << "3.Losowe wygenerowanie grafu skierowane (najkrotsza sciezka w grafie)" << endl;
        cout << "4.Losowe wygenerowanie grafu nieskierowane (MST)" << endl;
        cout << "5.Wyjdz z programu" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> x;
        switch (x)
        {
            case 1:
                cout << endl;
                end();
                e = wczyttab.wczytajZakres("C:\\Users\\mikus\\OneDrive\\Pulpit\\Projekty\\ProjektAIZO2\\dane.txt");
                v = wczyttab.wczytajLiczbeStruktur("C:\\Users\\mikus\\OneDrive\\Pulpit\\Projekty\\ProjektAIZO2\\dane.txt");
                wczyttab.zakres = e;
                wczyttab.liczbaStruktur = v;
                wczyttab.wczytajZPliku("C:\\Users\\mikus\\OneDrive\\Pulpit\\Projekty\\ProjektAIZO2\\dane.txt",tab);
                macierz = vector<vector<int>>(e, vector<int>(v));
                macierzInc.createMatrix(tab,e,1,macierz,wagiMatrix);
                listaKraw.createList(tab,e,1,lista,wagiLista);
                inicjujMenuSkier();
                enter();
                break;
            case 2:
                cout << endl;
                end();
                e = wczyttab.wczytajZakres("C:\\Users\\mikus\\OneDrive\\Pulpit\\Projekty\\ProjektAIZO2\\dane.txt");
                v = wczyttab.wczytajLiczbeStruktur("C:\\Users\\mikus\\OneDrive\\Pulpit\\Projekty\\ProjektAIZO2\\dane.txt");
                wczyttab.zakres = e;
                wczyttab.liczbaStruktur = v;
                wczyttab.wczytajZPliku("C:\\Users\\mikus\\OneDrive\\Pulpit\\Projekty\\ProjektAIZO2\\dane.txt",tab);
                macierz = vector<vector<int>>(e, vector<int>(v));
                macierzInc.createMatrix(tab,e,0,macierz,wagiMatrix);
                listaKraw.createList(tab,e,0,lista,wagiLista);
                inicjujMenuNieSkier();
                enter();
                break;
            case 3:
                cout << endl;
                end();
                cout<<"Podaj liczbe wierzcholkow E: "<<endl;
                cin>>e;
                cout<<"Podaj gestosc %: "<<endl;
                cin>>gestosc;

                v = ((gestosc/100)*e*(e-1))/2;
                inittab.dodajStrukturySkierowane(tab,e,v);
                macierz = vector<vector<int>>(e, vector<int>(v));
                macierzInc.createMatrix(tab,e,1,macierz,wagiMatrix);
                listaKraw.createList(tab,e,1,lista,wagiLista);
                inicjujMenuSkier();
                enter();
                break;
            case 4:
                cout << endl;
                end();
                cout<<"Podaj liczbe wierzcholkow E: "<<endl;
                cin>>e;
                cout<<"Podaj gestosc %: "<<endl;
                cin>>gestosc;

                v = ((gestosc/100)*e*(e-1))/2;
                //inittab.dodajStrukturyNieskierowane(tab,1,1);
                inittab.dodajStrukturyNieskierowane(tab,e,v);
                macierz = vector<vector<int>>(e, vector<int>(v));
                macierzInc.createMatrix(tab,e,0,macierz,wagiMatrix);
                listaKraw.createList(tab,e,0,lista,wagiLista);
                inicjujMenuNieSkier();
                enter();
                break;
            case 5:
                cout << endl;
                kon = 0;
                end();
                exit(1);
                break;
            default:
                cout << endl;
                cout << "Podano zla wartosc" << endl << endl;
                enter();
                break;
        }
    } while (kon == 1);
}

void Menu::inicjujMenuSkier() { //zainicjowanie Menu odpowiedzialnego za wykonywanie operacji na zmiennych typu int
    int x = 0, kon = 1;
    do
    {
        cout << "MENU Skierowana" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1.Wyswietl graf" << endl;
        cout << "2.Wygeneruj graf w formie reprezentacji macierzy incydencji " << endl;
        cout << "3.Wygeneruj graf w formie reprezentacji listowej " << endl;
        cout << "4.Wyznaczanie najkrotszej sciezki w grafie dla macierzy(algorytm Dijkstry) " << endl;
        cout << "5.Wyznaczanie najkrotszej sciezki w grafie dla macierzy(algorytm Forda-Bellmana) " << endl;
        cout << "6.Wyznaczanie najkrotszej sciezki w grafie dla listy(algorytm Dijkstry) " << endl;
        cout << "7.Wyznaczanie najkrotszej sciezki w grafie dla listy(algorytm Forda-Bellmana) " << endl;
        cout << "8.Wroc" << endl;
        cout << "9.Wyjdz z programu" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> x;
        switch (x)
        {
            case 1:
                cout << endl;
                Data::wyswietlStrukture(tab);
                enter();
                break;
            case 2:
                cout << endl;
                cout<<"Skierowana Macierz Incydencji: "<<endl;
                macierzInc.wysMacierz(macierz,e,v);
                macierzInc.wysWagi(wagiMatrix);
                enter();
                break;
            case 3:
                cout << endl;
                cout<<"Skierowana Lista Sasiadow: "<<endl;
                listaKraw.wysListe(lista);
                listaKraw.wysWagi(wagiMatrix);
                enter();
                break;
            case 4:
                cout << endl;
                started = clock();
                dijkstra.dijkstraMatrix(macierz,wagiMatrix,0,e,v);
                ended = clock();
                duration = 1000.0 * (ended - started)/CLOCKS_PER_SEC;
                cout << "Czas wykonania: " << duration << " ms" << endl;
                enter();
                break;
            case 5:
                cout << endl;
                started = clock();
                bellmanFord.bellmanFordMatrix(macierz,wagiMatrix,0,e,v);
                ended = clock();
                duration = 1000.0 * (ended - started)/CLOCKS_PER_SEC;
                cout << "Czas wykonania: " << duration << " ms" << endl;
                enter();
                break;
            case 6:
                cout << endl;
                started = clock();
                dijkstra.dijkstraList(lista,wagiLista,0,e,v);
                ended = clock();
                duration = 1000.0 * (ended - started)/CLOCKS_PER_SEC;
                cout << "Czas wykonania: " << duration << " ms" << endl;
                enter();
                break;
            case 7:
                cout << endl;
                started = clock();
                bellmanFord.bellmanFordList(lista,wagiLista,0,e,v);
                ended = clock();
                duration = 1000.0 * (ended - started)/CLOCKS_PER_SEC;
                cout << "Czas wykonania: " << duration << " ms" << endl;
                enter();
                break;
            case 8:
                cout << endl;
                initMenu();
                break;
            case 9:
                cout << endl;
                kon = 0;
                end();
                exit(1);
                break;
            default:
                cout << endl;
                cout << "Podano zla wartosc" << endl << endl;
                enter();
                break;
        }
    } while (kon == 1);
}

void Menu::inicjujMenuNieSkier() { //zainicjowanie Menu odpowiedzialnego za wykonywanie operacji na zmiennych typu int
    int x = 0, kon = 1;
    do
    {
        cout << "MENU Nieskierowana" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1.Wyswietl graf" << endl;
        cout << "2.Wygeneruj graf w formie reprezentacji macierzy incydencji " << endl;
        cout << "3.Wygeneruj graf w formie reprezentacji listowej " << endl;
        cout << "4.Wyznaczanie minimalnego drzewa rozpinajacego dla macierzy(algorytm Prima) " << endl;
        cout << "5.Wyznaczanie minimalnego drzewa rozpinajacego dla macierzy(algorytm Kruskala) " << endl;
        cout << "6.Wyznaczanie minimalnego drzewa rozpinajacego dla listy(algorytm Prima) " << endl;
        cout << "7.Wyznaczanie minimalnego drzewa rozpinajacego dla listy(algorytm Kruskala) " << endl;
        cout << "8.Wroc" << endl;
        cout << "9.Wyjdz z programu" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> x;
        switch (x)
        {
            case 1:
                cout << endl;
                Data::wyswietlStrukture(tab);
                enter();
                break;
            case 2:
                cout << endl;
                cout<<"Nieskierowana Macierz Incydencji: "<<endl;
                macierzInc.wysMacierz(macierz,e,v);
                macierzInc.wysWagi(wagiMatrix);
                enter();
                break;
            case 3:
                cout << endl;
                cout<<"Nieskierowana Lista Sasiadow: "<<endl;
                listaKraw.wysListe(lista);
                listaKraw.wysWagi(wagiLista);
                enter();
                break;
            case 4:
                cout << endl;
                started = clock();
                prima.mstPrimaMatrix(macierz,wagiMatrix);
                ended = clock();
                duration = 1000.0 * (ended - started)/CLOCKS_PER_SEC;
                cout << "Czas wykonania: " << duration << " ms" << endl;
                enter();
                break;
            case 5:
                cout << endl;
                started = clock();
                kruskal.mstKruskalMatrix(macierz,wagiMatrix);
                ended = clock();
                duration = 1000.0 * (ended - started)/CLOCKS_PER_SEC;
                cout << "Czas wykonania: " << duration << " ms" << endl;
                enter();
                break;
            case 6:
                cout << endl;
                started = clock();
                prima.mstPrimaList(lista,wagiLista);
                ended = clock();
                duration = 1000.0 * (ended - started)/CLOCKS_PER_SEC;
                cout << "Czas wykonania: " << duration << " ms" << endl;
                enter();
                break;
            case 7:
                cout << endl;
                started = clock();
                kruskal.mstKruskalList(lista,wagiLista);
                ended = clock();
                duration = 1000.0 * (ended - started)/CLOCKS_PER_SEC;
                cout << "Czas wykonania: " << duration << " ms" << endl;
                enter();
                break;
            case 8:
                cout << endl;
                initMenu();
                break;
            case 9:
                cout << endl;
                kon = 0;
                end();
                exit(1);
                break;
            default:
                cout << endl;
                cout << "Podano zla wartosc" << endl << endl;
                enter();
                break;
        }
    } while (kon == 1);
}


void Menu::end(){
    tab.clear();
    lista.clear();
    wagiMatrix.clear();
    wagiLista.clear();
    macierz.clear();
    e = 0;
    v = 0;
}

void Menu::enter() {
    cout << "Nacisnij przycisk ENTER aby wrocic do Menu" << endl;
    getchar();
    getchar();
}