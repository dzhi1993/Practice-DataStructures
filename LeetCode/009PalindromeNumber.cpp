#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {return false;}
        else if (x == 0) {return true;}
        else
        {
            //int i = x / 10;
            vector<int> integer_vec;
            while (x != 0) {
                int rest = x % 10;
                integer_vec.push_back(rest);
                x = x / 10;
            }
            for (vector<int>::size_type i = 0; i < integer_vec.size()/2 + 1; i++) {
                if (integer_vec.at(i) != integer_vec.at(integer_vec.size() - 1 - i)) {return false;}
            }
            return true;
        }
    }
};

int main() {

    Solution A;
	cout << A.isPalindrome(1) << endl;
	cout << A.isPalindrome(0) << endl;
	cout << A.isPalindrome(121) << endl;
	cout << A.isPalindrome(122) << endl;
	cout << A.isPalindrome(1111111) << endl;

	return 0;
}
