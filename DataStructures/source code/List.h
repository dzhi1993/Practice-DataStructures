/*
*File: List.h
*Author: Da Zhi
*
*Created on March 28, 2016.
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#ifndef _LIST_H_
#define _LIST_H_

class List {
private:

	typedef struct node {
		int data;
		node* next;
	}*nodePtr;	//typedef struct node* nodePtr;//same as this line.

	nodePtr head;
	nodePtr curr;
	nodePtr temp;

public:
	List();
	void AddNode(int addData);
	void DeleteNode(int delData);
	void ReverseList();
	void PrintList();

};

class DoublyList {
private:
	typedef struct node {
		int data;
		node *pre;
		node *next;
	}*NodePtr;

	NodePtr head;
public:
	DoublyList();
	void AddNode(int data);
	void DeleteNode(int delData);
	void PrintList();

};




#endif /*_LIST_H_*/