#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int index;
        std::string substring;
        long maxLength = 0; // integer is enough for this problem, but i set long here in case of long string

        for (char &ch : s) {// same as for (const string::value_type &ch : s)

            index = substring.find(ch);
            if ( index == string::npos ) {
                substring.append(1, ch); // parameter 1 means 1 character, ex.(2, a), then output is "aa"
            }
            else {
                if (substring.length() > maxLength){// record current maximum length of substring
                    maxLength = substring.length();
                }
                substring.append(1, ch);
                substring.erase(0, index + 1); // remove a substring of string from position 0 to index+1
            }
        }

        if (substring.length() > maxLength) { // in case of the maximum length is exactly string's length
            maxLength = substring.length();
        }
        return maxLength;
    }
};

int main() {

    string str = "sjfkdjnoedoifje";
    Solution A;
    int maxlength = A.lengthOfLongestSubstring(str);
    cout << "The maximum length of substring without repeating characters is: " << maxlength <<endl;

    return 0;
}
