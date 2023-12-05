#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"


class LinkedList
{

private:
    void reverseRec(Node* tmp1 , Node* tmp2);

public:

    Node* head;
    Node* tail;
    int length;

    LinkedList();
    LinkedList(int value);
    ~LinkedList();
    void printList();
    void addStart(int value);
    void addEnd(int value);
    void addIndex(int value , int index);
    void deleteFirst();
    void deleteLast();
    void deleteIndex(int index);
    void reverse();
    

    
};

#endif
