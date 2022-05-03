#include "Vertex.h"
void treeInit(Vertex*& pRoot) { pRoot = nullptr; }

bool treeIsEmpty(Vertex* pRoot) { return pRoot == nullptr; }

void search(Vertex* pRoot, Vertex* pCurrent, int currentKey, bool check)
{
	Vertex* pCurrent = pRoot;
	check = true;
	while (pCurrent != nullptr && check)
	{
		if (currentKey < pCurrent->key) { pCurrent = pCurrent->left; }
		else if (currentKey < pCurrent->key) { pCurrent = pCurrent->right; }
		else check = false;
	}
}
