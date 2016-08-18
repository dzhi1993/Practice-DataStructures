/*
*File: BiTree.h
*Author: Da Zhi
*
*Created on April 21, 2016.
*/

#include <iostream>
#include <cstdlib>
#include "BST.h"

#define NULL nullptr

using namespace std;

BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	RemoveSubtree(root);
}

void BST::RemoveSubtree(node* Ptr)
{
	if(Ptr != NULL)
	{
		if(Ptr->left != NULL)
		{
			RemoveSubtree(Ptr->left);
		}
		if(Ptr->right != NULL)
		{
			RemoveSubtree(Ptr->right);
		}
		cout << "Deleting the node containing value "<<Ptr->value << endl;
		delete Ptr;
	}
}

BST::node* BST::CreateLeaf(int value)
{
	node* n = new node;
	n->value = value;
	n->left = NULL;
	n->right = NULL;

	return n;
}

BST::node* BST::ReturnNode(int value)
{
	return ReturnNodePrivate(value, root);
}

BST::node* BST::ReturnNodePrivate(int value, node* Ptr)
{
	if(Ptr != NULL)
	{
		if(Ptr->value == value)
		{
			return Ptr;
		}
		else
		{
			if(value < Ptr->value)
			{
				return ReturnNodePrivate(value, Ptr->left);
			}
			else
			{
				return ReturnNodePrivate(value, Ptr->right);
			}
		}
	}
	else
	{
		return NULL;
	}
}


void BST::AddLeaf(int value)
{
	AddLeafPrivate(value, root);
}

void BST::AddLeafPrivate(int value, node* Ptr)
{
	if (root == NULL)
	{
		root = CreateLeaf(value);
	}
	else if (value < Ptr->value)
	{
		if (Ptr->left != NULL)
		{
			AddLeafPrivate(value, Ptr->left);
		}
		else
		{
			Ptr->left = CreateLeaf(value);
		}
	}
	else if (value > Ptr->value)
	{
		if (Ptr->right != NULL)
		{
			AddLeafPrivate(value, Ptr->right);
		}
		else
		{
			Ptr->right = CreateLeaf(value);
		}
	}
	else //value = Ptr->value
	{
		cout << "The value " << value << " has already been added to the tree" << endl;
	}
}

void BST::printInOrder()
{
	printInOrderPrivate(root);
	cout << endl;
}

void BST::printInOrderPrivate(node* Ptr)
{
	if (root != NULL)
	{
		if (Ptr->left != NULL)
		{
			printInOrderPrivate(Ptr->left);
		}
		cout << Ptr->value << " ";
		if (Ptr->right != NULL)
		{
			printInOrderPrivate(Ptr->right);
		}
	}
	else
	{
		cout << "The tree is empty!" << endl;
	}
}

int BST::ReturnRootValue()
{
	if(root != NULL)
	{
		return root->value;
	}
	else
	{
		return -1;
	}
}

void BST::PrintChildren(int value)
{
	node* Ptr = ReturnNode(value);

	if(Ptr != NULL)
	{
		cout << "Parent Node = " << Ptr->value << endl;

		Ptr->left == NULL ?
			cout << "Left Child = NULL" << endl :
			cout << "Left Child = " << Ptr->left->value << endl;

		Ptr->right == NULL ?
			cout << "Right Child = NULL" << endl :
			cout << "Right Child = " << Ptr->right->value << endl;
	}
	else
	{
		cout << "Value " << value << " is not in the tree." << endl;
	}
}

int BST::FindSmallest()
{
	return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node* Ptr)
{
	if(root == NULL)
	{
		cout << "The tree is empty" << endl;
		return -1;
	}
	else
	{
		if(Ptr->left != NULL)
		{
			return FindSmallestPrivate(Ptr->left);
		}
		else
		{
			return Ptr->value;
		}
	}
}

void BST::RemoveNode(int value)
{
	RemoveNodePrivate(value, root);
}

void BST::RemoveNodePrivate(int value, node* parent)
{
	if(root != NULL)
	{
		if(root->value == value)
		{
			RemoveRootMatch();
		}
		else
		{
			if(value < parent->value && parent->left != NULL)
			{
				parent->left->value == value ?
					RemoveMatch(parent, parent->left, true) :
					RemoveNodePrivate(value, parent->left);
			}
			else if (value > parent->value && parent->right != NULL)
			{
				parent->right->value == value ?
					RemoveMatch(parent, parent->right, false) :
					RemoveNodePrivate(value, parent->right);
			}
			else
			{
				cout << "The value " << value << " was not found in the tree" << endl;
			}
		}
	}
	else
	{
		cout << "The tree is empty" << endl;
	}
}

void BST::RemoveRootMatch()
{
	if(root != NULL)
	{
		node* delPtr = root;
		int rootvalue = root->value;
		int smallestInRightSubtree;

		//Case 0: 0 Child
		if(root->left == NULL && root->right ==NULL)
		{
			root = NULL;
			delete delPtr;
		}

		//Case 1: 1 child
		else if(root->left == NULL && root->right != NULL)
		{
			root = root->right;
			delPtr->right = NULL;
			delete delPtr;
			cout << "The root node with value" << rootvalue << " was deleted." 
				 << "The new root contains value " << root->value << endl;
		}
		else if (root->left != NULL && root->right == NULL)
		{
			root = root->left;
			delPtr->left = NULL;
			delete delPtr;
			cout << "The root node with value" << rootvalue << " was deleted."
				<< "The new root contains value " << root->value << endl;
		}

		//Case 2: 2 Children
		else
		{
			smallestInRightSubtree = FindSmallestPrivate(root->right);
			RemoveNodePrivate(smallestInRightSubtree, root);
			root->value = smallestInRightSubtree;
			cout << "The root value containing value " << rootvalue
				 << " was overwritten with value" << root->value << endl;
		}

	}
	else
	{
		cout << "Cannot remove root. The tree is empty" << endl;
	}
}

void BST::RemoveMatch(node* parent, node* match, bool left)
{
	if(root != NULL)
	{
		node* delPtr;
		int matchvalue = match->value;
		int smallestInRightSubtree;

		//case 0: 0 children
		if (match->left == NULL && match->right == NULL)
		{
			delPtr = match;
			left = true ? parent->left = NULL : parent->right = NULL;
			delete delPtr;
			cout << "The node containing value " << matchvalue << " was removed" << endl;
		}

		//case 1: 1 child
		else if(match->left ==  NULL && match->right != NULL)
		{
			left = true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;
			delPtr = match;
			delete delPtr;
			cout << "The node containing value " << matchvalue << " was removed." << endl;
		}
		else if (match->left != NULL && match->right == NULL)
		{
			left = true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
			delPtr = match;
			delete delPtr;
			cout << "The node containing value " << matchvalue << " was removed." << endl;
		}

		//case 2: 2 children
		else
		{
			smallestInRightSubtree = FindSmallestPrivate(match->right);
			RemoveNodePrivate(smallestInRightSubtree, match);
			match->value = smallestInRightSubtree;
		}
	}
	else
	{
		cout << "Cannot remove match. The tree is empty!" << endl;
	}
}
