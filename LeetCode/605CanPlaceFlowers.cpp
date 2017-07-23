#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// 605. Can Place Flowers
// Suppose you have a long flowerbed in which some of the plots are planted and some are not.
// However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.
// Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n,
// return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (unsigned int i = 0; i < flowerbed.size(); ++i) {
                //cout << i << " ";
            if (flowerbed[i] == 0) {
                if (i == 0 && flowerbed[i+1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
                else if (i == flowerbed.size() - 1 && flowerbed[i-1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
                else if (flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            //if (n == 0) return true;
        }
        return n <= 0;
    }
};

class anotherSolution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) {
        for (int i = 0; i < bed.size(); i++) {
            if (!bed[i] && (i == 0 || !bed[i - 1]) && (i == bed.size() - 1 || !bed[i + 1])) {
                bed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};

int main()
{
    //Input: [1, 2, 3, 4, 5], k = 1       output = 4
    //Input: [3, 1, 4, 1, 5], k = 2       output = 2
    //Input: [1, 3, 1, 5, 4], k = 0       output = 1
    int myarray[] = {0,0,1,0,1};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int));
	//vector<vector <int> > foo(3, vector<int>(2, 1) );
	//reverse(foo.begin(), foo.end());
    Solution A;
    cout << A.canPlaceFlowers(foo, 1);
    //vector<int> print = A.findDisappearedNumbers(foo);
    //int res = A.maxProfit(foo);

    //for (vector<string>::const_iterator i = tokens.begin(); i != tokens.end(); ++i)
      //  std::cout << *i << endl;

//    for (unsigned int k = 0; k < print.size(); k++) {
//        for (unsigned int x = 0; x < print[k].size(); x++) {
//            cout << print[k][x] << " ";
//        }
//        cout << endl;
//    }

    return 0;
}
