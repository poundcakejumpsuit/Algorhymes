#include <iostream>
#include <limits>
#include <cassert>
#include <iomanip>
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

RB_Tree::RB_Tree(Node* r) {
	root = r;
}

RB_Tree::~RB_Tree() {
	//pass, as there is no heap allocation
}

void RB_Tree::rotate_left(Node* n) {
	Node* n_new = n->right;
	assert(n_new->left != nullptr && n_new->right != nullptr);
	n->right = n_new->left;
	n_new->right->parent = n->parent;
	n_new->left = n;
	n_new->parent = n->parent;
	if (n->parent != nullptr) {
		if (n == n->parent->right) {
			n->parent->right = n_new;
		}
		else {
			n->parent->left = n_new;
		}
	}
	n->parent = n_new;
}

void RB_Tree::rotate_right(Node* n) {
	Node* n_new = n->left;
	assert(n_new->left != nullptr && n_new->right != nullptr);
	n->left = n_new->right;
	n_new->left->parent = n->parent;
	n_new->right = n;
	n_new->parent = n->parent;
	if (n->parent != nullptr) {
		if (n == n->parent->right) {
			n->parent->right = n_new;
		}
		else {
			n->parent->left = n_new;
		}
	}
	n->parent = n_new;
}

void RB_Tree::postorder(Node* p, int indent)
{
    if(p != NULL) {
        if(p->right) {
            postorder(p->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< p->data << "\n ";
        if(p->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            postorder(p->left, indent+4);
        }
    }
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
	Node* n6 = new Node(6, RED, nullptr, nullptr, n3);
	Node* n7 = new Node(7, RED, nullptr, nullptr, n3);
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
	Node* n8 = new Node(8, RED, nullptr, nullptr, n5);
	Node* n9 = new Node(9, RED, nullptr, nullptr, n5);
	Node* n10 = new Node(10, RED, nullptr, nullptr, n4);
	Node* n11 = new Node(11, RED, nullptr, nullptr, n4);
	n5->left = n8;
	n5->right = n9;
	n4->left = n10;
	n4->right = n11;
	RB_Tree* rb = new RB_Tree(n1);
	rb->postorder(n1);
	std::cout << "--------------------------------------" << std::endl;
	rb->rotate_right(n2);
	rb->postorder(n1);
	rb->rotate_left(n4);
	std::cout << "--------------------------------------" << std::endl;
	rb->postorder(n1);

	// std::cout << n4->get_uncle()->data << std::endl;
	// std::cout << n4->get_sibling()->data << std::endl;
	// std::cout << n4->get_grandparent()->data << std::endl;
}
