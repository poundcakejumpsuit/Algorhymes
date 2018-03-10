#include <iostream>
#include "rbtree.hpp"


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