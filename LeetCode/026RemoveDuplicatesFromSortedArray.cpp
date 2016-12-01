#include <iostream>
#include <string>
#include <vector>

using namespace std;

//General idea: In this problem, the input array is sorted.
//so we just update the next number once a time when its different between previous one

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 1;
        int len = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[len] != nums[i])
            {
                nums[len + 1] = nums[i];
                len++;
            }
        }
        return len + 1;
    }
};

int main() {

    int myarray[] = {1, 1, 2, 4};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int) );

    Solution A;
    cout << A.removeDuplicates(foo);

    return 0;
}
