#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

#include "BinaryTree.h"

template <typename T>
bool checkSameLevelLeaves(BinaryTree<T> bt) {
	std::vector<int> lvl;
	std::vector<bool> isLeaf;
	std::queue<BinaryTreeNode<T>*> q;
	q.push(bt.root);
	int currLvl = 0;
	int index = 0;


	while(!q.empty()) {
		BinaryTreeNode<T> *curr = q.front();
		index++;
		if(curr->getData() != T() || index==1) {
			if(curr->getLeftChild()->getData() == T() && curr->getRightChild()->getData() == T()) {
				isLeaf.push_back(true);
			} else {
				isLeaf.push_back(false);
			}
			if(index >= pow(2, currLvl)) {
				currLvl++;
			}
			lvl.push_back(currLvl);

			q.push(curr->getLeftChild());

			q.push(curr->getRightChild());
		}
		q.pop();
	}

	int leafLvl = 0;
	bool changed = false;
	for(int i=0; i<isLeaf.size(); i++) {
		if(isLeaf[i]) {
			if(leafLvl!=0 && leafLvl!=lvl[i]) {
				changed = true;
				break;
			}

			leafLvl = lvl[i];
		}
	}

	if(leafLvl==0) {
		return true;
	}

	return !changed;

}

template <typename T>
bool isBalanced(BinaryTree<T> bt) {
	// TODO
	return true;
}

template <typename T>
bool checkChildrenSum(BinaryTree<T> bt) {
	// TODO
	return true;
}

template <typename T>
int computeTreeHeight(BinaryTree<T> bt) {
	// TODO
	return 0;
}

int main() {
	// Create empty binary tree
	BinaryTree<int> bt;
	
	// Insert data
	for (int i = 0; i < 10; ++i) {
		bt.insert(i);
	}

	checkSameLevelLeaves(bt);

	// Print Ex2
	freopen("Out/Lab8/traversal.out", "w", stdout);
	std::vector<int> traversal = bt.traversal();
	for (auto node : traversal) {
		std::cout << node << " ";
	}

	// Check Ex3:sameLevelLeaves
	freopen("Out/Lab8/leaves.out", "w", stdout);
	bool sameLevel = checkSameLevelLeaves(bt);
	std::cout << sameLevel << '\n';
	for (int i = 10; i < 15; ++i) {
		bt.insert(i);
	}
	sameLevel = checkSameLevelLeaves(bt);
	std::cout << sameLevel << '\n';
	
	return 0;
}