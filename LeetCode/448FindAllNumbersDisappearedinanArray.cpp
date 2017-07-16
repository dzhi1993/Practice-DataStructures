#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 448. Find All Numbers Disappeared in an Array
// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
// Find all the elements of [1, n] inclusive that do not appear in this array.
// Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        std::set<int> index(nums.begin(), nums.end());
        for (int i = 1; i <= nums.size(); ++i) {
            if (!index.count(i))
                res.push_back(i);
        }
        return res;
    }
};

int main()
{

    int myarray[] = {4,3,2,7,8,2,3,1};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
	//reverse(foo.begin(), foo.end());

    Solution A;
    vector<int> print = A.findDisappearedNumbers(foo);
    //int res = A.maxProfit(foo);
    //cout << A.(foo, 9);


    for (vector<int>::const_iterator i = print.begin(); i != print.end(); ++i)
        std::cout << *i << ' ';

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
