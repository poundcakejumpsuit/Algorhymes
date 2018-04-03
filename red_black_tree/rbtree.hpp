#include <iostream>
#include <cstdint>
#include <limits>

enum class Color {RED, BLACK};

class Node {
public:
	Node(int d=std::numeric_limits<int>::quiet_NaN(), 
			Color c=Color::RED, 
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
	uint64_t compute_size(Node* n);
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
	void postorder(Node* n, int indent=0);
	void print();
	uint64_t get_size();
	uint64_t black_height(Node* root);
	uint64_t bh();
	void node_table(Node* n);
	void node_info(Node* n);
	void delete_node(Node* n);
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
