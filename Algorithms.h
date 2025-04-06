//emuna002@gmail.com
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.h"  
#include "Point.h"

class Algorithms
{
private:
    graph::Graph* graph;
    Point* start;

public:
    Algorithms(graph::Graph* G, int start);
    ~Algorithms();
    void resetVisited();
    void printPath(int dest);
    graph::Graph* bfs();
    graph::Graph* dfs();
    graph::Graph* dijkstra();
    graph::Graph* prim();
    graph::Graph* kruskal();
};

#endif 