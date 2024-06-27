//
// Created by mikus on 01.06.2024.
//

#ifndef PROJEKTAIZO2_DIJKSTRA_H
#define PROJEKTAIZO2_DIJKSTRA_H

#include "Data.h"
#include <limits>

class Dijkstra {
public:
    void dijkstraMatrix(const vector<vector<int>>& incidenceMatrix, const vector<int>& weights, int src, int E, int V);
    void dijkstraList(const vector<vector<int>>& adjList, const vector<int>& weights, int src, int E, int V);
private:
    const int INF = numeric_limits<int>::max();
    int minDistance(const vector<int>& dist, const vector<bool>& sptSet, int E);
    void printPath(const vector<int>& path, int E);
};


#endif //PROJEKTAIZO2_DIJKSTRA_H
