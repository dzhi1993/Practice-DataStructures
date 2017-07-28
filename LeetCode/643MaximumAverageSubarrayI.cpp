#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 643. Maximum Average Subarray I
// Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.
// Note: the double type value cannot show the behind point value, for example: double a = 3 / 4, returns 0, but not 0.75, unless double a = 3 * 1.0 /4.

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxSum = 0;
        for (unsigned int i = 0; i < k; ++i) {
            maxSum += nums[i];
        }
        double current = maxSum;
        for (unsigned int j = k; j < nums.size(); ++j) {
            current += nums[j] - nums[j-k];
            if (current > maxSum) {
                maxSum = current;
            }
        }
        return maxSum / 1.0 / k;
    }
};

int main()
{
    //Input: [1, 2, 3, 4, 5], k = 1       output = 4
    //Input: [3, 1, 4, 1, 5], k = 2       output = 2
    //Input: [1, 3, 1, 5, 4], k = 0       output = 1
    int myarray[] = {0,4,0,3,2};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
	//vector<vector <int> > foo(3, vector<int>(2, 1) );
	//reverse(foo.begin(), foo.end());
    Solution A;
    cout << A.findMaxAverage(foo, 1);
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
