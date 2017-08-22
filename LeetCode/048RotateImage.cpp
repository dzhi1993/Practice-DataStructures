#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map> // or <map>

using namespace std;

// 48. Rotate Image
// You are given an n x n 2D matrix representing an image. Rotate the image by 90 degrees (clockwise).
// Follow up: Could you do this in-place?

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (unsigned int i = 0; i < n; ++i) {
            for (unsigned int j = 0; j < i; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (unsigned int k = 0; k < n; ++k) {
            std::reverse(matrix[k].begin(), matrix[k].end());
        }
    }
};

int main()
{
    // For example, given array A = [ 1, 2], B = [-2,-1], C = [-1, 2], D = [ 0, 2]

    //int myarray[] = {10, 1, 2, 7, 6, 1, 5};
	//vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));

    vector<vector<int>> original(10, std::vector<int>(10));
    for (unsigned int x = 0; x < 10; x++) {
        original[x].resize(10);
        for (unsigned int y = 0; y < 10; y++) {
            original[x][y] = rand() % 20 + 1;
        }
    }

    for (unsigned int k = 0; k < original.size(); k++) {
        for (unsigned int x = 0; x < original[k].size(); x++) {
            cout << original[k][x] << " ";
        }
        cout << endl;
    }
    cout << endl;

    Solution A;
    A.rotate(original);
    //vector<vector<int>> print = A.combinationSum2(foo, 8);

    //vector<int> print = A.findDisappearedNumbers(foo);
    //int res = A.maxProfit(foo);

    //for (vector<int>::const_iterator i = a.begin(); i != a.end(); ++i)
      //  std::cout << *i << endl;

    for (unsigned int k = 0; k < original.size(); k++) {
        for (unsigned int x = 0; x < original[k].size(); x++) {
            cout << original[k][x] << " ";
        }
        cout << endl;
    }

    return 0;
}
