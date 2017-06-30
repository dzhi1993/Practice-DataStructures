#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i]++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

int main() {

    int myArray[] = {2,1,3,4,1,2,1,5,9};
    vector<int> foo (myArray, myArray + sizeof(myArray) / sizeof(int) );

    Solution a;
    vector<int> res = a.plusOne(foo);
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        std::cout << *i << ' ';

    //cout << a.plusOne(foo) << endl;

    return 0;
}