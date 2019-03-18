/**
 * LabSD 4
 * Queue.h
 * Purpose: Skeleton code for the queue.
 *
 * @author Gabriel Bercaru
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <assert.h>
#include <iostream>
#include <vector>

template <typename T, int N>
class Queue {
   private:
    int head;
    int tail;
    int numElements;
    T queueArray[N];

   public:
    // Constructor
    Queue() : head(0), tail(0), numElements(0){};

    // Destructor
    ~Queue() {}

    /**
     * Add a new element in the queue.
     *
     * @param element Value of the element to be added in the queue.
     */
    void enqueue(T element) {
        queueArray[tail++] = element;
        numElements++;
    }

    /**
     * Removes and returns an element from the queue.
     *
     * @return Value of the elmement removed from the queue.
     */
    T dequeue() {
        T val = queueArray[head];
        for (int i = 0; i < numElements - 1; i++) {
            queueArray[i] = queueArray[i + 1];
        }
        numElements--;
        tail--;
        return val;
    }

    /**
     * Returns an element from the queue, without removing it.
     *
     * @return Value of the first element stored in the queue (queue front).
     */
    T front() { return queueArray[head]; }

    /**
     * Checks if the queue contains any elements.
     *
     * @return True if the queue contains no elements, False otherwise.
     */
    bool isEmpty() {
        if (!numElements)
            return true;
        else
            return false;
    }

    /**
     * Returns the number of elements currently stored in the queue.
     *
     * @return The number of elements stored in the queue.
     */
    int size() { return numElements; }

    template <typename U, int M>
    friend std::ostream& operator<<(std::ostream& os, Queue<U, M>& queue);
};

template <typename T, int N>
std::ostream& operator<<(std::ostream& os, Queue<T, N>& queue) {
    os << "Front to rear: ";
    std::vector<T> aux;
    while (!queue.isEmpty()) {
        aux.push_back(queue.dequeue());
    }
    for (unsigned int i = 0; i < aux.size(); i++) {
        os << aux[i] << " ";
        queue.enqueue(aux[i]);
    }

    return os;
}

#endif  // __QUEUE_H__
