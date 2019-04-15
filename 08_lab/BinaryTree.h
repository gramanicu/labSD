#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <vector>
#include <queue>

template <typename T>
class BinaryTreeNode {
private:
	T data;
	BinaryTreeNode<T> *leftChild;
	BinaryTreeNode<T> *rightChild;

public:
	BinaryTreeNode(T data): data(data), leftChild(nullptr), rightChild(nullptr) {};

	~BinaryTreeNode() {
		/*
		delete leftChild;
		delete rightChild;*/
	}

	void setData(T data) {
		this->data = data;
	};

	T getData() {
		return data;
	}

	void setLeftChild(T data) {
		leftChild = new BinaryTreeNode(data);
	}

	BinaryTreeNode* getLeftChild() {
		return leftChild;
	}

	void setRightChild(T data) {
		rightChild = new BinaryTreeNode(data);
	}

	BinaryTreeNode* getRightChild() {
		return rightChild;
	}
};

template <typename T>
class BinaryTree {
private:
	int size;
public:
	BinaryTreeNode<T> *root;
	BinaryTree(): size(0), root(nullptr) {};

	~BinaryTree() {
		//delete root;
	}

	void insert(T data) {
		if(size == 0) {
			root = new BinaryTreeNode<T>(data);
			root->setRightChild(T());
			root->setLeftChild(T());
			size++;
		} else {
			std::queue<BinaryTreeNode<T>*> q;
			q.push(root->getLeftChild());
			q.push(root->getRightChild());

			while(!q.empty()) {
				BinaryTreeNode<T> *curr = q.front();
				if(curr->getData() == T()) {
					curr->setData(data);
					curr->setLeftChild(T());
					curr->setRightChild(T());
					size++;
					return;
				} else {
					q.pop();
					q.push(curr->getLeftChild());
					q.push(curr->getRightChild());
				}
				//delete curr;
			}
		}
	}

	std::vector<T> traversal() {
		std::vector<T> t;
		std::queue<BinaryTreeNode<T>*> q;
		q.push(root);
		bool first = true;

		while(!q.empty()) {
			BinaryTreeNode<T> *curr = q.front();
			if(curr->getData() != T() || first) {
				first = false;
				t.push_back(curr->getData());
				q.push(curr->getLeftChild());
				q.push(curr->getRightChild());
			}
			q.pop();
		}
		return t;
	}
};

#endif // __BINARYTREE_H__