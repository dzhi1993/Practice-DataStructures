#include <iostream>
#include <vector>
#include <set>

using namespace std;

// No.268 Missing Number
// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
// For example, Given nums = [0, 1, 3] return 2.
//Note: Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

class anotherSolution {// Not very sure why this solution returns a Time Limit Exceeded error ?
public:
    int missingNumber(vector<int>& nums) {
        std::set<int> transferred(nums.begin(), nums.end());
        int index;
        for (std::set<int>::const_iterator i = transferred.begin(); i != transferred.end(); ++i) {
            index = (int)std::distance( transferred.begin(), i );
            if (index != *i) return index;
        }
        return *transferred.end() + 1;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int> setNum;
        for (int i = 0; i <= nums.size(); ++i)
            setNum.insert(i);
        for (int i = 0; i < nums.size(); ++i)
            setNum.erase(nums[i]);
        return *setNum.begin();
    }
};

int main() {

    int myArray1[] = {0};
    int myArray2[] = {2,3,4,5,9};
    vector<int> A (myArray1, myArray1 + sizeof(myArray1) / sizeof(int) );
    vector<int> B (myArray2, myArray2 + sizeof(myArray2) / sizeof(int) );

    Solution a;
    //a.missingNumber(A);
    //vector<int> res = a.plusOne(foo);
    //for (std::vector<int>::const_iterator i = A.begin(); i != A.end(); ++i)
      //  std::cout << *i << ' ';

    cout << a.missingNumber(A) << endl;

    return 0;
}