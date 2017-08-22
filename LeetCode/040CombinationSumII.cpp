#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map> // or <map>

using namespace std;

// 40. Combination Sum II
// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
// Each number in C may only be used once in the combination.

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        std::sort(candidates.begin(), candidates.end());
        vector<int> local;
        findCombinations(res, 0, target, local, candidates);

        return res;
    }
    void findCombinations(vector<vector<int>>& res, const int position, const int target, vector<int>& local, const vector<int>& candidates) {
        if (target < 0) return;
        else if (target == 0) {
            res.push_back(local);
            return;
        }
        else {
            for (int i = position; i < candidates.size(); ++i) {
                if (target < candidates[i]) return;
                if (i > position && candidates[i] == candidates[i-1]) continue;
                local.push_back(candidates[i]);
                findCombinations(res, i + 1, target - candidates[i], local, candidates);
                local.pop_back();
            }
        }
    }
};

int main()
{
    // For example, given array A = [ 1, 2], B = [-2,-1], C = [-1, 2], D = [ 0, 2]

    int myarray[] = {10, 1, 2, 7, 6, 1, 5};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));

    Solution A;
    vector<vector<int>> print = A.combinationSum2(foo, 8);

    //vector<int> print = A.findDisappearedNumbers(foo);
    //int res = A.maxProfit(foo);

    //for (vector<int>::const_iterator i = a.begin(); i != a.end(); ++i)
      //  std::cout << *i << endl;

    for (unsigned int k = 0; k < print.size(); k++) {
        for (unsigned int x = 0; x < print[k].size(); x++) {
            cout << print[k][x] << " ";
        }
        cout << endl;
    }

    return 0;
}
