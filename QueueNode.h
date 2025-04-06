//emuna002@gmail.com
#ifndef QEUEUENODE_H
#define  QEUEUENODE_H
class QueueNode
{
    private:
        int number;
        QueueNode* next;
    public:
    QueueNode(int num);
    ~QueueNode();
    void setNext(QueueNode* next);
    QueueNode* getNext();
    int getValue();
};
#endif 