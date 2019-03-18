/**
 * LabSD 4
 * lab4.cpp
 * Purpose: Driver program to run lab4 tasks.
 *
 * @author Gabriel Bercaru
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "Algorithms.h"
#include "DoubleQueueStack.h"
#include "DoubleStackQueue.h"
#include "Queue.h"
#include "Stack.h"

void checkStack() {
#ifdef DEBUG
    std::ostream& task1 = std::cout;
#else
    std::ofstream file;
    file.open("Out/Lab4/task1.out");
    std::ostream& task1 = file;
#endif

    Stack<int, 5> s;

    task1 << "========== Checking stack methods  ==========\n";

    for (int i = 46; i < 51; i++) {
        s.push(i);
    }

    task1 << "Stack: " << s << std::endl;

#ifndef DEBUG
    file.close();
#endif
}

void checkQueue() {
#ifdef DEBUG
    std::ostream& task2 = std::cout;
#else
    std::ofstream file;
    file.open("Out/Lab4/task2.out");
    std::ostream& task2 = file;
#endif

    Queue<int, 5> q;

    task2 << "========== Checking queue methods ==========\n";

    for (int i = 0; i < 5; i++) {
        q.enqueue(i);
    }

    task2 << "Queue: " << q << std::endl;

#ifndef DEBUG
    file.close();
#endif
}

void checkBalancedParentheses() {
#ifdef DEBUG
    std::ostream& task3 = std::cout;
#else
    std::ofstream file;
    file.open("Out/Lab4/task3.out");
    std::ostream& task3 = file;
#endif

    task3 << "========== Balanced parentheses check ==========\n";
    std::ostringstream oss;

    oss << "Checking \"[({()})][{}]()\": "
        << Algorithms::checkBalancedParentheses("[({()})][{}]()") << std::endl;
    task3 << oss.str();
    oss.str("");

    oss << "Checking \"{}[(])\": "
        << Algorithms::checkBalancedParentheses("{}[(])") << std::endl;
    task3 << oss.str();
    oss.str("");

    oss << "Checking \"\": " << Algorithms::checkBalancedParentheses("")
        << std::endl;
    task3 << oss.str();
    oss.str("");

    oss << "Checking \"(\": " << Algorithms::checkBalancedParentheses("(")
        << std::endl;
    task3 << oss.str();
    oss.str("");

    oss << "Checking \"]\": " << Algorithms::checkBalancedParentheses("]")
        << std::endl;
    task3 << oss.str();
    oss.str("");

#ifndef DEBUG
    file.close();
#endif
}

void checkRadixSort() {
#ifdef DEBUG
    std::ostream& task4 = std::cout;
#else
    std::ofstream file;
    file.open("Out/Lab4/task4.out");
    std::ostream& task4 = file;
#endif

    task4 << "========== Radix sort check ==========\n";

    std::vector<int> v;
    v.push_back(50);
    v.push_back(45);
    v.push_back(75);
    v.push_back(90);
    v.push_back(2);
    v.push_back(24);
    v.push_back(802);
    v.push_back(66);

    task4 << "Before sort: ";

    for (unsigned int i = 0; i < v.size(); i++) {
        task4 << v[i] << " ";
    }

    task4 << std::endl;

    Algorithms::radixSort(v);

    task4 << "After sort: ";

    for (unsigned int i = 0; i < v.size(); i++) {
        task4 << v[i] << " ";
    }

    task4 << std::endl;

#ifndef DEBUG
    file.close();
#endif
}

void checkToBase2() {
#ifdef DEBUG
    std::ostream& task5 = std::cout;
#else
    std::ofstream file;
    file.open("Out/Lab4/task5.out");
    std::ofstream& task5 = file;
#endif

    task5 << "========== To Base 2 check ==========\n";

    task5 << "8 in base 2 is: ";
    Algorithms::toBase2(8, task5);

    task5 << "13 in base 2 is: ";
    Algorithms::toBase2(13, task5);

    task5 << "56 in base 2 is: ";
    Algorithms::toBase2(56, task5);

#ifndef DEBUG
    file.close();
#endif
}

void checkPalindrome() {
#ifdef DEBUG
    std::ostream& task6 = std::cout;
#else
    std::ofstream file;
    file.open("Out/Lab4/task6.out");
    std::ostream& task6 = file;
#endif

    task6 << "========== Palindrome check ==========\n";

    task6 << "abba is "
          << ((Algorithms::palindrome("abba")) ? "a palindrome\n"
                                               : "not a palindrome\n");

    task6 << "1221 is "
          << ((Algorithms::palindrome("1221")) ? "a palindrome\n"
                                               : "not a palindrome\n");

    task6 << "abc is "
          << ((Algorithms::palindrome("abc")) ? "a palindrome\n"
                                              : "not a palindrome\n");
}

void checkReverseQueue() {
#ifdef DEBUG
    std::ostream& bonus1 = std::cout;
#else
    std::ofstream file;
    file.open("Out/Lab4/bonus1.out");
    std::ostream& bonus1 = file;
#endif

    Queue<int, 20> queueB;

    bonus1 << "========== Reverse queue check (bonus) ==========\n";

    for (int i = 0; i < 10; i++) {
        queueB.enqueue(i + 1);
    }

    bonus1 << "QueueB before reverse: " << queueB << std::endl;
    Algorithms::reverseQueue(queueB);
    bonus1 << "QueueB after reverse: " << queueB << std::endl;

#ifndef DEBUG
    file.close();
#endif
}

void checkDoubleQueueStack() {
#ifdef DEBUG
    std::ostream& bonus2 = std::cout;
#else
    std::ofstream file;
    file.open("Out/Lab4/bonus2.out");
    std::ostream& bonus2 = file;
#endif

    bonus2 << "========== Double queue stack (bonus) ==========\n";
    DoubleQueueStack<char, 10> doubleQueueStack;
    doubleQueueStack.push('a');
    doubleQueueStack.push('b');
    doubleQueueStack.push('c');
    doubleQueueStack.push('d');

    bonus2 << "DoubleQueueStack: " << doubleQueueStack << std::endl;
    doubleQueueStack.pop();
    doubleQueueStack.pop();
    bonus2 << "After popping 2 elements: " << doubleQueueStack << std::endl;
    doubleQueueStack.push('z');
    bonus2 << "After pushing 'z': " << doubleQueueStack << std::endl;

#ifndef DEBUG
    file.close();
#endif
}

void checkDoubleStackQueue() {
#ifdef DEBUG
    std::ostream& bonus3 = std::cout;
#else
    std::ofstream file;
    file.open("Out/Lab4/bonus3.out");
    std::ostream& bonus3 = file;
#endif

    bonus3 << "========== Double stack queue (bonus) ==========\n";
    DoubleStackQueue<char, 10> doubleStackQueue;
    doubleStackQueue.enqueue('a');
    doubleStackQueue.enqueue('b');
    doubleStackQueue.enqueue('c');
    doubleStackQueue.enqueue('d');

    bonus3 << "DoubleStackQueue: " << doubleStackQueue << std::endl;
    doubleStackQueue.dequeue();
    doubleStackQueue.dequeue();
    bonus3 << "After popping 2 elements: " << doubleStackQueue << std::endl;
    doubleStackQueue.enqueue('z');
    bonus3 << "After pushing 'z': " << doubleStackQueue << std::endl;

#ifndef DEBUG
    file.close();
#endif
}

int main() {
    checkStack();
    checkQueue();
    checkBalancedParentheses();
    checkRadixSort();
    checkToBase2();
    checkPalindrome();
    checkReverseQueue();
    checkDoubleQueueStack();
    checkDoubleStackQueue();

    return 0;
}
