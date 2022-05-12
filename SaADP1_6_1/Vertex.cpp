#include <iostream>
#include "Vertex.h"

using namespace std;

void search(Vertex* pRoot, Vertex*& pCurrent, int currentKey, bool check)
{
	check = true;
	while (pCurrent != nullptr && check)
	{
		if (currentKey < pCurrent->key) { pCurrent = pCurrent->left; return; }
		else if (currentKey < pCurrent->key) { pCurrent = pCurrent->right; return; }
		pCurrent = nullptr; 
		check = false; break;
	}
}

int randomCount() { return MinNumber + rand() % (MaxNumber - MinNumber + 1); }

void add(Vertex*& pCurrent, int key)
{
	if (pCurrent == nullptr)
	{
		pCurrent = new Vertex; pCurrent->key = key; pCurrent->left = pCurrent->right = nullptr;
		pCurrent->numbOfIdentical = 1; return;
	}
	else if (key < pCurrent->key) { add(pCurrent->left, key); return; }
	else if (key > pCurrent->key) { add(pCurrent->right, key); return; }
	pCurrent->numbOfIdentical++;
}

void addNonRecursive(Vertex*& pCurrent, int key)
{
	if (pCurrent == nullptr)
	{
		pCurrent = new Vertex; pCurrent->left = pCurrent->right = nullptr;
		pCurrent->key = key; pCurrent->numbOfIdentical = 1; return;
	}
	Vertex* pParent = nullptr;
	while (pCurrent != nullptr)
	{
		pParent = pCurrent;
		if (key < pCurrent->key) { pCurrent = pCurrent->left; return; }
		else if (key > pCurrent->key) { pCurrent = pCurrent->right; return; }
		pCurrent->numbOfIdentical++;
		pCurrent = nullptr;
	}
	if (key < pParent->key)
	{
		pCurrent = new Vertex; pCurrent->left = pCurrent->right = nullptr; pCurrent->key = key;
		pParent->left = pCurrent; return;
	}
	else if (key < pParent->key)
	{
		pCurrent = new Vertex; pCurrent->left = pCurrent->right = nullptr; pCurrent->key = key;
		pParent->right = pCurrent; return;
	}
}

void deleteVertex(Vertex*& pCurrent, int key)
{
	Vertex* pTemporary;
	if (pCurrent == nullptr) { cout << "   There is no such vertex.\n"; return;}
	else if (key < pCurrent->key) { deleteVertex(pCurrent->left, key); return;}
	else if (key > pCurrent->key) { deleteVertex(pCurrent->right, key); return; }
	pTemporary = pCurrent;
	if (pTemporary->right == nullptr) { pCurrent = pTemporary->left; return; }
	else if (pTemporary->left == nullptr) { pCurrent = pTemporary->right; return; }
	change(pCurrent->left, pTemporary);
	delete pTemporary; pTemporary = nullptr;
}

void change(Vertex*& pSurrogate, Vertex*& pTemporary)
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

void showInLine(Vertex* pCurrent)
{
	if (pCurrent != nullptr)
	{
		showInLine(pCurrent->left);
		cout << pCurrent->key << "(" << pCurrent->numbOfIdentical << ")  ";
		showInLine(pCurrent->right);
	}
}

void clearMemory(Vertex*& pCurrent)
{
	if (pCurrent != nullptr)
	{
		clearMemory(pCurrent->left);
		clearMemory(pCurrent->right);
		delete pCurrent;
		pCurrent = nullptr;
	}
}