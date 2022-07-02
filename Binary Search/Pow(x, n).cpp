/*
Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

 
Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 

Constraints:
-100.0 < x < 100.0
-2^31 <= n <= 2^31-1
-10^4 <= x^n <= 10^4
*/

class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        if(n == INT_MAX) return x;
        if(n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        if(n < 0) {
            n = n*(-1);
            x = 1/x;
        }
        while(n > 0) {
            if(n&1 != 0) {
                result = result*x;
            }
            x = x*x;
            n = n >> 1;
        }
        return result;
    }
};