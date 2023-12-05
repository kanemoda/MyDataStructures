#include "LinkedList.h"
#include <iostream>

using namespace::std;

LinkedList::LinkedList() : head(nullptr) , tail(nullptr) , length(0)
{

}

LinkedList::LinkedList(int value) 
{
    Node* newNode = new Node(value);
    head  = newNode;
    tail = newNode;
    length = 1;
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::printList(){
    Node* tmp = head;
    while (tmp != nullptr)
    {
        
        if(tmp->next == nullptr){
            cout << tmp->value;
            break;
        }
        cout << tmp->value << " -> ";
        tmp = tmp->next;
    }
}

void LinkedList::addStart(int value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    length++;
}

void LinkedList::addEnd(int value){
    Node* newNode = new Node(value);
    tail->next = newNode;
    tail = newNode;
    length++;
}

void LinkedList::addIndex(int value , int index){
    if(index == length){
        addEnd(value);
    }

    else if(index == 0){
        addStart(value);
    }

    else {
        Node* tmp = head;
        Node* newNode = new Node(value);
        for (int i = 0; i < index - 1; i++)
        {
            tmp = tmp->next; 
        }
        Node* tmp2 = tmp->next;
        tmp->next = newNode;
        newNode->next = tmp2;
        length++;
    }
}

void LinkedList::deleteFirst(){

    Node* tmp = head->next;
    delete head;
    head = tmp;
    length--;

}

void LinkedList::deleteLast(){

    Node* tmp = head;
    while (tmp->next != tail)
    {
        tmp = tmp->next;
    }
    delete tail;
    tail = tmp;
    tail->next = nullptr;
    length--;

}

void LinkedList::deleteIndex(int index){

    if (index < 0 || index >= length) {
        cout << "Invalid index. Cannot delete.\n";
        return;
    }

    if (index == 0)
    {
        deleteFirst();
    }

    else if(index == length){
        deleteLast();
    }
    
    else{
        Node* tmp = head;
        Node* tmp2;
        for (int i = 0; i < index - 1; i++)
        {
            tmp = tmp->next; 
        }

        tmp2 = tmp->next->next;

        delete tmp->next;
        tmp->next = tmp2;
        length--;
    }

}

void LinkedList::reverseRec(Node* tmp1 , Node* tmp2){
    if(tmp2->next ==nullptr){
        tmp2->next = tmp1;
        Node* tmp3 = head;
        head = tmp2;
        tail = tmp3;
        tail->next = nullptr;
        return;
    }
    
    reverseRec(tmp1->next , tmp2->next);
    tmp2->next = tmp1;
    

    
}

void LinkedList::reverse(){
    if(length <= 1){
        return;
    }
    reverseRec(head , head->next);
}




