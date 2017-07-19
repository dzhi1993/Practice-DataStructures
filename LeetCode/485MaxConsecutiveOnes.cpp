#include <iostream>
#include <vector>

using namespace std;

// 485. Max Consecutive Ones
// Given a binary array, find the maximum number of consecutive 1s in this array.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxNums = 0;
        int curr = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                ++curr;
                if (curr > maxNums) maxNums = curr;
            }
            else {
                curr = 0;
            }
        }
        return maxNums;
    }
};

int main()
{

    int myarray[] = {1,1,0,1,1,1};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
	//reverse(foo.begin(), foo.end());

    Solution A;
    //vector<int> print = A.findDisappearedNumbers(foo);
    //int res = A.maxProfit(foo);
    cout << A.findMaxConsecutiveOnes(foo);


    //for (vector<int>::const_iterator i = print.begin(); i != print.end(); ++i)
        //std::cout << *i << ' ';

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
