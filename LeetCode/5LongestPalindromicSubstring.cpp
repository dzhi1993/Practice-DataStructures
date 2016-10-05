#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s)
    {
        cout << "length of string: " << s.size() << endl;
        string str2 = s;
        reverse( str2.begin(), str2.end() );
        int LCSuff[s.size()+1][str2.size()+1];
        int result = 0;  // To store the length of the longest common substring
        int startPos1, startPos2, endPos1 = 0, endPos2 = 0;
        string substring;

        for (int i = 0; i <= s.size(); i++)
        {
            for (int j = 0; j <= str2.size(); j++)
            {
                if (i == 0 || j == 0)
                    LCSuff[i][j] = 0;

                else if (s[i-1] == str2[j-1])
                {
                    LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                    if (LCSuff[i][j] > result) {
                        endPos1 = i - 1;
                        endPos2 = j - 1;
                    }
                    result = max(result, LCSuff[i][j]);
                }
                else LCSuff[i][j] = 0;
            }
        }
        startPos1 = endPos1 - result + 1;
        startPos2 = endPos2 - result + 1;

        if ( s.size() - startPos1 - 1 == endPos2 ){
            substring = str2.substr(startPos2, result);
        }
        cout << "Length: " << result << endl;
        cout << "Start Position1: " << startPos1 << " End Position1: " << endPos1 << endl;
        cout << "Start Position2: " << startPos2 << " End Position2: " << endPos2 << endl;
        return substring;
    }
};


int main() {

    //string str1 = "abaabcbadefg";
    //string str2 = "sfabcbadefsfdhjg";
    Solution A;
    string str = A.longestPalindrome("abcdefghigklmlnopqrsttsuvw");
    cout << str;

    return 0;
}
