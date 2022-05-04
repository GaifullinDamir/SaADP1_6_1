#include <iostream>
#include "Vertex.h"
using namespace std;
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
		else pCurrent = nullptr; check = false; break;
	}
}

int randomCount() { return MinNumber + rand() % (MaxNumber - MinNumber + 1); }

void add(Vertex* pCurrent, int key)
{
	if (treeIsEmpty(pCurrent))
	{
		pCurrent = new Vertex;
		pCurrent->key = key;
		pCurrent->left = pCurrent->right = nullptr;
		pCurrent->numbOfIdentical = 1;
		return;
	}
	else if (key < pCurrent->key) { add(pCurrent->left, key); return; }
	else if (key > pCurrent->key) { add(pCurrent->right, key); return; }
	pCurrent->numbOfIdentical++;
}

void addNonRecursive(Vertex* pRoot, Vertex* pCurrent, int key)
{
	if (treeIsEmpty(pRoot))
	{
		pRoot = new Vertex; pRoot->left = pRoot->right = nullptr;
		pRoot->key = key; pRoot->numbOfIdentical = 1;
		return;
	}
	Vertex* pParent;
	pCurrent = pRoot;
	while (pCurrent != nullptr)
	{
		pParent = pCurrent;
		if (key < pCurrent->key) { pCurrent = pCurrent->left; return; }
		else if (key > pCurrent->key) { pCurrent = pCurrent->right; return; }
		pCurrent->numbOfIdentical++; pCurrent = nullptr;
	}
	if (key < pParent->key)
	{
		pCurrent = new Vertex; pCurrent->left = pCurrent->right = nullptr; pCurrent->key = key;
		pParent->left = pCurrent;
		return;
	}
	else if (key < pParent->key)
	{
		pCurrent = new Vertex; pCurrent->left = pCurrent->right = nullptr; pCurrent->key = key;
		pParent->right = pCurrent;
		return;
	}
}

void addNumbOfVertex(Vertex* pRoot, Vertex* pCurrent, int choice, int numbOfVertex)
{
	switch (choice)
	{
	case Symmetric: for (int i = 0; i < numbOfVertex; i++) { add(pCurrent, randomCount()); }
	case NonSymmetric: for (int i = 0; i < numbOfVertex; i++) { addNonRecursive(pRoot, pCurrent, randomCount()); }
	default:
		cout << "   There is no such menu item.\n";
		break;
	}
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
		cout << pCurrent->key << "(" << pCurrent->numbOfIdentical << ")  ";
		showInString(pCurrent->right);
	}
}

void treeClearMemory(Vertex*& pCurrent)
{
	if (pCurrent != nullptr)
	{
		treeClearMemory(pCurrent->left);
		treeClearMemory(pCurrent->right);
		delete pCurrent;
		pCurrent = nullptr;
	}
}