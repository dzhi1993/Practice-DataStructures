#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) { return res;}
        res,push_back("");

        string myarray[] = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> LetterNumber ( myarray, myarray + sizeof(myarray) / sizeof(string) );
//        LetterNumber[2] = "abc";
//        LetterNumber[3] = "def";
//        LetterNumber[4] = "ghi";
//        LetterNumber[5] = "jkl";
//        LetterNumber[6] = "mno";
//        LetterNumber[7] = "pqrs";
//        LetterNumber[8] = "tuv";
//        LetterNumber[9] = "wxyz";
        for (vector<int>::size_type i = 0; i < digits.size(); i++) {
            int number = digits.at(i) - '0';
            //string letter = LetterNumber.find(number)->second;
            if (LetterNumber.at(number) == "") {
                break;
            }
            for (vector<int>::size_type j = 0; j < res.size(); j++) {
                for (int k = 0; k < LetterNumber.at(number).size(); k++) {
                    res.push_back( res.at(j) + LetterNumber.at(number).at(k) );
                }
            }

        }
        return res;
    }
};


int main() {


}
