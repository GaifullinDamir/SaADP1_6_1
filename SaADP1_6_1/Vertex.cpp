#include "Vertex.h"
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
		else pCurrent = nullptr; check = false; gCounter++;
	}
}

void addVertex(Vertex* pCurrent, int key)
{
	if (treeIsEmpty(pCurrent))
	{
		pCurrent = new Vertex;
		pCurrent->key = key;
		pCurrent->left = pCurrent->right = nullptr;
		gCounter = 1;
		return;
	}
	else if (key < pCurrent->key) { addVertex(pCurrent->left, key); }
	else if (key > pCurrent->key) { addVertex(pCurrent->right, key); }
	else gCounter++;
}