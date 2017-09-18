#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 54. Spiral Matrix
// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
// For example, Given the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        int counter = 0, up = 0, down = m - 1, left = 0, right = n - 1;
        vector<int> res (m * n);

        while (true) {
            // up line
            for (int column = left; column <= right; ++column) {
                res[counter] = matrix[up][column];
                counter++;
            }
            ++up;
            if (up > down) break;
            // right line
            for (int row = up; row <= down; ++row) {
                res[counter] = matrix[row][right];
                counter++;
            }
            --right;
            if (right < left) break;
            // bottom line
            for (int column = right; column >= left; --column) {
                res[counter] = matrix[down][column];
                counter++;
            }
            --down;
            if (down < up) break;
            // left line
            for (int row = down; row >= up; --row) {
                res[counter] = matrix[row][left];
                counter++;
            }
            ++left;
            if (left > right) break;
        }
        return res;
    }
};

int main()
{
    // For example, given array A = [ 1, 2], B = [-2,-1], C = [-1, 2], D = [ 0, 2]

//    int myarray[] = {10, 1, 2, 7, 6, 1, 5};
//	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));

    int i = 0;
    vector<vector<int>> original(3, std::vector<int>(3));
    for (unsigned int x = 0; x < 3; x++) {
        original[x].resize(3);
        for (unsigned int y = 0; y < 3; y++) {
            original[x][y] = ++i;
        }
    }

    Solution A;
    vector<int> print = A.spiralOrder(original);

    for (vector<int>::const_iterator i = print.begin(); i != print.end(); ++i)
        std::cout << *i << endl;

//    for (unsigned int k = 0; k < original.size(); k++) {
//        for (unsigned int x = 0; x < original[k].size(); x++) {
//            cout << original[k][x] << " ";
//        }
//        cout << endl;
//    }

    return 0;
}
