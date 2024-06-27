//
// Created by mikus on 02.06.2024.
//

#include "BellmanFord.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

void BellmanFord::bellmanFordMatrix(const vector<vector<int>>& incidenceMatrix, const vector<int>& weights, int src, int E, int V) {
    // Vector przechowujący najkrótsze odległości od źródła do każdego wierzchołka
    vector<int> dist(E, INF);

    // Wierzchołki w aktualnej drodze
    vector<int> path(E, -1);

    // Odległość od źródła do samego siebie to 0
    dist[src] = 0;

    // Relaksacja wszystkich krawędzi V-1 razy
    for (int i = 1; i <= E - 1; ++i) {
        for (int u = 0; u < E; ++u) {
            for (int e = 0; e < V; ++e) {
                if (incidenceMatrix[u][e] == 1) {  // Krawędź wychodząca z u
                    for (int v = 0; v < E; ++v) {
                        if (incidenceMatrix[v][e] == -1) {  // Krawędź wchodząca do v
                            if (dist[u] != INF && dist[u] + weights[e] < dist[v]) {
                                dist[v] = dist[u] + weights[e];
                                path[v] = u; // aktualizacja ścieżki
                            }
                        }
                    }
                }
            }
        }
    }

    // Sprawdzanie cykli o ujemnej wadze
    for (int u = 0; u < E; ++u) {
        for (int e = 0; e < V; ++e) {
            if (incidenceMatrix[u][e] == 1) {  // Krawędź wychodząca z u
                for (int v = 0; v < E; ++v) {
                    if (incidenceMatrix[v][e] == -1) {  // Krawędź wchodząca do v
                        if (dist[u] != INF && dist[u] + weights[e] < dist[v]) {
                            cout << "Graf zawiera ujemny cykl wagowy" << endl;
                            return;
                        }
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

void BellmanFord::bellmanFordList(const vector<vector<int>>& adjList, const vector<int>& weights, int src, int E, int V) {
    // Vector przechowujący najkrótsze odległości od źródła do każdego wierzchołka
    vector<int> dist(E, INF);

    // Wierzchołki w aktualnej drodze
    vector<int> path(E, -1);

    // Mapa krawędzi na ich wagi
    unordered_map<int, unordered_map<int, int>> edgeWeights;
    int weightIndex = 0;

    // Logowanie inicjalizacji edgeWeights
    cout << "Inicjalizacja edgeWeights..." << endl;

    for (int u = 0; u < adjList.size(); ++u) {
        for (int v : adjList[u]) {
            if (weightIndex < weights.size()) {
                edgeWeights[u][v] = weights[weightIndex++];
            } else {
                cerr << "Błąd: indeks wag wykracza poza rozmiar wektora wag." << endl;
                return;
            }
        }
    }

    // Odległość od źródła do samego siebie to 0
    dist[src] = 0;

    // Relaksacja wszystkich krawędzi V-1 razy
    for (int i = 1; i <= E - 1; ++i) {
        for (int u = 0; u < adjList.size(); ++u) { // changed V to adjList.size()
            for (int v : adjList[u]) {
                if (edgeWeights[u].find(v) != edgeWeights[u].end()) {
                    int weight = edgeWeights[u][v];
                    if (dist[u] != INF && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        path[v] = u; // aktualizacja ścieżki
                    }
                }
            }
        }
    }

    // Sprawdzanie cykli o ujemnej wadze
    for (int u = 0; u < adjList.size(); ++u) { // changed V to adjList.size()
        for (int v : adjList[u]) {
            if (edgeWeights[u].find(v) != edgeWeights[u].end()) {
                int weight = edgeWeights[u][v];
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    cout << "Graf zawiera ujemny cykl wagowy" << endl;
                    return;
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
void BellmanFord::printPath(const vector<int>& path, int E) {
    if (E == -1)
        return;
    printPath(path, path[E]);
    if (path[E] != -1) cout << " ";
    cout << E;
}