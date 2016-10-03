#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//List() {
//    head = nullptr;
//    curr = nullptr;
//    temp = nullptr;
//};

//void AddNodes(vector<int> &nums) { //Transfer a vector of numbers into a linked list.
//    //vector<int> reversedNums =
//    for (vector<int>::size_type i = 0; i < nums.size(); i++) {
//        nodePtr n = new ListNode;
//        n->next = nullptr;
//        n->val = nums[i];
//
//        if (head != nullptr) {
//            curr = head;
//            while ( curr->next != nullptr ) {
//                curr = curr->next;
//            }
//            curr->next = n;
//        }
//        else {
//            head = n;
//        }
//    }
//};
//
//void PrintList() {
//    curr = head;
//    while ( curr != nullptr ) {
//        cout << curr->val << " ";
//        curr = curr->next;
//    }
//    cout << endl;
//};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1, ptr2 = l2;
        ListNode* res = nullptr; // return
        ListNode* pre = nullptr; // previous pointer
        int carry = 0;

        if ( ptr1 == nullptr && ptr2 == nullptr ) {// If two linked list are both empty
            return nullptr;
        }
        else {
            while ( ptr1 != nullptr && ptr2 != nullptr ) {// If two linked list are both non-empty and equal length
                ListNode* temp = new ListNode(0);
                temp->val = ptr1->val + ptr2->val + carry;
                carry = temp->val / 10;
                temp->val = temp->val % 10;

                if (res != nullptr){ // return linked list is non-empty
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

            if (carry == 1 && ) {

            }

            while ( ptr1 != nullptr && ptr2 == nullptr ) {// If the length of first linked list > second one
                ListNode* temp = new ListNode(0);
                temp->val = ptr1->val + carry;
                carry = temp->val / 10;
                temp->val = temp->val % 10;

            }

        }

    }


};


int main() {

    int myarray1[] = {1, 3, 5, 7, 9};
	vector<int> nums1 (myarray1, myarray1 + sizeof(myarray1) / sizeof(int) );
	int myarray2[] = {2, 4, 6, 8, 0};
	vector<int> nums2 (myarray2, myarray2 + sizeof(myarray2) / sizeof(int) );

    List l1, l2;
    l1.AddNodes(nums1);
    l2.AddNodes(nums2);
    l1.PrintList();
    l2.PrintList();

    return 0;
}
