#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string substrings[numRows];
        int i = 0;
        while( i < s.length() ) {
            for (int j = 0; i < s.length() && j < numRows; j ++){
                substrings[j] += s[i];
                i++;
            }
            for (int j = numRows - 2; i < s.length() && j > 0; j --){
                substrings[j] += s[i];
                i++;
            }
        }
        string res = "";
        for (int i = 0; i < numRows; i++){
            res += substrings[i];
        }
        return res;
    }
};

int main()
{
    aSolution A;
    string str = A.convert("ABCDEFGHIJKLMNO", 4);
    cout << str << endl;
    return 0;
}
