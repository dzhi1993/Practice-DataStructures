#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 55. Jump Game
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position. Determine if you are able to reach the last index.
// For example: A = [2,3,1,1,4], return true.
//              A = [3,2,1,0,4], return false.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        for (int reach = 0; i < nums.size() && i <= reach; ++i)
            reach = max(i + nums[i], reach);
        return i == nums.size();
    }
};

int main()
{
    // For example, given array A = [ 1, 2], B = [-2,-1], C = [-1, 2], D = [ 0, 2]

    int myarray[] = {2,5,0,0};
 	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));

//    int i = 0;
//    vector<vector<int>> original(3, std::vector<int>(3));
//    for (unsigned int x = 0; x < 3; x++) {
//        original[x].resize(3);
//        for (unsigned int y = 0; y < 3; y++) {
//            original[x][y] = ++i;
//        }
//    }

    Solution A;
    cout << A.canJump(foo) << endl;
    //vector<int> print = A.spiralOrder(original);

//    for (vector<int>::const_iterator i = print.begin(); i != print.end(); ++i)
//        std::cout << *i << endl;

//    for (unsigned int k = 0; k < original.size(); k++) {
//        for (unsigned int x = 0; x < original[k].size(); x++) {
//            cout << original[k][x] << " ";
//        }
//        cout << endl;
//    }

    return 0;
}
