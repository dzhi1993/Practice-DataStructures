#include <iostream>
#include <cstdlib>
#include <string>

#include "BST.h"
#include "Graph.h"
#include "hashTable.h"

using namespace std;

int main() {

	//----------------------------------HashTable----------------------------------
	string name = "";
	hashTable Hash1;
	//Hash1.PrintTable();
	Hash1.AddItem("Paul","Locha");
	Hash1.AddItem("Kim","Iced Mocha");
	Hash1.AddItem("Emma","Strawberry Smoothy");
	Hash1.AddItem("Annie","Hot Chocolate");
	Hash1.AddItem("Sarah","Passion Tea");
	Hash1.AddItem("Pepper","Caramel Mocha");
	Hash1.AddItem("Mike","Chai Tea");
	Hash1.AddItem("Steve","Apple cider");
	Hash1.AddItem("Bill","Root Beer");
	Hash1.AddItem("Marie","Skinny Latte");
	Hash1.AddItem("Susan","Water");
	Hash1.AddItem("Joe","Green Tea");
	Hash1.AddItem("Teddy","Banana juice");
	Hash1.AddItem("Charlotte","Vanilla Latte");

	Hash1.PrintTable();
	//for (int i = 0;i < Hash1.getTableSize(); i++)
	//Hash1.PrintItemsInIndex(4);
	while(name != "exit"){//Search a person
	cout<<"Search for ";
	cin>>name;
	if(name != "exit"){
	Hash1.FindDrink(name);
	}
	else{
	break;
	}
	}
	Hash1.RemoveItem("Teddy");
	Hash1.PrintTable();
	//----------------------------------HashTable----------------------------------

	/*//----------------------------------LinkedList----------------------------------
	List list1;
	list1.AddNode(2);
	list1.AddNode(4);
	list1.AddNode(6);
	list1.PrintList();
	list1.ReverseList();
	//list1.PrintList();
	//list1.DeleteNode(4);
	list1.PrintList();

	//----------------------------------LinkedList----------------------------------*/

	/*----------------------------------Stack----------------------------------
	Stack stack1;

	stack1.Push("Paul",3);
	stack1.Push("Kim",5);
	stack1.Push("Emma",7);
	stack1.Push("Annie",1);
	stack1.Push("Sarah",8);
	stack1.Push("Pepper",0);
	stack1.Push("Mike",2);
	stack1.Push("Steve",4);
	stack1.Push("Bill",9);
	stack1.Print();

	cout<<"Poping"<<endl;
	stack1.Pop();
	cout<<"Poping"<<endl;
	stack1.Pop();
	cout<<"Poping"<<endl;
	stack1.Pop();

	stack1.Print();

	----------------------------------Stack----------------------------------*/

	/*----------------------------------Queue----------------------------------
	Queue queue1;
	queue1.InQueue(1);
	queue1.InQueue(2);
	queue1.InQueue(3);
	queue1.InQueue(4);
	queue1.Print();
	queue1.OutQueue();
	queue1.OutQueue();
	queue1.Print();

	----------------------------------Queue----------------------------------*/

	/*------------------------------binary search tree-------------------------------
	int input = 0;
	int TreeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80 };
	BST myTree;

	cout << "Printing the tree in order\nBefore adding numbers\n";
	myTree.printInOrder();

	for (int i = 0; i < 16; i++)
	{
		myTree.AddLeaf(TreeKeys[i]);
	}

	cout << "Printing the tree in order\nAfter adding numbers\n";
	myTree.printInOrder();

	cout << "-------------------------------------" << endl;

	//myTree.PrintChildren(myTree.ReturnRootValue());
	//for (int i = 0; i < 16; i++)
	//{
	//	myTree.PrintChildren(TreeKeys[i]);
	//	cout << endl;
	//}

	cout << "The smallest value in the tree is " << myTree.FindSmallest() << endl;
	
	cout << "Enter a value to delete. Enter -1 to exit the process" << endl;
	while(input != -1)
	{
		cout << "Delete Node: ";
		cin >> input;
		{
			if(input != -1)
			{
				cout << endl;
				myTree.RemoveNode(input);
				myTree.printInOrder();
				cout << endl;
			}
			else
			{
				myTree.~BST();
			}
		}
	}
	------------------------------binary search tree-------------------------------*/

	/*-------------------------------------graph----------------------------------//
	Graph g;
	char tempname[256];
	char * sendclass;
	char * preclass;
	bool quit = false;
	int answer = 0;

	while (quit != true)
	{
		cout << "1) Adding class\n"
			<< "2) Adding prerequisite class\n"
			<< "3) Removing class\n"
			<< "4) Removing prerequisite class\n"
			<< "5) Display Graph\n"
			<< "6) Quit\n";
		cin >> answer;
		cin.ignore();
		switch (answer)
		{
		case 1:
			cout << "What is the class?\n";
			cin.get(tempname, 256, '\n');
			cin.ignore();
			sendclass = new char[strlen(tempname) + 1];
			strcpy(sendclass, tempname);
			if (g.AddVert(sendclass) == 1)
				cout << "You have successfully added that class\n";
			else
				cout << "We were unable to add that class\n";
			break;
		case 2:
			cout << "What is the prerequisite class?\n";
			cin.get(tempname, 256, '\n');
			cin.ignore();
			preclass = new char[strlen(tempname) + 1];
			strcpy(preclass, tempname);
			cout << "What is the class?\n";
			cin.get(tempname, 256, '\n');
			cin.ignore();
			sendclass = new char[strlen(tempname) + 1];
			strcpy(sendclass, tempname);
			if (g.AddEdge(sendclass, preclass) == 1)
				cout << "You have successfully added that prerequisite class\n";
			else
				cout << "We were unable to add that prerequisite class\n";
			break;
		case 3:
			cout << "What class you would like to remove?\n";
			cin.get(tempname, 256, '\n');
			cin.ignore();
			sendclass = new char[strlen(tempname) + 1];
			strcpy(sendclass, tempname);
			if (g.RemoveVert(sendclass) == 1)
				cout << "You have successfully removed that class\n";
			else
				cout << "We were unable to remove that class\n";
			break;
		case 4:
			cout << "What prerequisite class you would like to remove?\n";
			cin.get(tempname, 256, '\n');
			cin.ignore();
			preclass = new char[strlen(tempname) + 1];
			strcpy(preclass, tempname);
			cout << "What is the class?\n";
			cin.get(tempname, 256, '\n');
			cin.ignore();
			sendclass = new char[strlen(tempname) + 1];
			strcpy(sendclass, tempname);
			if (g.RemoveEdge(sendclass, preclass) == 1)
				cout << "You have successfully removed that prerequisite class\n";
			else
				cout << "We were unable to remove that prerequisite class\n";
			break;
		case 5:
			g.Display();
			break;
		case 6:
			quit = true;
			break;
		default:
			cout << "please enter in a valid option\n";
			break;
		}
	}
	//-------------------------------------graph----------------------------------*/

	system("pause");
	return 0;

}