//
// Created by mikus on 31.05.2024.
//

#include "Kruskal.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Kruskal::mstKruskalMatrix(vector<vector<int>>& macierz,vector<int>& wagi) {
    int V = macierz.size(); // liczba wierzchołków
    int E = wagi.size(); // liczba krawędzi
    int suma = 0;
    vector<Data::struktura> edges(E);

    // Tworzenie listy krawędzi z macierzy incydencji i wag
    int edgeIndex = 0;
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
        edges[edgeIndex].started = u;
        edges[edgeIndex].ended = v;
        edges[edgeIndex].weight = wagi[j];
        edgeIndex++;
    }

    // Sortowanie krawędzi według wag
    sort(edges.begin(), edges.end(), [](const Data::struktura& a, const Data::struktura& b) {
        return a.weight < b.weight;
    });

    // Inicjalizacja zbiorów (Union-Find)
    vector<Data::subnet> subsets(V);
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    cout << "Minimalne Drzewo Rozpinajace dla Macierzy Incydencji (Kruskal):\n";
    for (int i = 0, e = 0; e < V - 1 && i < E; i++) {
        Data::struktura nextEdge = edges[i];
        int x = szukaj(subsets, nextEdge.started);
        int y = szukaj(subsets, nextEdge.ended);

        // Sprawdzanie czy dodanie tej krawędzi nie spowoduje cyklu
        if (x != y) {
            cout << "Krawedz " << nextEdge.started << " -- " << nextEdge.ended << " == " << nextEdge.weight << "\n";
            laczZbiory(subsets, x, y);
            e++;
            suma+=nextEdge.weight;
        }
    }
    cout<<"Suma wag krawedzi to: "<<suma<<endl;
}

void Kruskal::mstKruskalList(const vector<vector<int>>& lista, vector<int>& wagi) {
    int V = lista.size(); // liczba wierzchołków
    int suma = 0;
    vector<Data::struktura> edges;

    // Tworzenie listy krawędzi z listy sąsiedztwa i wag
    int weightIndex = 0;
    for (int u = 0; u < V; ++u) {
        for (int v : lista[u]) {
            if (u < v) { // Aby uniknąć dodawania tej samej krawędzi dwa razy
                edges.push_back({u, v, wagi[weightIndex]});
            }
            ++weightIndex;
        }
    }

    // Sortowanie krawędzi według wag
    sort(edges.begin(), edges.end(), [](const Data::struktura& a, const Data::struktura& b) {
        return a.weight < b.weight;
    });

    // Inicjalizacja zbiorów (Union-Find)
    std::vector<Data::subnet> subsets(V);
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    std::cout << "Minimalne Drzewo Rozpinajace dla Listy Nastepnikow/Poprzednikow (Kruskal):\n";
    for (const auto& edge : edges) {
        int x = szukaj(subsets, edge.started);
        int y = szukaj(subsets, edge.ended);

        // Sprawdzanie czy dodanie tej krawędzi nie spowoduje cyklu
        if (x != y) {
            cout << "Krawedz " << edge.started << " -- " << edge.ended << " == " << edge.weight << "\n";
            laczZbiory(subsets, x, y);
            suma+=edge.weight;
        }
    }
    cout<<"Suma wag krawedzi to: "<<suma<<endl;
}

int Kruskal::szukaj(vector<Data::subnet>& subsets, int i) { //znajduje rekurencyjnie to co chcemy ze zbioru
    if (subsets[i].parent != i) {
        subsets[i].parent = szukaj(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
void Kruskal::laczZbiory(vector<Data::subnet>& subsets, int x, int y) { //łączy dwa zbiory, znajduje oba elementy ze zbiorów i łączy mniejszy zbiór z większym, dla zminimalizowania wysokości drzewa
    int rootX = szukaj(subsets, x);
    int rootY = szukaj(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}