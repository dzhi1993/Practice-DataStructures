#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// This two solutions are solving Problem No. 121 and No. 122, respectively.

class Solution {//NO. 121
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int max = 0;
        int min = prices[0];

        for (unsigned int i = 1; i < prices.size(); i++) {
            if (prices[i] < min) {min = prices[i];}
            else {
                if (max < prices[i] - min) {max = prices[i] - min;}
            }
        }
        return max;
    }
};

class anotherSolution {//NO.122
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        for (unsigned int i = 1; i < prices.size(); i++) {
            if (prices[i] - prices[i-1] > 0) {max += prices[i] - prices[i-1];}
        }
        return max;
    }
};

int main()
{

    int myarray[] = {7, 1, 5, 3, 6, 4};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int) );
	//reverse(foo.begin(), foo.end());

    Solution A;
    int res = A.maxProfit(foo);
    cout << res << endl;

//    for (unsigned int k = 0; k < print.size(); k++) {
//        for (unsigned int x = 0; x < print[k].size(); x++) {
//            cout << print[k][x] << " ";
//        }
//        cout << endl;
//    }

    //vector<int> a(10);
    //cout << a.size() << endl;
    //for (vector<int>::const_iterator i = print.begin(); i != print.end(); ++i)
    //std::cout << *i << ' ';

    return 0;
}
