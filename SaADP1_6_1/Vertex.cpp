#include <iostream>
#include "Vertex.h"
using namespace std;
int gCounter = 0;
void treeInit(Vertex*& pRoot) { pRoot = nullptr; }

bool treeIsEmpty(Vertex* pRoot) { return pRoot == nullptr; }

void search(Vertex* pRoot, Vertex*& pCurrent, int currentKey, bool check)
{
	Vertex* pCurrent = pRoot;
	check = true;
	while (pCurrent != nullptr && check)
	{
		if (currentKey < pCurrent->key) { pCurrent = pCurrent->left; }
		else if (currentKey < pCurrent->key) { pCurrent = pCurrent->right; }
		else pCurrent = nullptr; check = false; gCounter++; break;
	}
}

void addVertex(Vertex* pCurrent, int key)
{
	if (treeIsEmpty(pCurrent))
	{
		pCurrent = new Vertex;
		pCurrent->key = key;
		pCurrent->left = pCurrent->right = nullptr;
		pCurrent->numbOfVertex = gCounter = 1;
		return;
	}
	else if (key < pCurrent->key) { addVertex(pCurrent->left, key); return; }
	else if (key > pCurrent->key) { addVertex(pCurrent->right, key); return; }
	pCurrent->numbOfVertex++; gCounter++;
}

void deleteVertex(Vertex* pCurrent, int key)
{
	Vertex* pTemporary;
	if (pCurrent == nullptr) { cout << "   Nothing to delete.\n"; return; }
	else if (key < pCurrent->key) { deleteVertex(pCurrent->left, key); return; }
	else if (key > pCurrent->key) { deleteVertex(pCurrent->right, key); return; }
	pTemporary = pCurrent;
	if (pTemporary->right == nullptr) { pCurrent = pTemporary->left; return; }
	else if (pTemporary->left == nullptr) { pCurrent = pTemporary->right; return; }
	change(pCurrent->left, pTemporary);
	delete pTemporary; pTemporary = nullptr;
}

void change(Vertex* pSurrogate, Vertex*& pTemporary)
{
	if (pSurrogate->right != nullptr) { change(pSurrogate->right, pTemporary); return; }
	pTemporary->key = pSurrogate->key;
	pTemporary = pSurrogate;
	pSurrogate = pSurrogate->left;
}

void showBackSymmetric(Vertex* pCurrent, int level)
{
	if (pCurrent != nullptr)
	{
		level++;
		showBackSymmetric(pCurrent->right, level);
		for (int i = 0; i < level - 1; i++) { cout << "   "; }
		cout << pCurrent->key << endl;
		showBackSymmetric(pCurrent->left, level);
	}
}

void showInString(Vertex* pCurrent)
{
	if (pCurrent != nullptr)
	{
		showInString(pCurrent->left);
		cout << pCurrent->key << "(" << pCurrent->numbOfVertex << ")  ";
		showInString(pCurrent->right);
	}
}

void searcTheSame(Vertex*& pCurrent, int key)
{

}