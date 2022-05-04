#pragma once
struct Vertex
{
	int key, numbOfIdentical;
	Vertex* left, * right;
};

enum vertex
{
	Symmetric = 1, NonSymmetric = 2,
	MinNumber = 1, MaxNumber = 250
};

void treeInit(Vertex*& pRoot);

void search(Vertex* pRoot, Vertex*& pCurrent, int currentKey, bool check);

int randomCount();

void add(Vertex* pCurrent, int key);

void addNonRecursive(Vertex* pCurrent, int key);

void addNumbOfVertex(Vertex* pCurrent, int choice, int numbOfVertex);

void deleteVertex(Vertex* pCurrent, int key);

void change(Vertex* pSurrogate, Vertex*& pTemporary);

void showBackSymmetric(Vertex* pCurrent, int level);

void showInString(Vertex* pCurrent);

void treeClearMemory(Vertex*& pCurrent);