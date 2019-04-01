/**
 * LabSD 3
 * ResizableArray.h
 * Purpose: Skeleton code for the resizable array.
 *
 * @author Gabriel Bercaru
 */

#ifndef __RESIZABLEARRAY_H__
#define __RESIZABLEARRAY_H__

#include <assert.h>
#include <memory.h>
#include <ostream>

template <typename T>
class ResizableArray {
   private:
    int defaultCapacity = 5;
    int expandFactor = 2;

    int numElements;
    int maxCapacity;
    T* data;

   public:
    // Constructor
    ResizableArray() {
        numElements = 0;
        maxCapacity = defaultCapacity;

        data = new T[maxCapacity];
    }

    // Another constructor
    ResizableArray(int initialCapacity) {
        numElements = 0;
        maxCapacity = initialCapacity;

        data = new T[maxCapacity];
    }

    // Another constructor
    ResizableArray(int initialCapacity, int defaultFactor) {
        numElements = 0;
        maxCapacity = initialCapacity;
        expandFactor = defaultFactor;

        data = new T[maxCapacity];
    }

    // Destructor
    ~ResizableArray() {
        if (data) {
            delete[] data;
        }
    }

    /**
     * Adds the specified element at the end of the array.
     *
     * @param element Element to be added at the end of the array.
     */
    void addLast(T element) {
        if (numElements + 1 > maxCapacity) {
            maxCapacity = maxCapacity * expandFactor;
            T* aux = new T[maxCapacity];
            for (int i = 0; i < numElements; i++) {
                aux[i] = data[i];
            }
            delete[] data;
            data = aux;
        }
        data[numElements++] = element;
    }

    /**
     * Adds the specified element at the beginning of the array.
     *
     * @param element Elment to be added at the beginning of the array.
     */
    void addFirst(T element) {
        if (numElements + 1 > maxCapacity) {
            maxCapacity = maxCapacity * expandFactor;
            T* aux = new T[maxCapacity];
            for (int i = 0; i < numElements; i++) {
                aux[i] = data[i];
            }
            delete[] data;
            data = aux;
        }
        if (numElements) {
            for (int i = numElements; i > 0; i--) {
                data[i] = data[i - 1];
            }
        }
        data[0] = element;
        numElements++;
    }

    /**
     * Removes and returns the last element of the array.
     *
     * @return Value of the last element stored in the array.
     */
    T removeLast() {
        if (numElements != 0) {
            data[numElements] = 0;
            numElements = numElements - 1;
        }
        return 0;
    }

    /**
     * Removes and returns the first element of the array.
     *
     * @return Value of the first element stored in the array.
     */
    T removeFirst() {
        if (numElements) {
            T val = data[0];
            for (int i = 1; i < numElements; i++) {
                data[i - 1] = data[i];
            }
            numElements = numElements - 1;
            return val;
        }
        return 0;
    }

    /**
     * Replace the value at the specified index with the given element.
     *
     * @param index Index of the element to be replaced.
     * @param element New value of the element.
     */
    void setElement(int index, T element) {
        if (index >= 0 && index < numElements) {
            data[index] = element;
        }
    }

    /**
     * Retrieve the value at the specified index.
     *
     * @param index Index of the element to be retrieved.
     * @return Value of the element on the specified position.
     */
    T getElement(int index) {
        if (index >= 0 && index < numElements) {
            return data[index];
        }
        return 0;
    }

    /**
     * Checks if the array contains any elements.
     *
     * @return True if the array contains no elements, False otherwise.
     */
    bool isEmpty() {
        if (numElements)
            return true;
        else
            return false;
    }

    /**
     * Returns the number of elements in the array.
     *
     * @return The number of elements stored in the array.
     */
    int size() {
        return numElements;
        return 0;
    }

    // Getters & Setters
    T* getData() { return data; }

    int getMaxCapacity() { return maxCapacity; }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os,
                                    const ResizableArray<U>& ra);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, ResizableArray<T>& ra) {
    os << "[ ";
    for (int i = 0; i < ra.size(); i++) {
        os << (ra.getData())[i] << " ";
    }
    os << "]";

    return os;
}

#endif  // __RESIZABLEARRAY_H__
