#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res, ans;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                res.push_back(i);
            }
        }

        if (res.empty()) {
            ans.push_back(-1);
            ans.push_back(-1);
        }

        else if (res.size() == 1) {
            ans.push_back(res[0]);
            ans.push_back(res[0]);
        }

        else {
            ans.push_back(res[0]);
            ans.push_back(res[res.size() - 1]);
        }

        return ans;
    }
};

int main()
{

    int myarray[] = {1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 9, 10};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int) );
	//reverse(foo.begin(), foo.end());

    Solution A;
    vector<int> a = A.searchRange(foo, 1);

    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }

    return 0;
}
