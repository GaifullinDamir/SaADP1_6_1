#pragma once
#include "Vertex.h"

enum userInterface
{
	ShowMenu, Add, ShowForward, ShowSymmetric, ShowBack, Delete, Exit,
	BaseLevel = 1,
	Left = 1, Right = 2,
	Continue = 1
};

void printMenu();

int input();

void interface(Vertex*& pRoot);

void caseAdd(Vertex*& pRoot);
