#include <iostream>
#include "DoublyLinkedList.h"

using namespace::std;

int main(int argc, char const *argv[])
{
    DoublyLinkedList doublyLinkedList(2);
    doublyLinkedList.addToBeggining(1);
    doublyLinkedList.addToEnd(3);
    doublyLinkedList.addToEnd(4);
    doublyLinkedList.addToEnd(6);
    doublyLinkedList.addToIndex(5 , 4);
    doublyLinkedList.printList();
    doublyLinkedList.reverseRecursively();
    cout << "\n";
    doublyLinkedList.printList();
    doublyLinkedList.reverseIteratively();
    cout << "\n";
    doublyLinkedList.printList();


    return 0;
}
