//emuna002@gmail.com
#include <iostream>
#include "Graph.h"

using namespace std;

using namespace graph;

Graph::Graph(int numVertices) {
    this->numVertices = numVertices;
    vertices = new Point*[numVertices]; // אתחול מערך הקודקודים
    for (int i = 0; i < numVertices; i++) {
        // יצירת קודקוד עם ID מ-0 עד numVertices-1
        vertices[i] = new Point(i, 0, nullptr); // ה-ID של כל קודקוד הוא האינדקס
    }
}


Graph::~Graph()
{
    // שחרור כל הקודקודים ברשימה
    for (int i = 0; i < numVertices; i++) {
        Point* current = vertices[i];
        while (current != nullptr) {
            Point* temp = current;
            current = current->getNext();
            delete temp;  // שחרור הזיכרון של הקודקוד הנוכחי
        }
    }
    delete[] vertices;  // שחרור המערך של מצביעים
}

void Graph::addEdge(int src, int dest, int weight)
{
    if (src >= numVertices || dest >= numVertices || src < 0 || dest < 0)
    {
        cout << "Error: Invalid edge" << endl;
        return;
    }

    // הוספת קשת src -> dest
    if (vertices[src] == nullptr)
        vertices[src] = new Point(dest, weight);
    else {
        Point* next = vertices[src];
        while (next->getNext() != nullptr)
            next = next->getNext();
        next->setNext(new Point(dest, weight));
    }

    // הוספת קשת dest -> src (גרף לא מכוון)
    if (vertices[dest] == nullptr)
        vertices[dest] = new Point(src, weight);
    else {
        Point* next2 = vertices[dest];
        while (next2->getNext() != nullptr)
            next2 = next2->getNext();
        next2->setNext(new Point(src, weight));
    }
}

void Graph::removeEdge(int src, int dest)
{
    if (src >= numVertices || dest >= numVertices || src < 0 || dest < 0)
    {
        cout << "Error: Invalid edge" << endl;
        return;
    }

    // הסרת קשת src -> dest
    Point* prev = nullptr;
    Point* curr = vertices[src];
    while (curr != nullptr && curr->getId() != dest)
    {
        prev = curr;
        curr = curr->getNext();
    }
    if (curr != nullptr) {
        if (prev)
            prev->setNext(curr->getNext());
        else
            vertices[src] = curr->getNext();
        delete curr;
    }

    // הסרת קשת dest -> src
    prev = nullptr;
    curr = vertices[dest];
    while (curr != nullptr && curr->getId() != src)
    {
        prev = curr;
        curr = curr->getNext();
    }
    if (curr != nullptr) {
        if (prev)
            prev->setNext(curr->getNext());
        else
            vertices[dest] = curr->getNext();
        delete curr;
    }
}

void Graph::printGraph() 
{
    for (int i = 0; i < numVertices; i++) {
        Point* next = vertices[i];
        cout << "Vertex " << i << ": ";
        while (next != nullptr) {
            cout << next->getId() << " -> ";
            next = next->getNext();
        }
        cout << "NULL" << endl;
    }
}

int Graph::getNumber()
{
    return numVertices;
}

Point* Graph::getVertex(int index) {
    return vertices[index]; // פונקציה שתהיה גישה לצומת ספציפי
}
