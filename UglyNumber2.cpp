/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return the nth ugly number.

 
Example 1:
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

Example 2:
Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:
1 <= n <= 1690
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        int ind2 = 0, ind3 = 0, ind5 = 0; 
        vector<int> res = {1};
        
        while(res.size() < n) {
            int ans = min(res[ind2]*2, min(res[ind3]*3, res[ind5]*5));
            res.push_back(ans);
            if(ans == res[ind2]*2)
                ind2++;
            if(ans == res[ind3]*3)
                ind3++;
            if(ans == res[ind5]*5)
                ind5++;   
        }
        return res[n-1];
    }
};