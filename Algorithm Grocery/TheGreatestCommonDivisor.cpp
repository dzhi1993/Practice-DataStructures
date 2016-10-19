////////////////////////////////////////////////////////////////////////////////////
/* The algorithms to find the greatest common divisor of two positive integer value
*  Author: Da Zhi
*  Created by: October 19th at Microsemi Corporation
*  Date: 11:14 AM 10/19/2016
*/
////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

class EuclideanAlgorithm { // Euclidean Algorithm
                           // The general idea of this algorithm is based on Euclidean Algorithm --
                           // The greatest common divisor of two positive integer a and b (a > b) is equals to
                           // the greatest common divisor of c and b, where c = a%b
                           // Chinese name of this algorithm is 辗转相除法, The complexity is O(log(min(a,b)))
private:
    int gcd(int a, int b) {
        if (a%b == 0) return b;
        else { return gcd(b, a%b); }
    }

public:
    int getGCD(int num1, int num2) {
        int res = 1;
        if (num1 > num2) { res = gcd(num1 ,num2); }
        else { res = gcd(num2, num1); }
        return res;
    }

};

class gengxiangjiansunshu { // gengxiangjiansunshu Algorithm
                            // Similar to Euclidean Algorithm, but it is optimal than previous one.
                            // The general idea of this algorithm is based on: The GCD of a and b (a > b) is equals to
                            // the greatest common divisor of c and b, where c = a - b
                            // The Chinese name of this algorithm is 更相减损术, The complexity is O(max(a,b))

public:
    int getGCD(int number1, int number2) {
        if(number1 == number2) return number1;
        else if (number1 < number2) { return getGCD(number2 - number1, number1); }
        else { return getGCD(number1 - number2, number2); }
    }

};

class OptimalSolution { // An optimal solution: solved the defect of % operation in gengxiangjiansunshu Algorithm by using logical shift
                        // Instead of % operation, judge the number is odd or even, then both right shift, when both number are even
                        // The complexity is O(log(max (a, b)))
public:
    int getGCD(int number1, int number2) {
        if (number1 == number2) return number1;
        else if (number1 < number2) return getGCD(number2, number1);
        else {
            if (!number1&1 && !number2&1) { return getGCD(number1>>1, number2>>1) << 1; }
            else if (!number1&1 && number2&1) { return getGCD(number1>>1, number2); }
            else if (number1&1 && !number2&1) { return getGCD(number1, number2>>1); }
            else { return getGCD(number2, number1 - number2); }
        }
    }
};

int main() {
    EuclideanAlgorithm A;
    gengxiangjiansunshu B;
    OptimalSolution C;
    cout << C.getGCD(25, 10) <<endl;

    return 0;
}
