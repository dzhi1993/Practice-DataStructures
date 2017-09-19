#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 62. Unique Paths
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// How many possible unique paths are there? Note: m and n will be at most 100

class Solution {
public:
    int uniquePaths(int m, int n) {// The unique paths should be Combinations(total, k)
        // total represents the total movements in order to reach the end point
        // k represents either the total right movements or the total down movements
        int k, total = m + n - 2;
        m >= n ? k = n - 1 : k = m - 1;
        double res = 1;

        for (int i = 1; i <= k; ++i) {
            res *= total - i + 1;
            res /= i;
        }
        return res;
    }
};

int main()
{
    // For example, given array A = [ 1, 2], B = [-2,-1], C = [-1, 2], D = [ 0, 2]

    //int myarray[] = {2,5,0,0};
 	//vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));

//    int i = 0;
//    vector<vector<int>> original(3, std::vector<int>(3));
//    for (unsigned int x = 0; x < 3; x++) {
//        original[x].resize(3);
//        for (unsigned int y = 0; y < 3; y++) {
//            original[x][y] = ++i;
//        }
//    }

    Solution A;
    cout << A.uniquePaths(3,7) << endl;
    //vector<vector<int>> a = A.generateMatrix(5);
    //vector<int> print = A.spiralOrder(original);

//    for (vector<int>::const_iterator i = print.begin(); i != print.end(); ++i)
//        std::cout << *i << endl;

//    for (unsigned int k = 0; k < a.size(); k++) {
//        for (unsigned int x = 0; x < a[k].size(); x++) {
//            cout << a[k][x] << " ";
//        }
//        cout << endl;
//    }

    return 0;
}
