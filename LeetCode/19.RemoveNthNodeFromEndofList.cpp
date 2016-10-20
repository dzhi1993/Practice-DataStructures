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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        if (ptr == nullptr || ptr->next == nullptr) { return nullptr;}
        else {
            ListNode* pre = nullptr;
            ListNode* curr = head;
            ListNode* next = curr->next;

            if (next->next ==nullptr) {
                delete curr;
            }
            else{
                while (next->next != nullptr) {
                    next = curr->next;
                    //curr->next = pre;
                    pre = curr;
                    curr = next;
                }
                delete curr;
                pre->next = next;
            }
        }
        return ptr;
    }
};

int main() {
    ListNode* l1 = ListNode(1);
    ListNode* l2 = ListNode(2);
    ListNode* l3 = ListNode(3);
    ListNode* l4 = ListNode(4);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    Solution A;
    ListNode* a = A.removeNthFromEnd(l1,)

}
