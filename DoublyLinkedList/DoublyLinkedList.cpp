#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() : head(nullptr) , tail(nullptr) , length(0)
{

}
DoublyLinkedList::DoublyLinkedList(int value)
{
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

void DoublyLinkedList::addToBeggining(int value){
    Node* newnode = new Node(value);
    head->Prev = newnode;
    newnode->Next = head;
    head = newnode;
    length++;
}

void DoublyLinkedList::addToEnd(int value){
    Node* newNode = new Node(value);
    tail->Next = newNode;
    newNode->Prev = tail;
    tail = newNode;
    length++;
}

void DoublyLinkedList::addToIndex(int value , int index){

    if(index == 0){
        addToBeggining(value);
    }

    else if (index == length){
        addToEnd(value);
    }

    //Forgot to increment length and also did a mistake by using "counter <= index" . Didn't take long to realise my mistakes. I guess I am learning
    else{
        Node* newNode = new Node(value);
        Node* tmp = head;
        int counter = 0;

        while (counter < index)
        {
            tmp = tmp->Next;
            counter++;
        }
        tmp->Prev->Next = newNode;
        newNode->Prev = tmp->Prev;
        tmp->Prev = newNode;
        newNode->Next = tmp;
        length++;
    }
    
    
}

void DoublyLinkedList::deleteFromBeggining(){
    Node* tmp = head->Next;
    delete head;
    head = tmp;
    head->Prev = nullptr;
    length--;

}

void DoublyLinkedList::deleteFromEnd(){
    Node* tmp = tail->Prev;
    delete tail;
    tail = tmp;
    tail->Next = nullptr;
    length--;
}
void DoublyLinkedList::deleteFromIndex(int index){

    if (index == 0)
    {
        deleteFromBeggining();
    }

    else if(index == length){
        deleteFromEnd();
    }

    else{
        Node* tmp = head;
        int counter = 0;
        while (counter < index)
        {
            tmp = tmp->Next;
            counter++;
        }
        Node* tmpBefore = tmp->Prev;
        Node* tmpAfter = tmp->Next;
        delete tmp;
        tmpBefore->Next = tmpAfter;
        tmpAfter->Prev = tmpBefore;
        length--;
    }
}

void DoublyLinkedList::reverseIteratively(){
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->Next;

        current->Next = prev;
        current->Prev = next;

        prev = current;
        current = next;
    }

    tail = head;
    head = prev;
}

void DoublyLinkedList::reverseRec(Node* tmp1 , Node* tmp2){
    //I Worked on this for so long ı and could't achive anything what a despair
    /* if(tmp2->Next == nullptr){
        tmp2->Prev = tmp2->Next;
        tmp2->Next = tmp1;
        Node* tmp3 = head;
        head = tmp2; 
        tail = tmp3;
        tail->Next = nullptr;
        tmp1->Prev = tmp2;
    } */
    if (tmp2->Next == nullptr) {
        tmp2->Next = tmp1;
        tmp1->Prev = tmp2;

        // Update pointers for the new head and tail
        tail = head;
        head = tmp2;
        tail->Next = nullptr;
        head->Prev = nullptr;
        return;
    }

    reverseRec(tmp1->Next , tmp2->Next);
    tmp2->Next = tmp1;
    tmp1->Prev = tmp2;
    
}

void DoublyLinkedList::reverseRecursively(){
    if(length <= 1) 
    {
        return;
    }
    reverseRec(head , head->Next);

}

void DoublyLinkedList::printList(){
    Node* tmp = head;
    while (tmp != nullptr)
    {
        if(tmp->Next == nullptr){
            std::cout << tmp->value;
            break;
        }
        std::cout << tmp->value << " -> ";
        tmp = tmp->Next;
    }
}