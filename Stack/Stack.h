#ifndef STACK_H
#define STACK_H

#include <array>

class Stack
{
private:
    int* StackArray;
    int top = -1;
    int size;
    int* tmpArray;
public:
    Stack();
    Stack(int size);
    bool isFull();
    void expand();
    void Push(int value);
    void shrink();
    bool isEmpty();
    int Peek();
    int Pop();
    
};


#endif
