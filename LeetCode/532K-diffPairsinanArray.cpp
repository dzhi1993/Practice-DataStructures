#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// 532. K-diff Pairs in an Array
// Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array.
// Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0 || nums.empty()) return 0;
        //std::sort (nums.begin(), nums.end());
        set<int> pairs;

        while (!nums.empty()) {
            int curr = nums[0];
            nums.erase(nums.begin());

            if (std::find(nums.begin(), nums.end(), curr - k) != nums.end()) { // nums[i] - k is found
                pairs.insert(curr - k);
            }
            if (std::find(nums.begin(), nums.end(), curr + k) != nums.end()) { // nums[i] + k is found
                pairs.insert(curr);
            }
        }
        for (set<int>::const_iterator i = pairs.begin(); i != pairs.end(); ++i)
            std::cout << *i << ' ';

        cout << endl;
        return pairs.size();
    }
};

int main()
{
    //Input: [1, 2, 3, 4, 5], k = 1       output = 4
    //Input: [3, 1, 4, 1, 5], k = 2       output = 2
    //Input: [1, 3, 1, 5, 4], k = 0       output = 1
    int myarray[] = {1, 2, 3, 4, 5};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
	//reverse(foo.begin(), foo.end());

    Solution A;
    //vector<int> print = A.findDisappearedNumbers(foo);
    //int res = A.maxProfit(foo);
    cout << A.findPairs(foo, 2);


    //for (set<int>::const_iterator i = print.begin(); i != print.end(); ++i)
      //  std::cout << *i << ' ';

//    for (unsigned int k = 0; k < print.size(); k++) {
//        for (unsigned int x = 0; x < print[k].size(); x++) {
//            cout << print[k][x] << " ";
//        }
//        cout << endl;
//    }

    //vector<int> a(10);
    //cout << a.size() << endl;
    //A.rotate(foo, 16);
    //cout << print.size();



    return 0;
}
