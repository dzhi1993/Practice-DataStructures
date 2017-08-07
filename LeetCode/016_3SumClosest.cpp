#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> // for function accumulate(first, last, INT), accumulating the values from first to last and integer vaule INT

using namespace std;

// 16. 3Sum Closest
// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
// Return the sum of the three integers. You may assume that each input would have exactly one solution.

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() <= 3) return accumulate(nums.begin(), nums.end(), 0);

        std::sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];

        for (unsigned int i = 0; i < nums.size() - 2; ++i) {

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(target - res) > abs(target - sum)) {
                    res = sum;
                    if (res == target) return res;
                }
                //if (sum > target) right--;
                //else if (sum <= target) left++;
                (sum > target) ? right-- : left++;

            }
            //while(i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
};

int main()
{
    // For example, given array S = [-1, 0, 1, 2, -1, -4],
    // Output: [[-1, 0, 1], [-1, -1, 2]]

    int myarray[] = {-1, 2, 1, -4};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
	//vector<vector <int> > foo(3, vector<int>(2, 1) );
	//reverse(foo.begin(), foo.end());

    Solution A;
    cout << A.threeSumClosest(foo, 1);
    //vector<vector<int> > print = A.threeSum(foo);

    //vector<int> print = A.findDisappearedNumbers(foo);
    //int res = A.maxProfit(foo);

    //for (vector<int>::const_iterator i = a.begin(); i != a.end(); ++i)
      //  std::cout << *i << endl;

//    for (unsigned int k = 0; k < print.size(); k++) {
//        for (unsigned int x = 0; x < print[k].size(); x++) {
//            cout << print[k][x] << " ";
//        }
//        cout << endl;
//    }

    return 0;
}
