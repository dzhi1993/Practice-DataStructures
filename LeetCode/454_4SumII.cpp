#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map> // or <map>

using namespace std;

// 454. 4Sum II
// Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
// To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500.
// All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> Combinations;
        int counter = 0;

        for (unsigned int i = 0; i < A.size(); ++i) {
            for (unsigned int j = 0; j < B.size(); ++j) {
                int abSum = A[i] + B[j];
                if (Combinations.find(abSum) != Combinations.end()) {
                    unordered_map<int, int>::iterator iter = Combinations.find(abSum);
                    iter->second += 1;
                }
                else Combinations[abSum] = 1;
            }
        }

        for (unsigned int k = 0; k < C.size(); ++k) {
            for (unsigned int l = 0; l < D.size(); ++l) {
                int cdSum = - (C[k] + D[l]);
                if (Combinations.find(cdSum) != Combinations.end()) {
                    unordered_map<int, int>::iterator iter2 = Combinations.find(cdSum);
                    counter = counter + iter2->second;
                }
            }
        }
        return counter;
    }
};

int main()
{
    // For example, given array A = [ 1, 2], B = [-2,-1], C = [-1, 2], D = [ 0, 2]

    //int myarray[] = {1, 0, -1, 0, -2, 2};
	//vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
    int A[] = {1, 2};
    int B[] = {-2, -1};
    int C[] = {-1, 2};
    int D[] = {0, 2};
    vector<int> foo1 (A, A + sizeof(A) / sizeof(int));
    vector<int> foo2 (B, B + sizeof(B) / sizeof(int));
    vector<int> foo3 (C, C + sizeof(C) / sizeof(int));
    vector<int> foo4 (D, D + sizeof(D) / sizeof(int));

    Solution test;
    cout << test.fourSumCount(foo1, foo2, foo3, foo4);
    //vector<vector<int> > print = A.fourSum(foo, 0);

    //vector<int> print = A.findDisappearedNumbers(foo);
    //int res = A.maxProfit(foo);

    //for (vector<int>::const_iterator i = a.begin(); i != a.end(); ++i)
      //  std::cout << *i << endl;

//    for (unsigned int k = 0; k < print.size(); k++) {
//        for (unsigned int x = 0; x < print[k].size(); x++) {
//            cout << print[k][x] << " ";
//        }
//        cout << endl;
//    }

    return 0;
}
