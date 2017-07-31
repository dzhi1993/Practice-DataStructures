#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 15. 3Sum
// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
// Note: The solution set must not contain duplicate triplets.

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        std::sort(nums.begin(), nums.end());

        for (unsigned int i = 0; i < nums.size(); ++i) {

            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum < target) left++;
                else if (sum > target) right--;
                else {
                    vector<int> curr(3, 0);
                    curr[0] = nums[i];
                    curr[1] = nums[left];
                    curr[2] = nums[right];
                    res.push_back(curr);

                    while (left < right && nums[left] == curr[1]) left++;
                    //while (left < right && nums[right] == curr[2]) right--;
                    //left++;
                    //right--;
                }
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
};

int main()
{
    // For example, given array S = [-1, 0, 1, 2, -1, -4],
    // Output: [[-1, 0, 1], [-1, -1, 2]]

    int myarray[] = {-1,0,1,2,-1,-4};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
	//vector<vector <int> > foo(3, vector<int>(2, 1) );
	//reverse(foo.begin(), foo.end());

    Solution A;
    vector<vector<int> > print = A.threeSum(foo);

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
