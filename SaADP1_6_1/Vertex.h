#pragma once
struct Vertex
{
	int key, numbOfVertex;
	Vertex* left, * right;
};

void treeInit(Vertex*& pRoot);


