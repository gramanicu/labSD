/**
 * LabSD 6
 * lab6.cpp
 * Purpose: Driver program to run lab6 tasks.
 *
 * @author Gabriel Bercaru
 */

#include <fstream>
#include <iostream>
#include <set>

#include "Algorithms.h"
#include "ListGraph.h"
#include "MatrixGraph.h"

void print(const std::vector<int> &vector) {
    for (auto it = vector.begin(); it != vector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

ListGraph createListGraph(const char *inputFilename) {
    std::ifstream inFile;
    inFile.open(inputFilename);
    int n, m;

    inFile >> n >> m;
    ListGraph listGraph(n);

    for (int i = 0; i < m; ++i) {
        int x, y;

        inFile >> x >> y;
        listGraph.addEdge(x, y);
        listGraph.addEdge(y, x);
    }

    inFile.close();

    return listGraph;
}

MatrixGraph createMatrixGraph(const char *inputFilename) {
    std::ifstream inFile;
    inFile.open(inputFilename);
    int n, m;

    inFile >> n >> m;
    MatrixGraph matrixGraph(n);

    for (int i = 0; i < m; ++i) {
        int x, y;

        inFile >> x >> y;
        matrixGraph.addEdge(x, y);
        matrixGraph.addEdge(y, x);
    }

    inFile.close();

    return matrixGraph;
}

void checkWordLadder() {
    std::set<std::string> words;
    std::string sourceWord = "abc";
    std::string targetWord = "efd";

    words.insert("abc");
    words.insert("abd");
    words.insert("afd");
    words.insert("efd");
    words.insert("egd");
    words.insert("abcd");
    words.insert("ebc");

    bool ret = Algorithms::wordLadder(words, sourceWord, targetWord);

    std::cout << "Path from " << sourceWord << " to " << targetWord << ": " << ret << std::endl;
}

int main() {
    // checkWordLadder();

    MatrixGraph m(7);
    m.addEdge(0,1);
    m.addEdge(0,2);
    m.addEdge(0,3);
    m.addEdge(1,4);
    m.addEdge(2,5);
    m.addEdge(2,6);
    m.addEdge(3,6);
    
    m.BFS();

    return 0;
}
