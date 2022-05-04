#pragma once
#include "Vertex.h"

enum userInterface
{
	ShowMenu, Create, Add, Search, ShowBack, ShowInLine, Delete, Exit,
	BaseLevel = 1,
	Left = 1, Right = 2,
	Continue = 1
};

void printMenu();

int input();

void interface(Vertex*& pRoot);

void caseCreate(Vertex*& pRoot);

void caseAdd(Vertex*& pRoot);

void caseSearch(Vertex* pRoot);

void caseShowBack(Vertex* pRoot);

void caseShowInLine(Vertex* pRoot);

void caseDelete(Vertex*& pRoot);