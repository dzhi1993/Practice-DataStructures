#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int max = nums[0];
        int end = nums[0];

        for (int i = 1; i<nums.size(); i++) {
            if (end < 0) {
                end = nums[i];
            } else {
                end = end + nums[i];
            }

            if (max < end) {
                max = end;
            }
        }
        return max;
    }
};

class anotherSolution {
public:
    int maxSubArray(vector<int>& nums) {
        int largest = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            largest = max(sum,largest);
            sum = max(sum,0);
        }
        return largest;
    }
};

int main() {

    int myArray[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> foo (myArray, myArray + sizeof(myArray) / sizeof(int) );

    Solution a;
    cout << a.maxSubArray(foo) << endl;

//    for (unsigned int i = 0; i < res.size(); i++)
//    {
//        vector<int> combination = res[i];
//        cout << "[";
//        for (int j = 0; j < combination.size(); j++){
//            cout << combination[j] << " ";
//        }
//        cout <<"]" << endl;
//    }


    return 0;
}