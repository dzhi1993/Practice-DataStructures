#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class anotherSolution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *cur = head;
        ListNode *pre = NULL;
        while (cur && cur->next) {
            ListNode *p = cur->next;
            cur->next = p->next;
            p->next = cur;
            if (pre) pre->next = p;
            else { head = p; }
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};

int main() {

    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    a->next = b;
    b->next = c;
    c->next = d;
    anotherSolution s;
    ListNode *p = s.swapPairs(a);
    while (p) {
        cout<<p->val<<" ";
        p = p->next;
    }

    return 0;
}
