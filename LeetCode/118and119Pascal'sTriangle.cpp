#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// This two solutions are solving Problem No. 118 and No. 119, respectively.
// The main idea is about to generate the pascal's triangle, the key formula is res[i][j] = res[i-1][j-1] + res[i-1][j];

class Solution { // No. 118
public:
    vector< vector<int> > generate(int numRows) {
        vector< vector<int> > res(numRows);
        //vector<int> singleRow;
        for (int i = 0; i < numRows; i++) {
            res.resize(i + 1);
            res[i][0] = res[i][i] = 1;
            //singleRow[0] = singleRow[i] = 1;
            for (int j = 1; j < i; j++) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }

        }

        return res;
    }
};

class anotherSolution { // No.119
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex + 1;
        vector< vector<int> > r(n);

        for (int i = 0; i < n; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }

        return r[rowIndex];
    }
};

int main()
{

    //int myarray[] = {1};
	//vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int) );
	//reverse(foo.begin(), foo.end());
    cout << "Hello" << endl;
    anotherSolution A;
    vector<int> print = A.getRow(3);

//    for (unsigned int k = 0; k < print.size(); k++) {
//        for (unsigned int x = 0; x < print[k].size(); x++) {
//            cout << print[k][x] << " ";
//        }
//        cout << endl;
//    }

    //vector<int> a(10);
    //cout << a.size() << endl;
    for (vector<int>::const_iterator i = print.begin(); i != print.end(); ++i)
    std::cout << *i << ' ';

    return 0;
}
