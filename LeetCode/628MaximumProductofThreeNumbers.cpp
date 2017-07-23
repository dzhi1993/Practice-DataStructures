#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// 628. Maximum Product of Three Numbers
// Given an integer array, find three numbers whose product is maximum and output the maximum product.

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int max1 = nums[0] * nums[1] * nums[nums.size()-1];
        int max2 = nums[nums.size()-1] *nums[nums.size()-2] * nums[nums.size()-3];
        if (max1 > max2) return max1;
        else return max2;
    }
};

int main()
{
    //Input: [1, 2, 3, 4, 5], k = 1       output = 4
    //Input: [3, 1, 4, 1, 5], k = 2       output = 2
    //Input: [1, 3, 1, 5, 4], k = 0       output = 1
    int myarray[] = {-4,-3,-2,-1,60};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
	//vector<vector <int> > foo(3, vector<int>(2, 1) );
	//reverse(foo.begin(), foo.end());
    Solution A;
    cout << A.maximumProduct(foo);
    //vector<int> print = A.findDisappearedNumbers(foo);
    //int res = A.maxProfit(foo);

    //for (vector<string>::const_iterator i = tokens.begin(); i != tokens.end(); ++i)
      //  std::cout << *i << endl;

//    for (unsigned int k = 0; k < print.size(); k++) {
//        for (unsigned int x = 0; x < print[k].size(); x++) {
//            cout << print[k][x] << " ";
//        }
//        cout << endl;
//    }

    return 0;
}
