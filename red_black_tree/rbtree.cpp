#include <iostream>
#include <limits>
#include "rbtree.hpp"

Node::Node() {
	data = std::numeric_limits<double>::quiet_NaN();
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}

Node::Node(int d) {
	data = d;
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}

Node* Node::get_sibling() {
	if (parent == nullptr) {
		std::cout << "No parent!" << std::endl;
		return nullptr;
	}
	//TODO: overload equality for duplicate values?
	if (this->data == parent->left->data) {
		return parent->right;
	}
	return parent->left;
}

Node* Node::get_uncle() {
	if (parent == nullptr) {
		std::cout << "No parent!" << std::endl;
		return nullptr;
	}
	if (parent->parent == nullptr) {
		std::cout << "No grandparent!" << std::endl;
		return nullptr;
	}
	if (parent->data == parent->parent->left->data) {
		if (parent->parent->right == nullptr) {
			std::cout << "No right uncle!" << std::endl;
			return nullptr;
		}
		return parent->parent->right;
	}
	if (parent->data == parent->parent->right->data) {
		if (parent->parent->left == nullptr) {
			std::cout << "No left uncle!" << std::endl;
			return nullptr;
		}
		return parent->parent->left;
	}
	return nullptr;
}

Node* Node::get_grandparent() {
	if (parent == nullptr) {
		std::cout << "No parent!" << std::endl;
		return nullptr;
	}
	if (parent->parent == nullptr) {
		std::cout << "No grandparent!" << std::endl;
		return nullptr;
	}
	return parent->parent;
}

Node::~Node() {
	//pass, as there is no heap allocation
}

RB_Tree::RB_Tree() {
	//a new tree has no nodes
	root = nullptr;
	size = 0;
}

RB_Tree::~RB_Tree() {
	//pass, as there is no heap allocation
}

int main(int argc, char* argv[]) {
	std::cout << "We are noobs!" << std::endl;
}