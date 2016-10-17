#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string common = strs[0];
        int len = common.size();
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            for (; j < len && j < strs[i].size() && common[j] == strs[i][j]; j++);
            len = j;
        }
        return common.substr(0, len);
    }
};

int main() {

//    vector<string> foo;
//    foo.push_back("sfdfs");
//    foo.push_back("sfdfs");
//    foo.push_back("sdgfh");
//    foo.push_back("sfgg");
    string myarray[] = {"sfdfs", "sfsfsd","sfghg"};
	vector<string> foo (myarray, myarray + sizeof(myarray) / sizeof(string) );

    Solution A;
    cout << A.longestCommonPrefix(foo) << endl;

    return 0;
}
