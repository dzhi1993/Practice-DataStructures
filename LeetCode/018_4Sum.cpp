#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 18. 4Sum
// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
// Find all unique quadruplets in the array which gives the sum of target.

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if (nums.empty()) return res;
        std::sort(nums.begin(), nums.end());

        for (unsigned int i = 0; i < nums.size(); ++i) {
            int targetof3 = target - nums[i];
            for (unsigned int j = i+1; j < nums.size(); ++j) {
                int targetof2 = targetof3 - nums[j];
                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    int sumof2 = nums[left] + nums[right];
                    if (sumof2 < targetof2) left++;
                    else if (sumof2 > targetof2) right--;
                    else { // sumof2 == targetof2, which means the result has been found.
                        vector<int> curr(4, 0);
                        curr[0] = nums[i];
                        curr[1] = nums[j];
                        curr[2] = nums[left];
                        curr[3] = nums[right];
                        res.push_back(curr);

                        while(left < right && nums[left] == curr[2]) left++;// eliminating the duplicates of left numbers
                        while(left < right && nums[right] == curr[3]) right--;// elimination the duplicates of right numbers
                    }
                }
                while (j+1 < nums.size() && nums[j+1] == nums[j]) j++; // eliminating the duplicates of the second number
            }
            while (i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
};

int main()
{
    // For example, given array S = [-1, 0, 1, 2, -1, -4],
    // Output: [[-1, 0, 1], [-1, -1, 2]]

    int myarray[] = {1, 0, -1, 0, -2, 2};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
	//vector<vector <int> > foo(3, vector<int>(2, 1) );
	//reverse(foo.begin(), foo.end());

    Solution A;
    //cout << A.fourSum(foo, 0);
    vector<vector<int> > print = A.fourSum(foo, 0);

    //vector<int> print = A.findDisappearedNumbers(foo);
    //int res = A.maxProfit(foo);

    //for (vector<int>::const_iterator i = a.begin(); i != a.end(); ++i)
      //  std::cout << *i << endl;

    for (unsigned int k = 0; k < print.size(); k++) {
        for (unsigned int x = 0; x < print[k].size(); x++) {
            cout << print[k][x] << " ";
        }
        cout << endl;
    }

    return 0;
}
