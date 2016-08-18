#include <iostream>
#include <cstdlib>

#include "Queue.h"

using namespace std;

Queue::Queue() {
	head = NULL;
	tail = NULL;
}

Queue::~Queue() {

	item* QueuePtr = NULL;

	while (head != NULL) {
		QueuePtr = head;
		head = head->next;
		delete QueuePtr;
	}

}

void Queue::InQueue(int data) {

	item *QueuePtr = new item;
	QueuePtr->data = data;
	QueuePtr->next = NULL;

	if (head == NULL) {
		head = QueuePtr;
		tail = QueuePtr;
	}
	else {
		tail->next = QueuePtr;
		tail = QueuePtr;
	}

}

void Queue::OutQueue() {
	item *QueuePtr = NULL;

	if (head == NULL) {
		cout << "There is nothing in the Queue!" << endl;
	}
	else {
		QueuePtr = head;
		head = head->next;
		delete QueuePtr;
	}

}

void Queue::Print() {

	if (head == NULL) {
		cout << "There is nothing in the Queue!" << endl;
	}
	else {
		item *QueuePtr = NULL;
		QueuePtr = head;
		while (QueuePtr != NULL) {
			cout << QueuePtr->data << " ";
			QueuePtr = QueuePtr->next;
		}
		cout << endl;
	}

}

