#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Note: When we delete the element, the iterator i should minus 1 to point original next element.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) == val) {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};

int main() {

    int myarray[] = {1, 1, 2, 4};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int) );

    Solution A;
    cout << A.removeElement(foo, 1);

    return 0;
}
