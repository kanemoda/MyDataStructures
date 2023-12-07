#ifndef DOUBLY_LINKED_LIST_H
#define DOUDOUBLY_LINKED_LIST_H
#include "Node.h"

class DoublyLinkedList
{

private:
    void reverseRec(Node* tmp1 , Node* tmp2);

public:
    Node* head;
    Node* tail;
    int length;
    DoublyLinkedList();
    DoublyLinkedList(int value);
    void addToBeggining(int value);
    void addToEnd(int value);
    void addToIndex(int value , int index);
    void deleteFromBeggining();
    void deleteFromEnd();
    void deleteFromIndex(int index);
    void reverseIteratively();
    void reverseRecursively();
    void printList();

};
#endif

