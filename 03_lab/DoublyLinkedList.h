/**
 * LabSD 3
 * DoublyLinkedList.h
 * Purpose: Skeleton code for the doubly linked list.
 *
 * @author Gabriel Bercaru
 */

#ifndef __DOUBLYLINKEDLIST_H__
#define __DOUBLYLINKEDLIST_H__

#include <assert.h>

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node(T data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class DoublyLinkedList {
   private:
    Node<T> *head;
    Node<T> *tail;
    int numElements;

   public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        numElements = 0;
    }

    // Another constructor
    DoublyLinkedList(Node<T> *head) {
        this->head = head;
        while (head != nullptr) {
            numElements++;
            head = head->next;
        }
    }

    // Destructor
    ~DoublyLinkedList() {
        Node<T> *current = head;
        while (current) {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
    }

    /**
     * Adds a new node at the end of the list.
     *
     * @param data Data to be added at the end of the list.
     */
    void addLast(T data) {
        if(head) {
            Node<T> *toAdd = new Node<T>(data);
            toAdd->prev = tail;
            toAdd->next = nullptr;
            tail = toAdd; 
        } else {
            Node<T> *toAdd = new Node<T>(data);
            head = toAdd;
            head->next = nullptr;
            head->prev = nullptr;
        }
        numElements++;
    }

    /**
     * Adds a new node at the beginning of the list.
     *
     * @param data Data to be added at the beginning of the list.
     */
    void addFirst(T data) {
        if (head) {
            Node<T> *toAdd = new Node<T>(data);
            toAdd->next = head;
            toAdd->prev = nullptr;
            head->prev = toAdd;
            head = toAdd;
        } else {
            Node<T> *toAdd = new Node<T>(data);
            head = toAdd;
            head->next = nullptr;
            head->prev = nullptr;
        }
        numElements++;
    }

    /**
     * Removes the last node of the list.
     *
     * @return Value stored in the last node of the list.
     */
    T removeLast() {
        if (tail) {
            Node<T> *aux = tail->prev;
            delete tail;
            tail = aux;
        }
        numElements--;
        return tail;
    }

    /**
     * Removes the first node of the list.
     *
     * @return Value stored in the first node of the list.
     */
    T removeFirst() {
        if (numElements > 1) {
            Node<T> *aux = head->next;
            delete head;
            head = aux;
        } else if (numElements == 1) {
            head = nullptr;
            tail = nullptr;
        }
        numElements--;
        return head->data;
    }

    /**
     * Check if the list contains any elements.
     *
     * @return True if the list contains no elements, False otherwise.
     */
    bool isEmpty() {
        if (numElements) return true;
        else return false;
    }

    /**
     * Get the number of nodes in the list.
     *
     * @return The number of nodes stored in the list.
     */
    int get_numElements() {
        return numElements;
    }

    // Getters & Setters
    Node<T> *getHead() { return head; }

    Node<T> *getTail() { return tail; }

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os,
                                    DoublyLinkedList<U> &list);
};

template <typename T>
std::ostream &operator<<(std::ostream &os, DoublyLinkedList<T> &list) {
    Node<T> *it = list.getHead();

    if (list.numElements > 0) {
        os << "[ ";
        while (it->next != nullptr) {
            os << it->data << " <-> ";
            it = it->next;
        }

        os << it->data;
        os << " ]";
    } else {
        os << "[]";
    }

    return os;
}

#endif  // __DOUBLYLINKEDLIST_H__
