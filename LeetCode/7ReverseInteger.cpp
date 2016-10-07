#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int reversed_num = 0;

            while(x != 0)
            {
                if (abs(reversed_num) > 214748364)
                    return 0;
                reversed_num = reversed_num*10 + (x % 10);
                x = x/10;
            }
            return reversed_num;
    }
};

int main() {
    Solution A;
    int res = A.reverse(1534236469);
    cout << res;
}
