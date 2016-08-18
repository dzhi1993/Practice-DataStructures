/*
*File: BiTree.h
*Author: Da Zhi
*
*Created on April 21, 2016.
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#ifndef _BST_H_
#define _BST_H_

class BST {
private:
	struct node {
		int value;
		node* left;
		node* right;
	};

	node* root;
	node* CreateLeaf(int value);
	node* ReturnNode(int value);
	void AddLeafPrivate(int value, node* Ptr);
	void printInOrderPrivate(node* Ptr);
	node* ReturnNodePrivate(int value, node* Ptr);
	int FindSmallestPrivate(node* Ptr);
	void RemoveNodePrivate(int value, node* parent);
	void RemoveRootMatch();
	void RemoveMatch(node* parent, node* match, bool left);
	void RemoveSubtree(node* Ptr);

public:

	BST();
	~BST();

	void AddLeaf(int value);
	void printInOrder();
	int  ReturnRootValue();
	void PrintChildren(int value);
	int  FindSmallest();
	void RemoveNode(int value);

};

#endif
