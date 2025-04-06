//emuna002@gmail.com
#ifndef POINT_H  // מונע כלול כפול
#define POINT_H


    class Point {
    private:
        int id;         // מספר הקודקוד
        int weight;     // משקל הצלע
        Point* next;    // מצביע לקודקוד הבא (בהתחלה nullptr)
        bool visited;

    public:
        // הצהרת הבנאי
        Point(int id, int weight = 0, Point* next = nullptr);  

        int getId() ;
        int getWeight() ;
        Point* getNext() ;
        bool isVisited();

        // הצהרת פונקציות set
        void setNext(Point* next);
        void setWeight(int weight);
        void setVisited(bool B);
    };


#endif  // POINT_H
