#include <iostream>
#include <cstdint>
#include <limits>

enum Color {RED, BLACK};

class Node {
public:
	Node();
	Node(int d=std::numeric_limits<double>::quiet_NaN(), Color c=RED, Node* l=nullptr, Node* r=nullptr, Node* p=nullptr);
	~Node();
public:
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
	RB_Tree(Node* r);
	~RB_Tree();
	void insert(Node* n);
	void insert_recurse(Node* cur_node, Node* n);
	void insert_repair_tree(Node* n);
	void insert_case1(Node* n);
	void insert_case2(Node* n);
	void insert_case3(Node* n);
	void insert_case4(Node* n);
	void insert_case4step2(Node* n);
	void rotate_right(Node* node);
	void rotate_left(Node* node);
	void delete_node(Node* node);
	void postorder(Node* n, int indent=0);
private:
	Node* root;
	uint64_t size;
};
