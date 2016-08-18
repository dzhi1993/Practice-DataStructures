#include <iostream>
#include <cstdlib>
#include <string>

#include "hashTable.h"

using namespace std;


hashTable::hashTable() {
	for (int i = 0; i<tableSize; i++) {//initialize
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;
	}

}

int hashTable::Hash(string key) {
	int hashTable = 0;
	int index;

	for (int i = 0; i < key.length(); i++) {
		hashTable = hashTable + (int)key[i];
	}

	//cout<< "hashTable =" << hashTable <<endl;
	index = hashTable % tableSize;
	//index = key.length();

	//cout<<"key[0] = "<<(int) key[0]<<endl;
	//cout<<"key[1] = "<<(int) key[1]<<endl;
	//cout<<"key[2] = "<<(int) key[2]<<endl;
	//cout<<"key[3] = "<<(int) key[3]<<endl;

	return index;
}

int hashTable::NumberOfItemsInIndex(int index) {
	int count = 0;

	if (HashTable[index]->name == "empty") {
		return count;
	}
	else {
		count++;
		item* Ptr = HashTable[index];
		while (Ptr->next != NULL) {
			count++;
			Ptr = Ptr->next;
		}
	}
	return count;
}

void hashTable::AddItem(string name, string drink) {
	int index = Hash(name);

	if (HashTable[index]->name == "empty") {

		HashTable[index]->name = name;
		HashTable[index]->drink = drink;

	}
	else {

		item* Ptr = HashTable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;

		while (Ptr->next != NULL) {
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}
}

void hashTable::FindDrink(string name) {
	int index = Hash(name);

	if (HashTable[index]->name == name) {
		cout << name << " likes drink " << HashTable[index]->drink << endl;
	}
	else {
		item* Ptr = HashTable[index]->next;
		while (Ptr->name != name) {
			if (Ptr->next == NULL) {
				cout << "Cannot find this person!" << endl;
				goto point;
			}
			else {
				Ptr = Ptr->next;
			}
		}
		cout << name << " likes drink " << Ptr->drink << endl;
	point:;
	}
}

void hashTable::RemoveItem(string name) {
	int index = Hash(name);

	item* delPtr;
	item* P1;
	item* P2;

	//case 0: bucket is empty
	if (HashTable[index]->name == "empty" && HashTable[index]->drink == "empty") {
		cout << name << " was not found!" << endl;
	}
	//case 1: only 1 item contained in this bucket and this one will be removed
	else if (HashTable[index]->name == name && HashTable[index]->next == NULL) {
		HashTable[index]->name == "empty";
		HashTable[index]->drink == "empty";
	}
	//case 2: there are more than 1 item in this bucket and remove first one
	else if (HashTable[index]->name == name && HashTable[index]->next != NULL) {
		delPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delPtr;

		cout << name << " has removed from Hash Table!" << endl;
	}
	//case 3: there are more than 1 item contained in this bucket, but first one not match
	else {

		P1 = HashTable[index]->next;
		P2 = HashTable[index];

		while (P1->name != name && P1 != NULL) {
			P2 = P1;
			P1 = P1->next;
		}
		if (P1->name == name) {
			delPtr = P1;
			P2->next = P1->next;
			P1 = P1->next;
			delete delPtr;
			cout << name << " has removed from Hash Table!" << endl;
		}
		else if (P1 == NULL) {
			cout << name << " was not found in this Hash Table!" << endl;
		}
	}

}

void hashTable::PrintTable() {
	int number;
	for (int i = 0; i < tableSize; i++) {
		number = NumberOfItemsInIndex(i);
		cout << "----------------------------------" << endl;
		cout << "index = " << i << endl;
		cout << HashTable[i]->name << "  " << HashTable[i]->drink << endl;
		cout << "number of items = " << number << endl;
		cout << "----------------------------------" << endl;
	}

}

void hashTable::PrintItemsInIndex(int index) {

	item* Ptr = HashTable[index];

	cout << "----------------------------------" << endl;
	if (Ptr->name == "epty") {
		cout << "index " << index << " is empty!" << endl;
	}
	else {
		cout << "index " << index << " contains the following items:" << endl;

		while (Ptr != NULL) {
			cout << Ptr->name << " likes drink " << Ptr->drink << endl;
			Ptr = Ptr->next;
		}
	}
	cout << "----------------------------------" << endl;
}





