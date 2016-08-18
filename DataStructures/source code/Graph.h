/*
*File: BiTree.h
*Author: Da Zhi
*
*Created on August 16, 2016.
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#ifndef TREES_H
#define TREES_H

struct node
{
	char * PreClassName;
	node * next;
};

struct vertex
{
	char * ClassName;
	node * nodehead;
	vertex * next;
};

class Graph
{
public:
	Graph();
	~Graph();

	int AddVert(char * sendclass);
	int AddEdge(char * sendclass, char * preclass);
	int RemoveVert(char * sendclass);
	int RemoveEdge(char * sendclass, char * preclass);
	void Display();

private:
	vertex * head;
	vertex * tail;
};

#endif