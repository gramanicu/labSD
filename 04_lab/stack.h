#ifndef STACK_H
#define STACK_H

#include "./node.h"

template <typename T>
class Stack {
   private:
    Node *head;
    int size;
   public:
    Stack() : head(nullptr), size(0);
    ~Stack();
    Stack(const Stack& other) head(other.head), size(other.size);
    
};

#endif