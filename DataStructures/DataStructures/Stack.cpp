#include <iostream>
#include <cstdlib>
#include <string>
#include "Stack.h"

using namespace std;

Stack::Stack() {
	stackPtr = NULL;
}

Stack::~Stack() {//destory this stack

	item* P1;
	item* P2;

	P1 = stackPtr;
	while (P1 != NULL) {
		P2 = P1;
		P1 = P1->pre;
		P2->pre = NULL;
		delete P2;
	}

}

void Stack::Push(string name, int value) {

	item *n = new item;
	n->name = name;
	n->value = value;

	if (stackPtr == NULL) {//if the stack is empty
		stackPtr = n;
		stackPtr->pre = NULL;
	}
	else {
		n->pre = stackPtr;
		stackPtr = n;
	}

}

void Stack::ReadItem(item *r) {
	cout << "-----------------------------------------" << endl;
	cout << "name is: " << r->name << endl;
	cout << "value is: " << r->value << endl;
	cout << "-----------------------------------------" << endl;
}

void Stack::Pop() {

	if (stackPtr == NULL) {
		cout << "there is nothing on the stack!" << endl;
	}
	else {
		item* p = stackPtr;
		ReadItem(p);
		stackPtr = stackPtr->pre;
		p->pre = NULL;
		delete p;
	}

}

void Stack::Print() {

	item* p = stackPtr;

	while (p != NULL) {
		ReadItem(p);
		p = p->pre;
	}
}