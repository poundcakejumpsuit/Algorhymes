#include <iostream>
#include <cstdint>
#include <limits>

enum Color {RED, BLACK};

class Node {
public:
	// Node();
	Node(int d=std::numeric_limits<double>::quiet_NaN(), 
			Color c=RED, 
			Node* l=nullptr, 
			Node* r=nullptr, 
			Node* p=nullptr);
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
	void print();
	uint64_t get_size();
	int black_height(Node* root);
	int bh();
	void node_table(Node* n);
	void node_info(Node* n);
	void delete_a_child(Node* n);
	void delete_case1(Node* n);
	void delete_case2(Node* n);
	void delete_case3(Node* n);
	void delete_case4(Node* n);
	void delete_case5(Node* n);
	void replace_node(Node* out, Node* in);
	Node* copy_node(Node* orig);
private:
	Node* root;
	uint64_t size;
};
