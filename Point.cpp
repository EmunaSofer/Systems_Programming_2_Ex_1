//emuna002@gmail.com
#include "Point.h"


    Point::Point(int id, int weight, Point* next) 
    {
        this->id = id;
        this->weight = weight;
        this->next = next;
        this->visited = false;
    }

    int Point::getId() 
    {
        return id; 
    }

    int Point::getWeight() 
    {
        return weight; 
    }

    Point* Point::getNext()
    {
        return next; 
    }

    void Point::setNext(Point* next) 
    {
        this->next = next; 
    }

    void Point::setWeight(int weight) 
    {
        this->weight = weight; 
    }

    void Point::setVisited(bool B) 
    {
        this->visited = B; 
    }

    bool Point::isVisited()
    {
        return this->visited;
    }




