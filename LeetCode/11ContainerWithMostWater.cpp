#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
//    int maxArea(vector<int> &height) {
//        long res = 0;
//        long long maxarea = 0;
//        for (vector<int>::size_type i = 0; i < height.size(); i++) {
//            for (vector<int>::size_type j = i + 1; j < (height.size()); j++){
//                res = (j - i) * min(height.at(i), height.at(j));
//                if (res > maxarea)
//                {
//                    maxarea = res;
//                }
//            }
//        }
//        return maxarea;
//    }
     int maxArea(vector<int>& height) {
        int maxarea = 0;
        int res = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            res = min(height[left], height[right]) * (right - left);
            if (res > maxarea) { maxarea = res;}
            //maxarea = max(maxarea, min(height[left], height[right]) * (right - left));
            else if (height[left] < height[right]) left++;
            else right--;
        }
        return maxarea;
    }

};

int main() {

    int myarray[] = {1, 2, 4, 3};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int) );

    Solution A;
    cout << A.maxArea(foo) <<endl;

    return 0;
}
