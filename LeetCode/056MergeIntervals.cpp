#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 56. Merge Intervals
// Given a collection of intervals, merge all overlapping intervals. For example, Given [1,3],[2,6],[8,10],[15,18], return [1,6],[8,10],[15,18].

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start;});
        res.push_back(intervals[0]);
        for (unsigned int i = 1; i < intervals.size(); ++i) {
            if (res.back().end < intervals[i].start) res.push_back(intervals[i]);
            else res.back().end = max(res.back().end, intervals[i].end);
        }
        return res;
    }
};

int main()
{
    // For example, given array A = [ 1, 2], B = [-2,-1], C = [-1, 2], D = [ 0, 2]

    //int myarray[] = {10, 1, 2, 7, 6, 1, 5};
	//vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
    vector<Interval> a;
    a[0] = {1,3};
    a[1] = {2,6};
    a[2] = {8,10};
    a[3] = {15,18};

    Solution A;
    vector<Interval> print = A.merge(a);
    //vector<vector<int>> print = A.combinationSum2(foo, 8);

    //vector<int> print = A.findDisappearedNumbers(foo);
    //int res = A.maxProfit(foo);

    //for (vector<int>::const_iterator i = a.begin(); i != a.end(); ++i)
      //  std::cout << *i << endl;

//    for (unsigned int k = 0; k < original.size(); k++) {
//        for (unsigned int x = 0; x < original[k].size(); x++) {
//            cout << original[k][x] << " ";
//        }
//        cout << endl;
//    }

    return 0;
}
