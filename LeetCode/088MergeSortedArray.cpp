#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //vector<int> res;
        int i = m-1, j = n-1, sum = m+n-1;
        while (j >= 0) {
            if (i>=0 && nums1[i] > nums2[j] ) {
                nums1[sum] = nums1[i];
                sum--;
                i--;
            }
            else {
                nums1[sum] = nums2[j];
                sum--;
                j--;
            }
        }
        cout << nums1.size() << endl;
        //for (std::vector<int>::const_iterator k = nums1.begin(); k != nums1.end(); ++k)
          //  std::cout << *k << ' ';
    }
};

class anotherSolution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }

        cout << nums1.size() << endl;
        //for (std::vector<int>::const_iterator k = nums1.begin(); k != nums1.end(); ++k)
         //   std::cout << *k << ' ';
    }
};

int main() {

    int myArray1[] = {1,3,4,7,8,12};
    int myArray2[] = {2,3,4,5,9};
    vector<int> A (myArray1, myArray1 + sizeof(myArray1) / sizeof(int) );
    vector<int> B (myArray2, myArray2 + sizeof(myArray2) / sizeof(int) );

    Solution a;
    a.merge(A, 6, B, 5);
    //vector<int> res = a.plusOne(foo);
    for (std::vector<int>::const_iterator i = A.begin(); i != A.end(); ++i)
        std::cout << *i << ' ';

    //cout << a.plusOne(foo) << endl;

    return 0;
}