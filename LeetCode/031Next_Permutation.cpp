#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int SIZE = nums.size();
        int index = SIZE - 2;
        while( nums[index] >= nums[index+1] ) {
            index--;
        }
        if(index < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        else {
            int MIN = SIZE - 1;
            while ( nums[MIN] <= nums[index] ) {
                MIN--;
            }
            swap( nums[MIN], nums[index] );
            reverse(nums.begin() + index + 1, nums.end());
            return;
        }
    }
};

int main()
{

    int myarray[] = {4, 3, 2, 1};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int) );
	//reverse(foo.begin(), foo.end());

    Solution A;
    A.nextPermutation(foo);

    for (unsigned int i = 0; i < foo.size(); i++){
		cout << foo[i] << " ";
	}
    return 0;
}
