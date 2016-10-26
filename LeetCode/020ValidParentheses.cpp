#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        string left = "([{";
        string right = ")]}";
        stack<char> ch;

        for (int i = 0; i < s.size(); i++) {
            if (left.find(s.at(i)) != string::npos) { ch.push(s.at(i)); }
            else if ( !ch.empty() && ch.top() == left.at(right.find(s.at(i))) ) { ch.pop(); }
            else { return false; }
        }
        return ch.empty();
    }
};

int main() {
    Solution A;
    cout << A.isValid("{()}");

    return 0;
}
