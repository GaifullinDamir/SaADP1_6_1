#include <iostream>
#include <string>
#include "Interface.h"
#include "Vertex.h"
using namespace std;

void printMenu()
{
	cout << endl;
	cout
		<< "\n1. Adding a number of vertex."
		<< "\n2. Forward tree output."
		<< "\n3. Symmetrical tree output."
		<< "\n4. Inversely symmetrical tree output."
		<< "\n5. Delete tree."
		<< "\n6. Exit."
		<< endl;
}

int input()
{
	int option = 0; bool check = true; string optionInput;
	while (check)
	{
		try { cin >> optionInput; option = stoi(optionInput); check = false; }
		catch (const std::exception&) { cout << "   Wrong input." << endl; cout << endl; check = true; }
	}
	return option;
}

void interface(Vertex*& pRoot)
{
	bool stop = false;
	printMenu();
	while (!stop)
	{
		cout << "   Choice: ";
		switch (input())
		{
		case ShowMenu: { printMenu(); break; }
		case Add: { caseAdd(pRoot); break; }
		case ShowForward:
		{
			if (!treeIsEmpty(pRoot))
			{
				cout << "_________________________" << endl;
				showForward(pRoot, BaseLevel);
				cout << "_________________________" << endl;
			}
			else cout << "   Nothing to show." << endl;
			break;
		}
		case ShowSymmetric:
		{
			if (!treeIsEmpty(pRoot))
			{
				cout << "_________________________" << endl;
				showSymmetric(pRoot, BaseLevel);
				cout << "_________________________" << endl;
			}
			else cout << "   Nothing to show." << endl;
			break;
		}
		case ShowBack:
		{
			if (!treeIsEmpty(pRoot))
			{
				cout << "_________________________" << endl;
				showBackSymmetric(pRoot, BaseLevel);
				cout << "_________________________" << endl;
			}
			else cout << "   Nothing to show." << endl;
			break;
		}
		case Delete:
		{
			if (!treeIsEmpty(pRoot)) { treeClearMemory(pRoot); cout << "   Complete." << endl; }
			else cout << "   Nothing to delete." << endl;
			break;
		}
		case Exit: { stop = true; break; }
		default:
			std::cout << "   There is no such menu item." << std::endl; std::cout << std::endl; break;
		}
		std::cout << "   (0) - show menu." << std::endl;
	}
}

void caseAdd(Vertex*& pRoot)
{
	Vertex* pCurrent = pRoot;
	Vertex* pSearched;
	if (treeIsEmpty(pRoot))
	{
		cout << "   Enter data to add: "; int data = input();
		add(pRoot, pSearched, data);
	}
	else
	{
		bool check = false;
		cout << "   Enter data to search: ";
		int searchedData = input();
		searchVertex(pCurrent, pSearched, searchedData, check);
		if (check)
		{
			if (pSearched->left != nullptr && pSearched->right != nullptr) { cout << "   The vertex is full." << endl; }
			else
			{
				cout << "   Enter data to add: "; int data = input();
				add(pRoot, pSearched, data);
			}
		}
		else cout << "   No such vertex." << endl;
	}
}