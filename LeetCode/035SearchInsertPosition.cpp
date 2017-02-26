#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int SIZE = nums.size();
        int left = 0, right = SIZE - 1;
        int index;

        while (left <= right) {
            int mid = (left + right) / 2;
            index = mid;
            if (nums[mid] == target) return mid;

            else {
                if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        if (nums[index] < target) return index + 1;
        else return index;
    }
};

int main()
{

    int myarray[] = {1};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int) );
	//reverse(foo.begin(), foo.end());

    Solution A;
    cout << A.searchInsert(foo, 0);

    return 0;
}
