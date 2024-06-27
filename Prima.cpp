//
// Created by mikus on 01.06.2024.
//

#include "Prima.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void Prima::mstPrimaMatrix(vector<vector<int>>& macierz, vector<int>& wagi) {
    int V = macierz.size(); // liczba wierzchołków
    int E = wagi.size(); // liczba krawędzi
    int suma = 0; // Inicjalizacja zmiennej suma

    // Tworzenie listy sąsiedztwa z macierzy incydencji i wag
    vector<vector<pair<int, int>>> adj(V);
    for (int j = 0; j < E; j++) {
        int u = -1, v = -1;
        for (int i = 0; i < V; i++) {
            if (macierz[i][j] == 1) {
                if (u == -1) {
                    u = i;
                } else {
                    v = i;
                    break;
                }
            }
        }
        if (u != -1 && v != -1) {
            adj[u].emplace_back(v, wagi[j]);
            adj[v].emplace_back(u, wagi[j]);
        }
    }

    // Tablice używane w algorytmie Prima
    vector<int> parent(V, -1); // Przechowuje MST
    vector<int> key(V, INT_MAX); // Najmniejsze wagi krawędzi
    vector<bool> inMST(V, false); // Wierzchołki w MST

    // Priorytetowa kolejka do wyboru krawędzi o najmniejszej wadze
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> priorytet;

    // Startujemy od wierzchołka 0
    priorytet.emplace(0, 0);
    key[0] = 0;

    while (!priorytet.empty()) {
        int u = priorytet.top().second;
        priorytet.pop();

        inMST[u] = true;

        // Przeglądanie wszystkich sąsiadów wierzchołka u
        for (auto& [v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                priorytet.emplace(key[v], v);
                parent[v] = u;
            }
        }
    }

    cout << "Minimalne Drzewo Rozpinajace dla Macierzy Incydencji (Prima):\n";
    for (int i = 1; i < V; ++i) {
        if (parent[i] != -1) { // Upewnij się, że krawędź istnieje
            cout << "Krawedz " << parent[i] << " -- " << i << " == " << key[i] << "\n";
            suma += key[i];
        }
    }
    cout << "Suma wag krawedzi to: " << suma << endl;
}

void Prima::mstPrimaList(const vector<vector<int>>& lista, vector<int>& wagi) {
    int suma = 0;
    int V = lista.size(); // liczba wierzchołków
    vector<vector<pair<int, int>>> adj(V);

    // Tworzenie listy sąsiedztwa z wagami
    int weightIndex = 0;
    for (int u = 0; u < V; ++u) {
        for (int v : lista[u]) {
            adj[u].emplace_back(v, wagi[weightIndex]);
            ++weightIndex;
        }
    }

    // Tablice używane w algorytmie Prima
    vector<int> parent(V, -1); // Przechowuje MST
    vector<int> key(V, INT_MAX); // Najmniejsze wagi krawędzi
    vector<bool> inMST(V, false); // Wierzchołki w MST

    // Priorytetowa kolejka do wyboru krawędzi o najmniejszej wadze
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // Startujemy od wierzchołka 0
    pq.emplace(0, 0);
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        // Przeglądanie wszystkich sąsiadów wierzchołka u
        for (auto& [v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.emplace(key[v], v);
                parent[v] = u;
            }
        }
    }

    cout << "Minimalne Drzewo Rozpinajace dla Listy Nastepnikow/Poprzednikow (Prim):\n";
    for (int i = 1; i < V; ++i) {
        cout << "Krawedz " << parent[i] << " -- " << i << " == " << key[i] << "\n";
        suma += key[i];
    }
    cout<<"Suma wag krawedzi to: "<<suma<<endl;
}