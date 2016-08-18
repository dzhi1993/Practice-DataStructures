/*
*File: Queue.h
*Author: Da Zhi
*
*Created on April 3, 2016.
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#ifndef _QUEUE_H_
#define _QUEUE_H_

class Queue {
private:

	struct item {
		int data;
		item* next;
	};

	item* head;
	item* tail;

public:
	Queue();
	~Queue();
	void InQueue(int data);
	void OutQueue();
	void Print();

};

//#endif

//#ifndef _CIRCULARQUEUE_H_
//#define _CIRCULARQUEUE_H_

class CircualrQueue {
private:
	static const int MaxCircualrQueueSize = 10;

	typedef struct item {
		int data;
		item *next;
	}CircularQueuePtr;

	CircularQueuePtr front;
	CircularQueuePtr rear;
	int count;

public:
	int getSize() {
		return MaxCircualrQueueSize;
	};
	CircualrQueue();
	~CircualrQueue();

};

#endif