#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s)
    {
        int len = s.length();
        int P[1000][1000];
        memset(P, 0, len*len*sizeof(int));
        int maxlen = 0, start = 0, end = 0;
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                P[j][i] = (s[j] == s[i])&&((i - j == 1) || P[j+1][i-1]);
                if (P[j][i]&&(maxlen<i-j+1))
                {
                    maxlen = i-j+1;
                    start = j;
                    end = i;
                }
            }
            P[i][i] = 1;
        }
        return s.substr(start, end - start + 1);
    }

//    string longestPalindrome(string s)
//    {
//        //long strlen = s.length();
//        cout << "length of string: " << static_cast<long>(s.length()) << endl;
//        string str2 = s;
//        reverse( str2.begin(), str2.end() );
//        cout << str2 <<endl;
//        int LCSuff[s.length() + 1][s.length() + 1];
//        int result = 0;  // To store the length of the longest common substring
//        long startPos1, startPos2, endPos1 = 0, endPos2 = 0;
//        string substring;
//
//        for (long i = 0; i <= static_cast<long>(s.length()); i++)
//        {
//            for (long j = 0; j <= static_cast<long>(str2.length()); j++)
//            {
//                if (i == 0 || j == 0)
//                    LCSuff[i][j] = 0;
//
//                else if (s.at(i - 1) == str2.at(j - 1))
//                {
//                    LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
//                    if (LCSuff[i][j] > result) {
//                        endPos1 = i - 1;
//                        endPos2 = j - 1;
//                    }
//                    result = max(result, LCSuff[i][j]);
//                }
//                else LCSuff[i][j] = 0;
//            }
//        }
//        startPos1 = endPos1 - result + 1;
//        startPos2 = endPos2 - result + 1;
//
//        if ( static_cast<long>(s.length()) - startPos1 - 1 == endPos2 && result > 2){
//            substring = str2.substr(startPos2, result);
//        }
//        cout << "Length of substring: " << result << endl;
//        cout << "Start Position1: " << startPos1 << " End Position1: " << endPos1 << endl;
//        cout << "Start Position2: " << startPos2 << " End Position2: " << endPos2 << endl;
//        return substring;
//    }
};


int main() {

    //string str1 = ;
    //string str2 = "sfabcbadefsfdhjg";
    Solution A;
    string str = A.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
    cout << str;

    return 0;
}
