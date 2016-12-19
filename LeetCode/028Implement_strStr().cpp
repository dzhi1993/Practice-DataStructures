#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Note: When we delete the element, the iterator i should minus 1 to point original next element.

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		if (haystack.empty()) return -1;
		int i = 0, n = haystack.size(), m = needle.size();
		if (n < m) return -1;
		for (; i + m <= n; i++) {
			int j = 0;
			for (; j < m && haystack[i + j] == needle[j]; j++);
			if (j == m) break;
		}
		return i + m <= n ? i : -1;
	}
};

int main() {

	Solution s;
	//TestCases:
	string haystack = "abc";
	string needle = "";
	int output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;

	haystack = "";
	needle = "a";
	output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;

	haystack = "abc";
	needle = "a";
	output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;

	haystack = "abababab";
	needle = "ab";
	output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;

	haystack = "apple";
	needle = "b";
	output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;

	haystack = "aaaaaaaa";
	needle = "a";
	output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;

	haystack = "abcdefgh";
	needle = "abcdefg";
	output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;

	haystack = "abcdefgh";
	needle = "gh";
	output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;


	haystack = "mississipi";
	needle = "pi";
	output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;

	system("pause");
	return 0;
}