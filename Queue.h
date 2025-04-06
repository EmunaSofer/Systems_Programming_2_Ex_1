//emuna002@gmail.com
#ifndef QUEUE_H
#define QUEUE_H

#include "QueueNode.h"  // כולל את הקובץ של QueueNode

class Queue
{
private:
    QueueNode* First;  // מצביע לנקודת ההתחלה של התור
    QueueNode* Last;   // מצביע לנקודת הסיום של התור

public:
    Queue();  // בונה תור ריק
    ~Queue(); // דורס את המערכת ומשחרר את כל הזיכרון

    void add(int number);      // מוסיף מספר לתור
    void remove();             // מסיר את האלמנט הראשון בתור
    bool isEmpty();            // בודק אם התור ריק
    QueueNode* theFirst();     // מחזיר את הקודקוד הראשון בתור
};

#endif // QUEUE_H
