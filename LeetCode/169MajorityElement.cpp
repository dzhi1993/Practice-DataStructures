#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// NO.169 Majority Element
// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
// You may assume that the array is non-empty and the majority element always exist in the array.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 1;
        int majority = nums[0];

        for (unsigned int i = 1; i < nums.size(); i++) {
            if (counter == 0) {
                majority = nums[i];
                counter++;
            }
            else {
                if (nums[i] != majority) {
                    counter--;
                }
                else counter++;
            }
        }
        return majority;
    }
};

int main()
{

    int myarray[] = {1, 2, 1, 2, 1, 2, 1, 2, 1};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
	//reverse(foo.begin(), foo.end());

    Solution A;
    //int res = A.maxProfit(foo);
    cout << A.majorityElement(foo) << endl;

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

    //for (vector<int>::const_iterator i = foo.begin(); i != foo.end(); ++i)
    //std::cout << *i << ' ';

    return 0;
}
