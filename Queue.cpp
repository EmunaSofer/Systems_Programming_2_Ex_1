
#include "Queue.h"

Queue::Queue() 
{
    First = Last = nullptr; 
}

Queue::~Queue()
{
    while (!isEmpty()) 
    {
        remove();
    }
}

void Queue::add(int number)
{
    QueueNode* temp = new QueueNode(number);  // יצירת קודקוד חדש
    if (First == nullptr)
    {
        First = Last = temp;  // אם התור ריק, אז התור מכיל רק את האלמנט החדש
    }
    else
    {
        Last->setNext(temp);  // אם התור לא ריק, מוסיפים את האלמנט בסופו
        Last = temp;  // מעדכנים את Last
    }
}

void Queue::remove()
{
    if (isEmpty())
    {
        //throw std::underflow_error("Queue is empty, cannot remove element.");  // שגיאה במקרה שהתור ריק
    }

    QueueNode* temp = First;  // שומר את הקודקוד הראשון

    if (Last == First)
    { 
        Last = First = nullptr;  // אם יש רק אלמנט אחד, התור ריק לאחר ההסרה
    }
    else
    {
        First = First->getNext();  // מקדמים את First
    }

    delete temp;  // משחררים את הזיכרון של הקודקוד הראשון
}

bool Queue::isEmpty() 
{
    return First == nullptr;
}

QueueNode* Queue::theFirst() 
{
    return First;
}
