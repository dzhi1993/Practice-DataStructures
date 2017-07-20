#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// 561. Array Partition I
// Given an array of 2n integers, your task is to group these integers into n pairs of integer,
// say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int res = 0;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                res += nums[i];
            }
        }
        return res;
    }
};

int main()
{
    //Input: [1, 2, 3, 4, 5], k = 1       output = 4
    //Input: [3, 1, 4, 1, 5], k = 2       output = 2
    //Input: [1, 3, 1, 5, 4], k = 0       output = 1
    int myarray[] = {1, 2, 3, 4, 5};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
	//vector<vector <int> > foo(3, vector<int>(2, 1) );
	//reverse(foo.begin(), foo.end());

    Solution A;
    //vector<int> print = A.findDisappearedNumbers(foo);
    //int res = A.maxProfit(foo);
    cout << A.arrayPairSum(foo);


    //for (set<int>::const_iterator i = print.begin(); i != print.end(); ++i)
      //  std::cout << *i << ' ';

//    for (unsigned int k = 0; k < print.size(); k++) {
//        for (unsigned int x = 0; x < print[k].size(); x++) {
//            cout << print[k][x] << " ";
//        }
//        cout << endl;
//    }

    return 0;
}
