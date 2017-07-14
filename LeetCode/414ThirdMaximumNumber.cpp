#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 414. Third Maximum Number
// Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number.
// The time complexity must be in O(n).

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int, greater<int> > test (nums.begin(), nums.end());
        if (test.size() < 3) return *test.begin();
        else {
            std::set<int>::iterator it = test.begin();
            std::advance(it, 2); // Advance the iterator by 2;
            return *it;
        }
    }
};

int main() {

    int myArray1[] = {0,1,1,0,0,4,5,8,0,7,0,433,0};
    int myArray2[] = {2,3,4,5,9};
    vector<int> A (myArray1, myArray1 + sizeof(myArray1) / sizeof(int) );
    vector<int> B (myArray2, myArray2 + sizeof(myArray2) / sizeof(int) );

    Solution a;
    //vector<int> res = a.plusOne(foo);
    //set<int, greater<int> > test (A.begin(), A.end());
    //for (std::set<int>::const_iterator i = test.begin(); i != test.end(); ++i)
      //  std::cout << *i << ' ';

    cout << a.thirdMax(A) << endl;

    return 0;
}