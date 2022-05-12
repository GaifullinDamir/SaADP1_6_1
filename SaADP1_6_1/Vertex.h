#pragma once
struct Vertex
{
	int key, numbOfIdentical;
	Vertex* left, * right;
};

enum vertex { MinNumber = 1, MaxNumber = 15 };

void search(Vertex* pRoot, Vertex*& pCurrent, int currentKey, bool check);

int randomCount();

void add(Vertex*& pCurrent, int key);

void addNonRecursive(Vertex*& pCurrent, int key);

void deleteVertex(Vertex*& pCurrent, int key);

void change(Vertex*& pSurrogate, Vertex*& pTemporary);

void showBackSymmetric(Vertex* pCurrent, int level);

void showInLine(Vertex* pCurrent);

void clearMemory(Vertex*& pCurrent);