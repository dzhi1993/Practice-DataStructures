#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<string> generateParenthesis (int n) {
//        if (n == 0) return vector<string>(1, "");
//        if (n == 1) return vector<string> (1, "()");
//        vector<string> result;
//        for (int i = 0; i < n; ++i)
//            for (auto inner : generateParenthesis (i))
//                for (auto outer : generateParenthesis (n - 1 - i))
//                    result.push_back ("(" + inner + ")" + outer);
//        return result;
//}
//
//    vector<string> generateParenthesis(int n) {
//        vector<string> res;
//        if (n == 0) {
//            res.push_back("");
//            return res;
//        }
//        else if (n == 1) {
//            res.push_back("()");
//            return res;
//        }
//        else {
//            result.push_back("()");
//            result.push_back("()","(",")");
//            for (vector<int>::type_size i =0; i < n; i++) {
//
//            }
//        }
//    }
//};

class anotherSolution {
private:
    void generateParenthesis(int left, int right, vector<string>& res, string& s) {
        if (left == 0) {
            int i = right;
            while (i) { s.push_back(')'); i--; }
            res.push_back(s);

            while (i < right) { s.pop_back(); i++; }
            return;
        }
        else {
            s.push_back('(');
            generateParenthesis(left-1, right, res, s);
            s.pop_back();

            if (left != right) {
                s.push_back(')');
                generateParenthesis(left, right-1, res, s);
                s.pop_back();
            }
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string str;
        generateParenthesis(n, n, res, str);
        return res;
    }
};

int main() {
    anotherSolution A;
    vector<string> a = A.generateParenthesis(8);
    for (int i = 0; i < a.size(); i++) {
        cout << a.at(i) << endl;
    }

    return 0;
}
