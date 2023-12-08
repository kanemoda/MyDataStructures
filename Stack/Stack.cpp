#include "Stack.h"
#include <iostream>
#include <stdexcept>

Stack::Stack() : StackArray(new int[10]) , size(10)
{

}
Stack::Stack(int size){
    StackArray = new int[size];
    this->size = size;
}


bool Stack::isFull(){
    if(top == size -1){
        return true;
    }
    return false;
}

bool Stack::isEmpty(){
    if(top == -1){
        return true;
    }
    return false;
}

void Stack::expand(){
    tmpArray = new int[size*2];
    for (int i = 0; i < size; i++)
    {
        tmpArray[i] = StackArray[i];
    }
    size *= 2;
    delete[] StackArray;
    StackArray = tmpArray;
}
void Stack::shrink(){
    
}

void Stack::Push(int value){
    if(!isFull()){
        StackArray[top + 1] = value;
        top++;
        return;
    }
    //If Stack is Full
    expand();
    Push(value);
}

int Stack::Peek(){
    if (isEmpty()) {
        throw std::runtime_error("Stack is Empty");
    }

    return StackArray[top];
}

int Stack::Pop(){
    if (isEmpty())
    {
        throw std::runtime_error("Stack is Empty");
    }
    int value = StackArray[top];
    top--;
    return value;
}