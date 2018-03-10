#include <iostream>
#include <limits>
#include "rbtree.hpp"

Node::Node() {
	data = std::numeric_limits<double>::quiet_NaN();
	parent = nullptr;
	left = nullptr;
	right = nullptr;
	color = RED;
}

Node::Node(int d, Color c, Node* l, Node* r, Node* p) {
	data = d;
	parent = p;
	left = l;
	right = r;
	color = c;
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
	//Node(int d, Color c, Node* l, Node* r, Node* p)
	Node* n1 = new Node(1);
	Node* n2 = new Node(2, RED, nullptr, nullptr, n1);
	Node* n3 = new Node(3, RED, nullptr, nullptr, n1);
	n1->left = n2;
	n1->right = n3;
	Node* n4 = new Node(4, RED, nullptr, nullptr, n2);
	Node* n5 = new Node(5, RED, nullptr, nullptr, n2);
	n2->left = n4;
	n2->right = n5;

	std::cout << n4->get_uncle()->data << std::endl;
	std::cout << n4->get_sibling()->data << std::endl;
	std::cout << n4->get_grandparent()->data << std::endl;
}
