#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string substrings[numRows];

        for (int i = 0; i < s.length(); i++) {

            int curr = numRows % ( (numRows - 1) * 2 );

            for (int j = 0; j < numRows; j++) {
                if ( curr == 0 ) {
                    substrings[j] += s.at(i);
                }
                else if ()
            }


        }
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
