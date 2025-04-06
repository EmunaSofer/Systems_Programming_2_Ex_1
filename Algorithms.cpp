//emuna002@gmail.com
#include <iostream>
#include <climits>
#include "Algorithms.h"
#include "Queue.h"
using namespace std;

Algorithms::Algorithms(graph::Graph* G, int start)
{
    graph = G;
    this->start = G->getVertex(start);  // בצבעה על הקודקוד הראש
}
Algorithms::~Algorithms()
{
    // אין צורך בשחרור של start כי זה מנוהל ב-Graph
}

void Algorithms::resetVisited()
{
    for (int i = 0; i < graph->getNumber(); i++)
    {
        Point* current = graph->getVertex(i);
        while (current != nullptr)
        {
            current->setVisited(false);
            current = current->getNext();
        }
    }
}

graph::Graph* Algorithms::bfs() {
    Queue q;
    resetVisited();

    int startId = start->getId();
    graph::Graph* tree = new graph::Graph(graph->getNumber());//העץ המוחזר 

    graph->getVertex(startId)->setVisited(true);
    q.add(startId);

    while (!q.isEmpty()) {
        int v = q.theFirst()->getValue();
        q.remove();

        Point* neighbor = graph->getVertex(v);
        while (neighbor != nullptr) {
            int neighborId = neighbor->getId();
            if (!graph->getVertex(neighborId)->isVisited()) {
                graph->getVertex(neighborId)->setVisited(true);
                q.add(neighborId);

                // מוסיפים את הצלע לעץ
                tree->addEdge(v, neighborId);
            }
            neighbor = neighbor->getNext();
        }
    }

    return tree;
}

void dfsRecursive(graph::Graph* original, graph::Graph* tree, int v) {
    original->getVertex(v)->setVisited(true);

    Point* neighbor = original->getVertex(v);
    while (neighbor != nullptr) {
        int neighborId = neighbor->getId();
        if (!original->getVertex(neighborId)->isVisited()) {
            // מוסיפים את הצלע לעץ
            tree->addEdge(v, neighborId);
            dfsRecursive(original, tree, neighborId);
        }
        neighbor = neighbor->getNext();
    }
}

graph::Graph* Algorithms::dfs() {
    resetVisited();
    int startId = start->getId();
    graph::Graph* tree = new graph::Graph(graph->getNumber());

    dfsRecursive(graph, tree, startId);

    return tree;
}

graph::Graph* Algorithms::dijkstra() {
    int numVertices = graph->getNumber();
    int* distance = new int[numVertices];  // מערך מרחקים
    bool* visited = new bool[numVertices];  // מערך לבדיקת ביקור
    for (int i = 0; i < numVertices; i++) {
        distance[i] = INT_MAX;  // אתחול כל המרחקים לאינסוף
        visited[i] = false;     // כל הקודקודים לא בוקרים בהתחלה
    }
    distance[start->getId()] = 0;  // המרחק מהקודקוד ההתחלתי הוא 0

    // חיפוש הכי קצר עד שיבוקרו כל הקודקודים
    for (int i = 0; i < numVertices; i++) {
        // מציאת הקודקוד עם המרחק הקטן ביותר שעדיין לא בוקר
        int u = -1;
        for (int j = 0; j < numVertices; j++) {
            if (!visited[j] && (u == -1 || distance[j] < distance[u])) {
                u = j;
            }
        }

        if (distance[u] == INT_MAX) {
            break;  // לא ניתן להמשיך כי כל שאר הקודקודים לא נגישים
        }

        // סימון הקודקוד כביקר
        visited[u] = true;

        // עדכון המרחקים לשכנים של הקודקוד הנוכחי
        Point* neighbor = graph->getVertex(u)->getNext();
        while (neighbor != nullptr) {
            int v = neighbor->getId();
            int weight = neighbor->getWeight();

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;  // עדכון המרחק
            }
            neighbor = neighbor->getNext();
        }
    }

    // יצירת עץ גרף חדש עם הקודקודים והקשתות הקצרות ביותר
    graph::Graph* result = new graph::Graph(numVertices);
    for (int i = 0; i < numVertices; i++) {
        if (distance[i] != INT_MAX) {
            // יצירת קשת אם המרחק לא אינסופי (כלומר יש אפשרות להגיע)
            Point* neighbor = graph->getVertex(i)->getNext();
            while (neighbor != nullptr) {
                int v = neighbor->getId();
                int weight = neighbor->getWeight();
                if (distance[i] + weight == distance[v]) {
                    result->addEdge(i, v, weight);  // הוספת הקשת לעץ
                }
                neighbor = neighbor->getNext();
            }
        }
    }

    delete[] distance;  // שחרור זיכרון של המערך
    delete[] visited;   // שחרור זיכרון של המערך

    return result;
}

graph::Graph* Algorithms::prim() {
    int numVertices = graph->getNumber();
    graph::Graph* mst = new graph::Graph(numVertices); // הגרף המינימלי שנחזיר
    bool* inMST = new bool[numVertices]{false};
    int* minEdge = new int[numVertices];
    int* parent = new int[numVertices];
    
    for (int i = 0; i < numVertices; i++) {
        minEdge[i] = INT_MAX;
        parent[i] = -1;
    }
    
    minEdge[0] = 0;
    
    for (int i = 0; i < numVertices; i++) {
        int u = -1;
        for (int j = 0; j < numVertices; j++) {
            if (!inMST[j] && (u == -1 || minEdge[j] < minEdge[u])) {
                u = j;
            }
        }
        
        if (minEdge[u] == INT_MAX) break; // הגרף לא קשיר
        
        inMST[u] = true;
        
        if (parent[u] != -1) {
            mst->addEdge(parent[u], u, minEdge[u]);
        }
        
        Point* neighbor = graph->getVertex(u);
        while (neighbor) {
            int v = neighbor->getId();
            if (!inMST[v] && neighbor->getWeight() < minEdge[v]) {
                minEdge[v] = neighbor->getWeight();
                parent[v] = u;
            }
            neighbor = neighbor->getNext();
        }
    }
    
    delete[] inMST;
    delete[] minEdge;
    delete[] parent;
    return mst;
}

graph::Graph* Algorithms::kruskal() 
{
    int numVertices = graph->getNumber();
    graph::Graph* mst = new graph::Graph(numVertices); // יצירת גרף חדש לאחסון העץ הפורש המינימלי

    int* parent = new int[numVertices];
    for (int i = 0; i < numVertices; i++) {
        parent[i] = i; // כל קודקוד הוא בתחילה קבוצה נפרדת
    }

    // פונקציה למציאת השורש של קודקוד
    auto find = [&](int v) {
        while (parent[v] != v) {
            v = parent[v];
        }
        return v;
    };

    // פונקציה לאיחוד שתי קבוצות
    auto unionSets = [&](int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        parent[rootV] = rootU;
    };

    // הוספת כל הקשתות למערך זמני
    int edgesCount = 0;
    for (int i = 0; i < numVertices; i++) {
        Point* current = graph->getVertex(i);
        while (current) {
            if (i < current->getId()) { // כדי למנוע כפילויות
                edgesCount++;
            }
            current = current->getNext();
        }
    }

    int* edges = new int[edgesCount * 3]; // נשמור את הקשתות כשלשות (src, dest, weight)
    int index = 0;
    for (int i = 0; i < numVertices; i++) {
        Point* current = graph->getVertex(i);
        while (current) {
            if (i < current->getId()) { // כדי למנוע כפילויות
                edges[index] = i;
                edges[index + 1] = current->getId();
                edges[index + 2] = current->getWeight();
                index += 3;
            }
            current = current->getNext();
        }
    }

    // מיון הקשתות לפי המשקל (מיון בחירה פשוט)
    for (int i = 0; i < edgesCount - 1; i++) {
        for (int j = i + 1; j < edgesCount; j++) {
            if (edges[i * 3 + 2] > edges[j * 3 + 2]) {
                swap(edges[i * 3], edges[j * 3]);
                swap(edges[i * 3 + 1], edges[j * 3 + 1]);
                swap(edges[i * 3 + 2], edges[j * 3 + 2]);
            }
        }
    }

    // מעבר על הקשתות ובחירה של אלו שלא יוצרות מעגלים
    for (int i = 0; i < edgesCount; i++) {
        int u = edges[i * 3];
        int v = edges[i * 3 + 1];
        int weight = edges[i * 3 + 2];

        if (find(u) != find(v)) {
            mst->addEdge(u, v, weight);
            unionSets(u, v);
        }
    }

    delete[] parent;
    delete[] edges;
    return mst;
}
