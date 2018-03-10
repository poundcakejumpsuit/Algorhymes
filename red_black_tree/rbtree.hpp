#include <iostream>

enum Color {RED, BLACK};

struct Node {
	int data;
	Color color;
	Node* left;
	Node* right;
};