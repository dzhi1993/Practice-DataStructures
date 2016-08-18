/*
*File: Stack.h
*Author: Da Zhi
*
*Created on April 1, 2016.
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#ifndef _STACK_H_
#define _STACK_H_

class Stack {
private:

	struct item {
		string name;
		int value;
		item* pre;
	};

	item* stackPtr;

public:

	Stack();
	~Stack();

	void Push(string name, int value);
	void Pop();
	void ReadItem(item* r);
	void Print();

};

#endif