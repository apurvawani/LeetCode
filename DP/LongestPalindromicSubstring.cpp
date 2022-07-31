/*
Given a string s, return the longest palindromic substring in s.


Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
 

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
*/

class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 1)
            return s;
        
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        int start = 0, max_len = 1;
        
        for(int i = 0 ; i < n ; i++) {
            dp[i][i] = true;
        }
        
        for(int i = 0 ; i < n-1 ; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                max_len = 2;
                start = i;
            }
        }
        
        for(int i = 3 ; i <= n ; i++) {
            for(int j = 0, k = j+i-1 ; j <= n-i ; j++, k++) {
                if(s[j] == s[k] && dp[j+1][k-1]) {
                    dp[j][k] = true;
                    start = j;
                    max_len = i;
                }
                else
                    dp[j][k] = false;
            }
        }
        
        return s.substr(start, max_len);
    }
};