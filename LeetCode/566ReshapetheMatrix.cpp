#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// 566. Reshape the Matrix
// In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.
// You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.
// The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.
// If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

class Solution {
public:
    vector< vector<int> > matrixReshape(vector< vector<int> >& nums, int r, int c) {
        int originalrow = nums.size();
        int originalcolumn = nums[0].size();
        if (r * c != originalcolumn * originalrow) return nums;

        //vector<int> allElements;
        vector< vector<int> > res( r, vector<int>(c) );// initialize new matrix's size
        for (unsigned int i = 0; i < originalcolumn * originalrow; ++i) {
            res[i/c][i%c] = nums[i/originalcolumn][i%originalcolumn];
        }
        return res;
    }
};

int main()
{
    //Input: [1, 2, 3, 4, 5], k = 1       output = 4
    //Input: [3, 1, 4, 1, 5], k = 2       output = 2
    //Input: [1, 3, 1, 5, 4], k = 0       output = 1
    //int myarray[] = {1, 2, 3, 4, 5};
	//vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
	vector<vector <int> > foo(3, vector<int>(2, 1) );
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
