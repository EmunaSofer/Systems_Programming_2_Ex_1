//emuna002@gmail.com
#include "QueueNode.h"

QueueNode::QueueNode(int num)
{
    this->number=num;
    next=nullptr;
}

QueueNode::~QueueNode()
{
    // שחרור זיכרון אם יש צורך
}

void QueueNode::setNext(QueueNode* next)
{
    this->next=next;
}

QueueNode* QueueNode::getNext()
{
    return next;
}

int QueueNode::getValue()
{
    return this->number;
}