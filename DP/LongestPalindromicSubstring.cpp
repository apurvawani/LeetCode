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

//DP : T.C = O(N^2) , S.C = O(N^2)
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
        
        for(int len = 3 ; len <= n ; len++) {
            for(int i = 0, j = i+len-1 ; i <= n-len ; i++, j++) {
                if(s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    start = i;
                    max_len = len;
                }
                else
                    dp[i][j] = false;
            }
        }
        
        return s.substr(start, max_len);
    }
};


//T.C = O(N^2) , S.C = O(1)
class Solution {
public:
    
    int palindromeLength(string s, int left, int right) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right-left-1;
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        if(n <= 1)
            return s;
        
        int start = 0, end = 0;
        for(int i = 0 ; i < n ; i++) {
            //odd len
            int len1 = palindromeLength(s, i, i);
            //even len
            int len2 = palindromeLength(s, i, i+1);
            
            int len = max(len1, len2);
            if(len >= (end-start+1)) {
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start, (end-start+1));
    }
};