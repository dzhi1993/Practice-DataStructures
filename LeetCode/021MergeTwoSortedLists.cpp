#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        else if (l2 == nullptr) return l1;
        else {

            ListNode* ptr1 = l1;
            ListNode* ptr2 = l2;

            ListNode* head = new ListNode(0);
            ListNode* curr = head;

            while (ptr1 != nullptr && ptr2 != nullptr) {
                if (ptr1->val < ptr2->val) {
                    curr->next = ptr1;
                    ptr1 = ptr1->next;
                    curr =curr->next;
                }
                else {
                    curr->next = ptr2;
                    ptr2 = ptr2->next;
                    curr =curr->next;
                }
            }

            if (ptr1 == nullptr) { curr->next = ptr2; }
            else { curr->next = ptr1; }

            ListNode* res = head->next;
            delete head;
            return res;
        }
    }
};

int main()
{
    ListNode* l1 = ListNode(1);
    ListNode* l2 = ListNode(3);
    ListNode* l3 = ListNode(5);
    ListNode* l4 = ListNode(7);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    ListNode* r1 = ListNode(2);
    ListNode* r2 = ListNode(4);
    ListNode* r3 = ListNode(6);
    ListNode* r4 = ListNode(8);
    r1->next = r2;
    r2->next = r3;
    r3->next = r4;

    Solution A;
    ListNode* result = A.mergeTwoLists(l1,r1);
    ListNode* curr = result;

	while (curr != nullptr) {
		cout << curr->val << " ";
		curr = curr->next;
	}
	cout << endl;
    return 0;
}
