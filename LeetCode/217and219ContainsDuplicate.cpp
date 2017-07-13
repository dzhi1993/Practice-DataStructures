#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

// NO.217 Contains Duplicate
// Given an array of integers, find if the array contains any duplicates.
// Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

// NO.219 Contains Duplicate II
// Given an array of integers and an integer k,
// find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

class Solution { // No.217
public:
    bool containsDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};

class anotherSolution { // No.217
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) return true;
        }
        return false;
    }
};

class Solution1 { // No.219
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0) return false;
        set<int> window;
        for (int i = 0; i < nums.size(); ++i) {
            if (i <= k) {
                window.insert(nums[i]);
                if (window.size() != i+1) return true;
            }
            else {
                window.erase(nums[i-k-1]);
                window.insert(nums[i]);
                if (window.size() != k+1) return true;
            }
        }
        return false;
    }
};

int main()
{

    int myarray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
	//reverse(foo.begin(), foo.end());

    Solution1 A;
    //int res = A.maxProfit(foo);
    cout << A.containsNearbyDuplicate(foo, 9);


    //for (set<int,less<int> >::const_iterator j = intSetSort.begin(); j != intSetSort.end(); ++j)
      //  std::cout << *j << ' ';

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
