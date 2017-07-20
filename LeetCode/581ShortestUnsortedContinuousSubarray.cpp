#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// 581. Shortest Unsorted Continuous Subarray
// Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
// You need to find the shortest such subarray and output its length.

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        vector<int> sorted(nums);
        std::sort(sorted.begin(), sorted.end());

        int start = 0;
        int endwith = nums.size() - 1;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            if (nums[i] != sorted[i]) {
                start = i;
                break;
            }
        }
        //if (start == 0) return 0;
        while (endwith >= 0 && nums[endwith] == sorted[endwith]) {
            endwith--;
        }

        if (endwith == start) return 0;
        else return endwith - start + 1;
    }
};

int main()
{
    //Input: [1, 2, 3, 4, 5], k = 1       output = 4
    //Input: [3, 1, 4, 1, 5], k = 2       output = 2
    //Input: [1, 3, 1, 5, 4], k = 0       output = 1
    int myarray[] = {2, 1};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
	//vector<vector <int> > foo(3, vector<int>(2, 1) );
	//reverse(foo.begin(), foo.end());
    Solution A;
    //vector<int> print = A.findDisappearedNumbers(foo);
    //int res = A.maxProfit(foo);
    cout << A.findUnsortedSubarray(foo);


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
