// Alphabetic Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Visualisation.h"

#pragma warning(disable : 4996);

unsigned int num = 0;
visualisation::Node* head = NULL;

visualisation::Node* new_element(std::string english, int frequency) {
	visualisation::Node* temp = new visualisation::Node();
	temp->english = english;
	temp->frequency = frequency;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insertNode(visualisation::Node* head, visualisation::Node* element) {
	visualisation::Node* x = head;
	while (true) {
		int i = x->english.compare(element->english);
		if (i == 0) {
			x->frequency++;
			break;
		}
		else if (i > 0) {
			if (x->left == NULL) {
				x->left = element;
				break;
			}
			else x = x->left;
		}
		else if (i < 0) {
			if (x->right == NULL) {
				x->right = element;
				break;
			}
			else x = x->right;
		}
	}
}

void insertNode2(visualisation::Node* head, visualisation::Node* element) {
	visualisation::Node* x = head;
	while (true) {
		int i = 0;
		if (x->frequency >= element->frequency) i = -1; else
			if (x->frequency < element->frequency) i = 1;

		if (i < 0) {
			if (x->left == NULL) {
				x->left = element;
				break;
			}
			else x = x->left;
		}
		else if (i > 0) {
			if (x->right == NULL) {
				x->right = element;
				break;
			}
			else x = x->right;
		}
	}
}

void insertNode3(visualisation::Node* head, visualisation::Node* element) {
	visualisation::Node* x = head;
	while (true) {
		int i = 0;
		if (x->english.size() >= element->english.size()) i = -1; else
			if (x->english.size() < element->english.size()) i = 1;
		if (i > 0) {
			if (x->left == NULL) {
				x->left = element;
				break;
			}
			else x = x->left;
		}
		else if (i < 0) {
			if (x->right == NULL) {
				x->right = element;
				break;
			}
			else x = x->right;
		}
	}
}

visualisation::Node *WordSplit() {
	std::fstream file;
	std::string word, filename;
	filename = "file.txt";
	file.open(filename.c_str());
	visualisation::Node* head = NULL;
	int wordnumber;
	if (file.is_open())
	{
		file >> word;
		head = new_element(word, 0);
		while (file >> word)
			insertNode(head, new_element(word, 0));
	}
	FILE* f = fopen("output.txt", "w+b");
	visualisation::bst_print_dot(head, f);
	return head;
}

void printInorderEnglish(visualisation::Node* node)
{
	if (node == NULL)
		return;

	printInorderEnglish(node->left);
	std:: cout << node->english << " ";
	printInorderEnglish(node->right);
}

void swap(visualisation::Node* xp, visualisation::Node* yp)
{
	visualisation::Node temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void AddArray(visualisation::Node* node, visualisation::Node** arr) // array of pointers to the Node
{
	if (node == NULL)
		return;
	arr[num] = new visualisation::Node;
	arr[num] = node;
	num++;
	AddArray(node->left, arr);
	AddArray(node->right, arr);
}

visualisation::Node* rebuildTree_frequency() {
	visualisation::Node** arr = NULL;
	arr = new visualisation::Node*[100];
	AddArray(head, arr);
	visualisation::Node* head2 = NULL;
	head2 = new_element(arr[0]->english, arr[0]->frequency);
	for (int k = 1; k < num; k++) insertNode2(head2, new_element(arr[k]->english, arr[k]->frequency));
	printInorderEnglish(head2);
	return head2;
}

visualisation::Node* rebuildTree_character_number() {
	visualisation::Node** arr = NULL;
	arr = new visualisation::Node*[100];
	AddArray(head, arr);
	visualisation::Node* head2 = NULL;
	head2 = new_element(arr[num - 1]->english, arr[num - 1]->frequency);
	for (int k = num - 2; k >= 0; k--) insertNode3(head2, new_element(arr[k]->english, arr[k]->frequency));
	printInorderEnglish(head2);
	return head2;
}

int main()
{
	head = WordSplit();
	while (1)
	{
		num = 0;
		int choice = visualisation::DisplayMainMenu2();
		switch (choice) {
		case 1:
			::system("cls");
			printInorderEnglish(head);
			system("pause");
			break;
		case 2: 
		{
			::system("cls");
			head = rebuildTree_frequency();
			system("pause");
			break;
		}
		case 3:
		{
			::system("cls");
			head = rebuildTree_character_number();

			system("pause");
			break;
		}	
		case 4: 
		{ 
			FILE* f = fopen("output.txt", "w+b");
			visualisation::bst_print_dot(head, f);
			fclose(f);
			break;
		}
		case 5:
		default:
			return 0;
		};
	}
}

