#include "Node.h"

Node::Node(int value){
    this->value = value;
    this->Next = nullptr;
    this->Prev = nullptr;
}