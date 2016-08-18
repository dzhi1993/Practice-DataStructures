/*
*File: hashTable.h
*Author: Da Zhi
*
*Created on March 28, 2016.
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_


class hashTable {
private:
	static const int tableSize = 10;

	struct item {
		string name;
		string drink;
		item* next;
	};

	item* HashTable[tableSize];

public:
	int getTableSize() {
		return tableSize;
	}
	hashTable();
	int Hash(string key);
	void AddItem(string name, string drink);
	int NumberOfItemsInIndex(int index);
	void PrintTable();
	void PrintItemsInIndex(int index);
	void FindDrink(string name);
	void RemoveItem(string name);

};


#endif 