// TreeText.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Visualisation.h"
#include <iostream>
#include <string>
#include <fstream>

#pragma warning(disable : 4996);
void searchWord();
void inputWords();
visualisation::Node* new_element(std::string english, std::string russian, int frequency);
void insertNode(visualisation::Node *head, visualisation::Node *element);
visualisation::Node* rebuildTree();
void bubbleSort(visualisation::Node** arr, int n);
void swap(visualisation::Node* xp, visualisation::Node* yp);
void AddArray(visualisation::Node* node, visualisation::Node** arr);

visualisation::Node *head = NULL;
int i = 0;

int main()
{
	while (1)
	{
		int choice = visualisation::DisplayMainMenu();
		switch (choice) {
			case 1:
				inputWords();
				break;
			case 2:
			{
				FILE *f = fopen("output.txt", "w+b");
				visualisation::bst_print_dot(head, f);
				fclose(f);
				break;
			}
			case 3:
				searchWord();
				break;
			case 4:
				head = rebuildTree();
				break;
			case 5:
			default:
				return 0;
		};
	}
}

visualisation::Node *rebuildTree() {
	visualisation::Node** arr = NULL;
	arr = new visualisation::Node*();
	AddArray(head, arr);
	bubbleSort(arr, i);
	visualisation::Node* head2 = NULL;
	head2 = new_element(arr[i-1]->english, arr[i-1]->russian, arr[i-1]->frequency);
	for (int k = i-2; k >= 0; k--) insertNode(head2, new_element(arr[k]->english, arr[k]->russian, arr[k]->frequency));
	return head2;
}

void AddArray(visualisation::Node* node, visualisation::Node** arr) // array of pointers to the Node
{
	if (node == NULL)
		return;
	arr[i] = new visualisation::Node();
	arr[i] = node;
	i++;
	AddArray(node->left, arr);
	AddArray(node->right, arr);
}

void bubbleSort(visualisation::Node** arr, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place    
		for (j = 0; j < n - i - 1; j++)
			if (arr[j]->frequency > arr[j + 1]->frequency)
				swap(arr[j], arr[j + 1]);
}

void swap(visualisation::Node *xp, visualisation::Node *yp)
{
	visualisation::Node temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void searchWord() {
	::system("cls");
	visualisation::Node *x = head;
	int success = false;
	std::string word;
	std::cout << "English: ";
	std::cin >> word;

	while (true) {
		int i = x->english.compare(word);
		if (i == 0) {
			success = true;
			x->frequency = x->frequency++;
			break;
		}
		else if (i > 0) {
			if (x->left == NULL) {
				success = false;
				break;
			}
			else x = x->left;
		}
		else if (i < 0) {
			if (x->right == NULL) {
				success = false;
				break;
			}
			else x = x->right;
		}
	}

	if (success == false) std::cout << "Word is not found"; else
		std::cout << "Russian: " << x->russian << "\n";
	system("pause");
}

void inputWords() {
	::system("cls");
	std::string english;
	std::string russian;
	std::cout << "Add words \n";
	std::cout << "English: ";
	std::cin >> english;
	std::cout << "Russian: ";
	std::cin >> russian;
	if (head != NULL)
		insertNode(head, new_element(english, russian, 0)); else
		head = new_element(english, russian, 0);
}

visualisation::Node *new_element(std::string english, std::string russian, int frequency) {
	visualisation::Node *temp = new visualisation::Node();
	temp->english = english;
	temp->russian = russian;
	temp->frequency = frequency;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insertNode(visualisation::Node *head, visualisation::Node *element) {
	visualisation::Node *x = head;
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






