#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) { return res;}
        res.push_back("");

        string myarray[] = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> LetterNumber ( myarray, myarray + sizeof(myarray) / sizeof(string) );

        for (vector<int>::size_type i = 0; i < digits.size(); i++) {
            int number = digits.at(i) - '0';
            //cout << number << " ";
            //cout << res.size();
            //string letter = LetterNumber.find(number)->second;
            if (LetterNumber.at(number) == "") {
                res.clear();
                break;
            }
            vector<string> tmp;
            for (vector<int>::size_type j = 0; j < res.size(); j++) {
                for (int k = 0; k < LetterNumber.at(number).size(); k++) {
                    tmp.push_back( res[j] + LetterNumber[number][k] );
                }
            }
            swap(tmp, res);
        }
        return res;
    }
};

int main() {
    Solution A;
    vector<string> a = A.letterCombinations("234645");
    //cout << a.size();
    for (int i =0; i < a.size(); i++) {
        cout << a.at(i) << " ";
    }

    return 0;
}
