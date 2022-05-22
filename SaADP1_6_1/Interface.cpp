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
		<< "\n3. Add vertex recursive."
		<< "\n4. Search vertex."
		<< "\n5. Inversely symmetrical tree output."
		<< "\n6. Tree output in line."
		<< "\n7. Delete a vertex."
		<< "\n8. Exit."
		<< endl;
}

int input()
{
	int option = 0; bool check = true; string optionInput;
	while (check)
	{
		try { cin >> optionInput; option = stoi(optionInput); check = false; }
		catch (const std::exception&) { cout << "   Wrong input.\n\n"; check = true; }
	}
	return option;
}

void interface(Vertex*& pRoot)
{
	bool stop = false; printMenu();
	while (!stop)
	{
		cout << "   Choice: ";
		switch (input())
		{
		case ShowMenu:     { printMenu(); break; }
		case Create:       { caseCreate(pRoot); break; }
		case Add:          { caseAdd(pRoot); break; }
		case AddRecursive: { caseAddRecursive(pRoot); break; }
		case Search:       { caseSearch(pRoot); break; }
		case ShowBack:     { caseShowBack(pRoot); break; }
		case ShowInLine:   { caseShowInLine(pRoot); break; }
		case Delete:       { caseDelete(pRoot); break;}
		case Exit:         { stop = true; break; }
		default:           std::cout << "   There is no such menu item.\n\n"; break;
		}
		cout << "   (0) - show menu.\n";
	}
}

void caseCreate(Vertex*& pRoot)
{
	Vertex* pCurrent;
	cout << "   Number of vertexes: "; int numbOfVertex = input();
	for (int i = 0; i < numbOfVertex; i++) { add(pRoot, randomCount()); }
}

void caseAdd(Vertex*& pRoot)
{
	Vertex* pCurrent;
	cout << "   Enter data to add (number):";
	addNonRecursive(pRoot, input());
}

void caseAddRecursive(Vertex*& pRoot)
{
	Vertex* pCurrent;
	cout << "   Enter data to add (number):";
	add(pRoot, input());
}

void caseSearch(Vertex* pRoot)
{
	Vertex* pCurrent;
	cout << "   Enter a vertex for search: ";
	bool check = false; search(pRoot, pCurrent, input(), check);
	if (check) { cout << "   Vertex: " << pCurrent->key << "(" << pCurrent->numbOfIdentical << ")\n"; return; }
	cout << "   There is no such vertex.\n";
}

void caseShowBack(Vertex* pRoot)
{
	if (pRoot == nullptr) { cout << "   Nothing to show.\n"; return; }
	cout << "_________________________\n";
	showBackSymmetric(pRoot, BaseLevel);
	cout << "_________________________\n";
}

void caseShowInLine(Vertex* pRoot)
{
	if (pRoot == nullptr) { cout << "   Nothing to show.\n"; return; }
	cout << "_________________________\n";
	showInLine(pRoot);
	cout << "_________________________\n";
}

void caseDelete(Vertex*& pRoot)
{
	cout << "   Enter a vertex for delete: ";
	deleteVertex(pRoot, input());
}