#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


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

    nodePtr getHead(){
        return head;
    }

    List() {
        head = NULL;
        curr = NULL;
        temp = NULL;
    }

	void AddNode(int addData) {
        nodePtr n = new node;
        n->next = NULL;
        n->data = addData;

        if (head != NULL) {
            curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = n;
        }
        else {
            head = n;
        }
    }

	void PrintList() {
        curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

};

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}*nodePtr;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* res = nullptr; // return
        ListNode* pre = nullptr; // previous pointer
        int carry = 0;

        if ( ptr1 == nullptr && ptr2 == nullptr ) {// If two linked list are both empty
            return nullptr;
        }
        else
        {
            while ( ptr1 != nullptr && ptr2 != nullptr ) {// If two linked list are both non-empty and equal length
                ListNode* temp = new ListNode(0);
                temp->val = ptr1->val + ptr2->val + carry;
                carry = temp->val / 10;
                temp->val = temp->val % 10;

                if (res != nullptr) { // return linked list is non-empty
                    pre->next = temp;
                    pre = temp;
                }
                else { // return linked list is empty
                    temp->next = nullptr;
                    pre = temp;
                    res = temp;
                }

                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }

            while ( ptr1 != nullptr && ptr2 == nullptr ) {// If the length of first linked list > second one
                ListNode* temp = new ListNode(0);
                temp->val = ptr1->val + carry;
                carry = temp->val / 10;
                temp->val = temp->val % 10;

                if (res != nullptr) {
                    pre->next = temp;
                    pre = temp;
                }
                else {
                    temp->next = nullptr;
                    pre = temp;
                    res = temp;
                }
                ptr1 = ptr1->next;
            }

            while ( ptr1 == nullptr && ptr2 != nullptr ) {// If the length of first linked list < second one
                ListNode* temp = new ListNode(0);
                temp->val = ptr2->val + carry;
                carry = temp->val / 10;
                temp->val = temp->val % 10;

                if (res != nullptr) {
                    pre->next = temp;
                    pre = temp;
                }
                else {
                    temp->next = nullptr;
                    pre = temp;
                    res = temp;
                }
                ptr2 = ptr2->next;
            }

            if (carry == 1) {
                ListNode* temp = new ListNode(0);
                temp->val = carry;
                temp->next = nullptr;
                pre->next = temp;
            }

            return res;
        }
    }
};


int main() {

    List l1;
    l1.AddNode(2);
    l1.AddNode(4);
    l1.AddNode(3);
    l1.PrintList();
    l1.getHead();

    List l2;
    l2.AddNode(5);
    l2.AddNode(6);
    l2.AddNode(4);
    l2.PrintList();

    Solution a;
    //ListNode* result = a.addTwoNumbers(*l1.getHead(),*l2.getHead());
    //cout << result <<endl;

    return 0;
}
