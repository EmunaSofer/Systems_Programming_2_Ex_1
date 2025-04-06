//emuna002@gmail.com
#ifndef GRAPH_H
#define GRAPH_H

#include "Point.h"
#include <iostream>

namespace graph 
{
    class Graph {
        private:
        int numVertices; // מספר הקודקודים
        Point** vertices; // מערך של מצביעים לאובייקטים של Point (השכנים)
        
    public:
        Graph(int numVertices); // בונה גרף
        ~Graph(); // Destructor

        void addEdge(int src, int dest, int weight=1); // הוספת קשת לגרף
        void removeEdge(int src, int dest); // הסרת קשת מהגרף
        void printGraph(); // הדפסת הגרף
        int getNumber(); // מחזיר את מספר הקודקודים בגרף
        Point* getVertex(int index); // גישה לקודקוד ספציפי


    };
}

#endif
