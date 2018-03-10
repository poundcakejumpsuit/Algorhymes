#include <iostream>
#include <cstdint>

enum Color {RED, BLACK};

class Node {
public:
	Node();
	Node(int d);
	~Node();
private:
	int data;
	Color color;
	Node* left;
	Node* right;
	Node* parent;
	Node* get_sibling();
	Node* get_uncle();
	Node* get_grandparent();
	friend class RB_Tree;
};

class RB_Tree {
public:
	RB_Tree();
	~RB_Tree();
	void insert(Node* node);
	void rotate_right(Node* node);
	void rotate_left(Node* node);
	void delete_node(Node* node);
private:
	Node* root;
	uint64_t size;
};
