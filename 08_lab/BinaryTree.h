#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <vector>

template <typename T>
class BinaryTreeNode {
private:
	T data;
	BinaryTreeNode<T> *leftChild;
	BinaryTreeNode<T> *rightChild;

public:
	BinaryTreeNode(T data) {
		// TODO 1
	}

	~BinaryTreeNode() {
		// TODO 2
	}

	void setData(T data) {
		// TODO 3
	}

	T getData() {
		// TODO 4
	}

	void setLeftChild(T data) {
		// TODO 5
	}

	BinaryTreeNode* getLeftChild() {
		// TODO 6
	}

	void setRightChild(T data) {
		// TODO 7
	}

	BinaryTreeNode* getRightChild() {
		// TODO 8
	}
};

template <typename T>
class BinaryTree {
private:
	int size;
	BinaryTreeNode<T> *root;
public:
	BinaryTree() {
		// TODO 9
	}

	~BinaryTree() {
		// TODO 10
	}

	void insert(T data) {
		// TODO 11: Insert node at the first empty position
	}

	std::vector<T> traversal() {
		// TODO 12
	}
};

#endif // __BINARYTREE_H__