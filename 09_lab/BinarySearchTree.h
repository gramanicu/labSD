/**
  * Autor: Victor Carbune
  * Echipa SD, 2012
  *
  * Modificari: Adrian Bogatu
  * Echipa SD, 2013
  *
  * Modificari: Cosmin Petrisor
  * Echipa SD, 2015
  *
  * Modificari: Cristian Creteanu
  * Echipa SD, 2017
  * 
  * Modificari: Ioana Stefan
  * Echipa SD, 2018
  * License: LGPL
  */

#ifndef __BINARY_SEARCH_TREE__H
#define __BINARY_SEARCH_TREE__H

#include <iostream> 
#include <vector>

template <typename T>
class BinarySearchTree
{
private:
    BinarySearchTree<T> *leftNode;
    BinarySearchTree<T> *rightNode;
    BinarySearchTree<T> *parent;
    T pData;

public:
    bool initialised = false;
    BinarySearchTree():leftNode(nullptr), rightNode(nullptr), parent(nullptr), pData(T()) {}

    ~BinarySearchTree() {
        delete leftNode;
        delete rightNode;
        // ?
    }
    
    bool isEmpty() {
        return (pData == nullptr);
    }
 
    void insertKey(T x) {
        if(pData==T() && !initialised) {
            pData = x;
            BinarySearchTree<T> *lInsert = new BinarySearchTree<T>();
            BinarySearchTree<T> *rInsert = new BinarySearchTree<T>();
            lInsert->parent = this;
            rInsert->parent = this;
            this->leftNode = lInsert;
            this->rightNode = rInsert;
        } else {
            if(x < pData) {
                leftNode->insertKey(x);
            } else if(x > pData) {
                rightNode->insertKey(x);
            }
        }

        if(!initialised) {
            initialised = true;
        }
    }
    
    BinarySearchTree<T>* searchKey(T x) {
        if(pData == x) {
            return this;
        } else {
            if(x>pData) {
                if(rightNode->pData!=T()) {
                    return rightNode->searchKey(x);
                } else {
                    return nullptr;
                }
            } else {
                if(leftNode->pData!=T()) {
                    return leftNode->searchKey(x);
                } else {
                    return nullptr;
                }
            }
        }
    }
    
    std::vector<T> inOrderDisplay() {
        std::vector<T> res;
        if(leftNode->pData != T()) {
            std::vector<T> aux = leftNode->inOrderDisplay();
            res.insert(res.end(), aux.begin(), aux.end());
        }
        res.push_back(pData);
        if(rightNode->pData != T()) {
            std::vector<T> aux = rightNode->inOrderDisplay();
            res.insert(res.end(), aux.begin(), aux.end());
        } 
        return res;
    }
    
    T findMin() {
        if(leftNode->pData==T()) {
            return pData;
        } else {
            return leftNode->findMin();
        }
    }
    
    T findMax() {
        if(rightNode->pData==T()) {
            return pData;
        } else {
            return rightNode->findMax();
        }
    }

    int findLevels() {
        int cLevel;
        bool right = false;
        bool left = false;
        if(rightNode->pData != T()) {
            right = true;
        }
        if(leftNode->pData != T()) {
            left = true;
        }
        int lL = 0;
        int rL = 0;
        if(right) rL = rightNode->findLevels();
        if(left) lL = leftNode->findLevels();
        
        if(rL > lL) cLevel = rL;
        else if(rL < lL) cLevel = lL;
        if(parent!=nullptr) {
            cLevel++;
        }
        return cLevel;
    }
    
    std::vector<T> displayLevel(int level) {
        // TODO 3
        std::vector<T> res;
        return res;
    }
    
    BinarySearchTree<T>* removeKey(T x) {
        BinarySearchTree<T>* node = searchKey(x);
        if(node!=nullptr) {
            std::vector<T> toInsert;

            if(node->leftNode->pData!= T()) {
                std::vector<T> aux = node->leftNode->inOrderDisplay();
                for(auto& i : aux) {
                    toInsert.push_back(i);
                }
            }

            if(node->rightNode->pData!= T()) {
                std::vector<T> aux = node->rightNode->inOrderDisplay();
                for(auto& i : aux) {
                    toInsert.push_back(i);
                }
            }

            node->pData = T();
            for(auto& i : toInsert) {
                this->insertKey(i);
            }
        }
        return nullptr;
    }
 
};
 
#endif // __BINARY_SEARCH_TREE_H

