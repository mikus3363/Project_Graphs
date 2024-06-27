//
// Created by mikus on 02.06.2024.
//

#ifndef PROJEKTAIZO2_BELLMANFORD_H
#define PROJEKTAIZO2_BELLMANFORD_H

#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class BellmanFord {
public:
    void bellmanFordMatrix(const vector<vector<int>>& incidenceMatrix, const vector<int>& weights, int src, int E, int V);
    void bellmanFordList(const vector<vector<int>>& adjList, const vector<int>& weights, int src, int E, int V);
private:
    const int INF = INT_MAX;
    void printPath(const vector<int>& path, int v);
};


#endif //PROJEKTAIZO2_BELLMANFORD_H
