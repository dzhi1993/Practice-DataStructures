#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int SIZE = nums.size();
        int left = 0, right = SIZE - 1;

        if (nums.empty()) return -1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;

            if (nums[left] <= nums[mid]) {
                if (target < nums[mid] && target >= nums[left]) { right = mid - 1; }
                else left = mid + 1;
            }
            else {
                if (target > nums[mid] && target <= nums[right]) { left = mid + 1; }
                else right = mid - 1;
            }
        }
        if (nums[left] == target) return left;
        else return -1;
    }
};

int main()
{

    int myarray[] = {3, 1};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int) );
	//reverse(foo.begin(), foo.end());
    vector<int> boo;

    Solution A;
    cout << A.search(foo, 1) << endl;

    return 0;
}
