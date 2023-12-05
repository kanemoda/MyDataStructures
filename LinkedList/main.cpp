#include "LinkedList.h"
#include <iostream>

using namespace::std;

int main(int argc, char const *argv[])
{
    LinkedList LL(1);
    LL.addEnd(2);
    LL.printList();
    cout << "\n";
    LL.reverse();
    LL.printList();


    return 0;
}
