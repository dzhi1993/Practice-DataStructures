#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// NO.189 Rotate Array
// Rotate an array of n elements to the right by k steps.
// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        k = k % N;
        //vector<int>::iterator itr;
        //itr = nums.begin()
        reverse(nums.begin(), nums.begin()+N-k);
        reverse(nums.begin()+N-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main()
{

    int myarray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
	//reverse(foo.begin(), foo.end());

    Solution A;
    //int res = A.maxProfit(foo);
    //cout << A.majorityElement(foo) << endl;

//    for (unsigned int k = 0; k < print.size(); k++) {
//        for (unsigned int x = 0; x < print[k].size(); x++) {
//            cout << print[k][x] << " ";
//        }
//        cout << endl;
//    }

    //vector<int> a(10);
    //cout << a.size() << endl;
    A.rotate(foo, 16);
    //cout << print.size();

    for (vector<int>::const_iterator i = foo.begin(); i != foo.end(); ++i)
    std::cout << *i << ' ';

    return 0;
}
