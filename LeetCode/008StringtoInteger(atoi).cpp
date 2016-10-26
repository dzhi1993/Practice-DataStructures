#include <iostream>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        int flag = 0;
        for (const string::value_type &ch : str) {
            int askii = (int) ch;
            if ((askii >= 48 && askii <= 57) || askii == 45 || askii == 43) // "+" -> 43, "-" -> 45, 0-9 -> [48, 57]
            {
                if (askii == 43)
                {
                    flag = flag + 1;
                }
                if (askii >= 48 && askii <= 57)
                    { res = res * 10 + (askii - 48); }
                else if (askii == 45) {
                    flag = 1;
                }

            }
        }
        if (flag == 1) {
            return -res;
        }
        else if (flag == 2){
        return res;
        }
        else {return res;}

    }
};

int main() {
    Solution A;
    int a = A.myAtoi("1+23");
    cout << a <<endl;
    return 0;
}
