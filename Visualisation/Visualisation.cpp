#include "Visualisation.h"
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <string>
#include <windows.h> 
#include <sstream>
#include <conio.h>


namespace visualisation {

	void bst_print_dot_null(Node *key, int nullcount, FILE* stream)
	{
		fprintf(stream, "    null%d [shape=point];\n", nullcount);
		fprintf(stream, "    %s -> null%d;\n", key->english.c_str(), nullcount);
	}

	void bst_print_dot_aux(Node* node, FILE* stream)
	{
		static int nullcount = 0;
		static int dotcount = 0;
		if (node->left)
		{
			fprintf(stream, "    %s -> %s;\n", node->english.c_str(), node->left->english.c_str());
			bst_print_dot_aux(node->left, stream);
		}
		else
			bst_print_dot_null(node, nullcount++, stream);

		if (node->right)
		{
			fprintf(stream, "    %s -> %s;\n", node->english.c_str(), node->right->english.c_str());
			bst_print_dot_aux(node->right, stream);
		}
		else
			bst_print_dot_null(node, nullcount++, stream);
	}

	void bst_print_dot(Node* tree, FILE* stream)
	{
		fprintf(stream, "digraph BST {\n");
		fprintf(stream, "    node [fontname=\"Arial\"];\n");

		if (!tree)
			fprintf(stream, "\n");
		else if (!tree->right && !tree->left) {
			fprintf(stream, "    %s;\n", tree->english.c_str());
			//fprintf(stream, "    \"%s\";\n", tree->info.c_str());
		}
		else
			bst_print_dot_aux(tree, stream);
		fprintf(stream, "}\n");
	}

	void gotoxy(int x, int y)
	{
		COORD ord;
		ord.X = x;
		ord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ord);
	}

	int DisplayMainMenu() {
		::system("cls");
		gotoxy(5, 4);

		std::cout << "___________________________________________";
		gotoxy(5, 6);
		std::cout << "1. Add words";

		gotoxy(5, 7);
		std::cout << "2. Tree appearance";

		gotoxy(5, 8);
		std::cout << "3. Search words";

		gotoxy(5, 9);
		std::cout << "4. Rebuild tree";

		gotoxy(5, 10);
		std::cout << "5. Exit";

		gotoxy(5, 11);
		std::cout << "___________________________________________";

		gotoxy(5, 13);
		std::cout << "Your choice: ";
		int m = -1;
		std::cin >> m;

		return m;
	}

	int DisplayMainMenu2() {
		::system("cls");
		gotoxy(5, 4);

		std::cout << "___________________________________________";
		gotoxy(5, 6);
		std::cout << "1. Sort by Alphabetic Order";

		gotoxy(5, 7);
		std::cout << "2. Sort by Frequency";

		gotoxy(5, 8);
		std::cout << "3. Sort by Character Number";

		gotoxy(5, 9);
		std::cout << "4. Tree appearance";

		gotoxy(5, 10);
		std::cout << "5. Exit";

		gotoxy(5, 11);
		std::cout << "___________________________________________";

		gotoxy(5, 13);
		std::cout << "Your choice: ";
		int m = -1;
		std::cin >> m;

		return m;
	}

}