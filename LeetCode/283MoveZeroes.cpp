#include <iostream>
#include <vector>

using namespace std;

// No.283 Move Zeroes
// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
// Note:You must do this in-place without making a copy of the array. Minimize the total number of operations.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int SumofZero = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == 0) {
                //nums[i] = nums[i+1];
                nums.erase(nums.begin() + i);
                --i;
                SumofZero++;
            }
        }
        while(SumofZero--){
            nums.push_back(0);
        }
    }
};

int main() {

    int myArray1[] = {0,1,1,0,0,4,5,8,0,7,0,433,0};
    int myArray2[] = {2,3,4,5,9};
    vector<int> A (myArray1, myArray1 + sizeof(myArray1) / sizeof(int) );
    vector<int> B (myArray2, myArray2 + sizeof(myArray2) / sizeof(int) );

    Solution a;
    a.moveZeroes(A);
    //vector<int> res = a.plusOne(foo);
    for (std::vector<int>::const_iterator i = A.begin(); i != A.end(); ++i)
        std::cout << *i << ' ';

    //cout << a.missingNumber(A) << endl;

    return 0;
}