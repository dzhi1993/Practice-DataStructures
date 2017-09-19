#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 59. Spiral Matrix II
// Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) return {};
        vector<vector<int>> matrix (n, std::vector<int>(n, 0)); //initializing a 2d vector filled with 0
        int up = 0, down = n - 1, left = 0, right = n - 1, number = 1;
        while (up <= down && left <= right) {
            // up line
            for (int column = left; column <= right; ++column) {
                matrix[up][column] = number++;
            }
            ++up;
            // right line
            for (int row = up; row <= down; ++row) {
                matrix[row][right] = number++;
            }
            --right;
            // bottom line
            for (int column = right; column >= left; --column) {
                matrix[down][column] = number++;
            }
            --down;
            // left line
            for (int row = down; row >= up; --row) {
                matrix[row][left] = number++;
            }
            ++left;
        }
        return matrix;
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
    vector<vector<int>> a = A.generateMatrix(5);
    //vector<int> print = A.spiralOrder(original);

//    for (vector<int>::const_iterator i = print.begin(); i != print.end(); ++i)
//        std::cout << *i << endl;

    for (unsigned int k = 0; k < a.size(); k++) {
        for (unsigned int x = 0; x < a[k].size(); x++) {
            cout << a[k][x] << " ";
        }
        cout << endl;
    }

    return 0;
}
