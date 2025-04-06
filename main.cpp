//emuna002@gmail.com
#include "Graph.h"
#include "Algorithms.h"
#include <iostream>

using namespace graph;
using namespace std;

int main() {
    // יצירת גרף עם 5 קודקודים
    Graph* g = new Graph(5);
    g->addEdge(0, 1, 10);
    g->addEdge(0, 4, 20);
    g->addEdge(1, 2, 5);
    g->addEdge(1, 3, 7);
    g->addEdge(2, 3, 2);
    g->addEdge(3, 4, 1);

    // הדפסת הגרף
    cout << "Graph representation:" << endl;
    g->printGraph();
    // הרצת אלגוריתם BFS
    Algorithms algo(g, 0);
    Graph* bfs_tree = algo.bfs();
    cout << "\nBFS Tree from node 0:" << endl;
    bfs_tree->printGraph();
    delete bfs_tree;

    // הרצת אלגוריתם DFS
    Graph* dfs_tree = algo.dfs();
    cout << "\nDFS Tree from node 0:" << endl;
    dfs_tree->printGraph();
    delete dfs_tree;

    // הרצת אלגוריתם Dijkstra
    Graph* dijkstra_tree = algo.dijkstra();
    cout << "\nDijkstra Tree from node 0:" << endl;
    dijkstra_tree->printGraph();
    delete dijkstra_tree;

    // הרצת אלגוריתם Prim
    Graph* prim_tree = algo.prim();
    cout << "\nPrim Minimum Spanning Tree:" << endl;
    prim_tree->printGraph();
    delete prim_tree;

    // הרצת אלגוריתם Kruskal
    Graph* kruskal_tree = algo.kruskal();
    cout << "\nKruskal Minimum Spanning Tree:" << endl;
    kruskal_tree->printGraph();
    delete kruskal_tree;

    // שחרור זיכרון
    delete g;

    return 0;
}
