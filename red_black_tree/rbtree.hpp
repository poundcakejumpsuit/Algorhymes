#include <iostream>
#include <cstdint>

enum Color {RED, BLACK};

struct Node {
	int data;
	Color color;
	Node* left;
	Node* right;
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