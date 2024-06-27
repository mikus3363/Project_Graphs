//
// Created by mikus on 01.06.2024.
//

#include "Dijkstra.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

void Dijkstra::dijkstraMatrix(const vector<vector<int>>& incidenceMatrix, const vector<int>& weights, int src, int E, int V) {
    // Vector przechowujący najkrótsze odległości od źródła do każdego wierzchołka
    vector<int> dist(E, INF);

    // Wierzchołki w aktualnej drodze
    vector<int> path(E, -1);

    // Zbiór wierzchołków, dla których najkrótsza ścieżka została już znaleziona
    vector<bool> sptSet(E, false);

    // Odległość od źródła do samego siebie to 0
    dist[src] = 0;

    // Znajdowanie najkrótszej ścieżki dla wszystkich wierzchołków
    for (int count = 0; count < E - 1; count++) {
        // Wybierz wierzchołek o minimalnej odległości, który nie został jeszcze przetworzony
        int u = minDistance(dist, sptSet, E);
        // Oznacz wybrany wierzchołek jako przetworzony
        sptSet[u] = true;

        // Aktualizuj wartość dist wierzchołków sąsiadujących z wybranym wierzchołkiem
        for (int i = 0; i < V; i++) {
            if (incidenceMatrix[u][i] == 1) {  // Krawędź wychodząca z u
                for (int v = 0; v < E; v++) {
                    if (incidenceMatrix[v][i] == -1 && !sptSet[v] && dist[u] != INF &&
                        dist[u] + weights[i] < dist[v]) {
                        dist[v] = dist[u] + weights[i];
                        path[v] = u; // aktualizacja ścieżki
                    }
                }
            }
        }
    }
    // Wyświetlenie wyników
    cout << "Wierzcholek \t Odleglosc od zrodla \t Droga" << endl;
    for (int i = 0; i < E; i++) {
        cout << i << " \t\t " << dist[i] << " \t\t\t ";
        printPath(path, i);
        cout << endl;
    }
}
void Dijkstra::printPath(const vector<int>& path, int E) {
    if (E == -1)
        return;
    printPath(path, path[E]);
    cout << E << " ";
}
int Dijkstra::minDistance(const vector<int>& dist, const vector<bool>& sptSet, int V) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void Dijkstra::dijkstraList(const vector<vector<int>>& adjList, const vector<int>& weights, int src, int E, int V) {
    // Vector przechowujący najkrótsze odległości od źródła do każdego wierzchołka
    vector<int> dist(E, INF);

    // Wierzchołki w aktualnej drodze
    vector<int> path(E, -1);

    // Kolejka priorytetowa dla wierzchołków do przetworzenia
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Mapa krawędzi na ich wagi
    unordered_map<int, unordered_map<int, int>> edgeWeights;
    int weightIndex = 0;
    for (int u = 0; u < adjList.size(); ++u) {
        for (int v : adjList[u]) {
            edgeWeights[u][v] = weights[weightIndex++];
        }
    }

    // Odległość od źródła do samego siebie to 0
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Przeglądaj wszystkie wierzchołki sąsiadujące z u
        for (int v : adjList[u]) {
            int weight = edgeWeights[u][v];

            // Jeżeli istnieje krótsza ścieżka do v przez u
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
                path[v] = u; // aktualizacja ścieżki
            }
        }
    }

    // Wyświetlenie wyników
    cout << "Wierzcholek \t Odleglosc od zrodla \t Droga" << endl;
    for (int i = 0; i < E; i++) {
        cout << i << " \t\t " << dist[i] << " \t\t\t ";
        printPath(path, i);
        cout << endl;
    }
}
