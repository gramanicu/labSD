/**
 * LabSD 4
 * Stack.h
 * Purpose: Skeleton code for the stack.
 *
 * @author Gabriel Bercaru
 */

#ifndef __STACK_H__
#define __STACK_H__

#include <assert.h>

#include <vector>

/**
 * First template parameter is the datatype of the elements to be stored.
 * Second template parameter is the maximum stack size.
 */
template <typename T, int N>
class Stack {
   private:
    // Underlying array
    T stackArray[N];
    int topLevel;

   public:
    // Constructor
    Stack() : topLevel(-1){};

    // Destructor
    ~Stack(){};

    /**
     * Adds an element on top of the stack.
     *
     * @param element Element to be added to the stack.
     */
    void push(T element) {
        if (topLevel + 1 < N) {
            topLevel = topLevel + 1;
            stackArray[topLevel] = element;
        }
    }

    /**
     * Removes the top element of the stack.
     */
    void pop() {
        if (topLevel >= 0) {
            stackArray[topLevel] = 0;
            topLevel = topLevel - 1;
        }
    }

    /**
     * Retrieves the top value stored in the stack.
     *
     * @return Value of the element stored on top of the stack.
     */
    T peek() { return stackArray[topLevel]; }

    /**
     * Checks if the stack contains any elements.
     *
     * @return True if the stack contains no elements, False otherwise.
     */
    bool isEmpty() {
        if (topLevel == -1)
            return true;
        else
            return false;
    }

    /**
     * Returns the number of elements currently stored in the stack.
     *
     * @return The number of elements stored in the stack.
     */
    int size() { return topLevel - 1; }

    template <typename U, int M>
    friend std::ostream& operator<<(std::ostream& os, Stack<U, M>& stack);
};

template <typename T, int N>
std::ostream& operator<<(std::ostream& os, Stack<T, N>& stack) {
    os << "Bottom to top: ";
    std::vector<T> aux;

    while (!stack.isEmpty()) {
        aux.push_back(stack.peek());
        stack.pop();
    }

    for (int i = aux.size() - 1; i >= 0; i--) {
        os << aux[i] << " ";
        stack.push(aux[i]);
    }

    return os;
}

#endif  // __STACK_H__
