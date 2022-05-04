#include <iostream>
#include <string>
#include "Interface.h"
#include "Vertex.h"
using namespace std;

void printMenu()
{
	cout << endl;
	cout
		<< "\n1. Add number of vertex in tree."
		<< "\n2. Add vertex."
		<< "\n3. Search vertex."
		<< "\n4. Inversely symmetrical tree output."
		<< "\n5. Tree output in line."
		<< "\n6. Delete a vertex."
		<< "\n7. Exit."
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
		case Create: { caseCreate(pRoot); break; }
		case Add: { cout << "   Enter data to add (number):"; addNonRecursive(pRoot, input()); break; }
		case Search: {caseSearch(pRoot); break; }
		case ShowBack: {}
		case Exit: { stop = true; break; }
		default:
			std::cout << "   There is no such menu item." << std::endl; std::cout << std::endl; break;
		}
		std::cout << "   (0) - show menu." << std::endl;
	}
}

void caseCreate(Vertex*& pRoot)
{
	cout << "   Number of vertexes: "; 
	for (int i = 0; i < input(); i++) { add(pRoot, randomCount()); }
}

void caseSearch(Vertex* pRoot)
{
	Vertex* pCurrent;
	cout << "   Enter a vertex for search: ";
	bool check = false; search(pRoot, pCurrent, input(), check);
	if (check) { cout << "   Vertex: " << pCurrent->key << "(" << pCurrent->numbOfIdentical << ")\n"; return; }
	cout << "   There is no such vertex.\n";
}
void caseShow(Vertex* pRoot)
{
	if (pRoot != nullptr)
	{
		cout << "_________________________" << endl;
		showBackSymmetric(pRoot, BaseLevel);
		cout << "_________________________" << endl;
		return;
	}
	cout << "   Nothing to show.\n";
	
}
