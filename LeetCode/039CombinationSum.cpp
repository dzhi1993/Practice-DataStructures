#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector< vector<int> > result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates,target, result, combination, 0);
        return result;
    }

    void combinationSum(vector<int> &candidates, int target, vector< vector<int> > &res, vector<int> &combination, int begin) {
        if(target == 0){
            res.push_back(combination);
        }

        for(int i = begin; i < candidates.size() && candidates[i] <= target; i++){ // vector candidates has already sorted.
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }

};

int main() {

    int myarray[] = {2, 3, 6, 7};
    vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int) );

    Solution a;
    vector< vector<int> > res = a.combinationSum(foo, 7);

    for (unsigned int i = 0; i < res.size(); i++)
    {
        vector<int> combination = res[i];
        cout << "[";
        for (int j = 0; j < combination.size(); j++){
            cout << combination[j] << " ";
        }
        cout <<"]" << endl;
    }


    return 0;
}