#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <sstream>

namespace visualisation {

	struct Node {
		std::string english;
		std::string russian;
		int frequency = 0;
		int letternumber = 0;
		Node *left, *right;
	};

	//functions for graph visualization in GraphViz
	void bst_print_dot_null(Node *key, int nullcount, FILE* stream);
	void bst_print_dot_aux(Node* node, FILE* stream);
	void bst_print_dot(Node* tree, FILE* stream);

	void gotoxy(int x, int y);
	int DisplayMainMenu();
	int DisplayMainMenu2();
}