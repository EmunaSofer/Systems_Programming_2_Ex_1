//emuna002@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.h"
#include "Algorithms.h"

using namespace graph;  
using namespace std;

TEST_CASE("Testing BFS") {
    // יצירת גרף לדוגמה
    Graph* graph = new Graph(5);
    graph->addEdge(0, 1, 10);
    graph->addEdge(0, 4, 20);
    graph->addEdge(1, 2, 5);
    graph->addEdge(1, 3, 7);
    graph->addEdge(2, 3, 2);
    graph->addEdge(3, 4, 1);

    Algorithms* algo = new Algorithms(graph, 0);

    // הרצת אלגוריתם BFS וקבלת עץ
    Graph* bfs_tree = algo->bfs();

    // הדפסת העץ שהתקבל (אם יש לך printGraph או print_graph)
    bfs_tree->printGraph();

    delete graph;
    delete bfs_tree;
    delete algo;
}

TEST_CASE("Testing DFS") {
    // יצירת גרף לדוגמה
    Graph* graph = new Graph(5);
    graph->addEdge(0, 1, 10);
    graph->addEdge(0, 4, 20);
    graph->addEdge(1, 2, 5);
    graph->addEdge(1, 3, 7);
    graph->addEdge(2, 3, 2);
    graph->addEdge(3, 4, 1);

    Algorithms* algo = new Algorithms(graph, 0);

    // הרצת אלגוריתם DFS וקבלת עץ
    Graph* dfs_tree = algo->dfs();

    // הדפסת העץ שהתקבל
    dfs_tree->printGraph();

    delete graph;
    delete dfs_tree;
    delete algo;
}

TEST_CASE("Testing Dijkstra") {
    Graph* graph = new Graph(5);
    graph->addEdge(0, 1, 10);
    graph->addEdge(0, 4, 3);
    graph->addEdge(1, 2, 2);
    graph->addEdge(1, 4, 4);
    graph->addEdge(2, 3, 9);
    graph->addEdge(3, 2, 7);
    graph->addEdge(4, 1, 1);
    graph->addEdge(4, 2, 8);
    graph->addEdge(4, 3, 2);

    Algorithms* algo = new Algorithms(graph, 0);
    Graph* result = algo->dijkstra();

    CHECK(result != nullptr); // לוודא שהגרף הוחזר

    delete result;
    delete algo;
    delete graph;
}

TEST_CASE("Testing Prim") {
    Graph* graph = new Graph(5);
    graph->addEdge(0, 1, 2);
    graph->addEdge(0, 3, 6);
    graph->addEdge(1, 2, 3);
    graph->addEdge(1, 3, 8);
    graph->addEdge(1, 4, 5);
    graph->addEdge(2, 4, 7);
    graph->addEdge(3, 4, 9);

    Algorithms* algo = new Algorithms(graph, 0);
    Graph* mst = algo->prim();

    CHECK(mst != nullptr); // לוודא שהוחזר גרף תקף

    delete mst;
    delete algo;
    delete graph;
}

TEST_CASE("Testing Kruskal") {
    Graph* graph = new Graph(6);
    graph->addEdge(0, 1, 4);
    graph->addEdge(0, 2, 4);
    graph->addEdge(1, 2, 2);
    graph->addEdge(1, 0, 4);
    graph->addEdge(2, 0, 4);
    graph->addEdge(2, 1, 2);
    graph->addEdge(2, 3, 3);
    graph->addEdge(2, 5, 2);
    graph->addEdge(2, 4, 4);
    graph->addEdge(3, 2, 3);
    graph->addEdge(3, 4, 3);
    graph->addEdge(4, 2, 4);
    graph->addEdge(4, 3, 3);
    graph->addEdge(5, 2, 2);
    graph->addEdge(5, 4, 3);

    Algorithms* algo = new Algorithms(graph, 0);
    Graph* mst = algo->kruskal();

    CHECK(mst != nullptr); // לוודא שהוחזר גרף תקף

    delete mst;
    delete algo;
    delete graph;
}