#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> res;

        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                res.push_back(left + 1);
                res.push_back(right + 1);
                return res;
            }
            else {
                if (numbers[left] + numbers[right] > target) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return res;
    }
};

int main()
{

    int myarray[] = {2, 7, 11, 15};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
	//reverse(foo.begin(), foo.end());

    Solution A;
    //int res = A.maxProfit(foo);
    //cout << res << endl;

//    for (unsigned int k = 0; k < print.size(); k++) {
//        for (unsigned int x = 0; x < print[k].size(); x++) {
//            cout << print[k][x] << " ";
//        }
//        cout << endl;
//    }

    //vector<int> a(10);
    //cout << a.size() << endl;
    vector<int> print = A.twoSum(foo, 9);
    //cout << print.size();
    for (vector<int>::const_iterator i = print.begin(); i != print.end(); ++i)
    std::cout << *i << ' ';

    return 0;
}
