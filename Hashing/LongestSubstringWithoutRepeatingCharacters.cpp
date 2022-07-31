/*
Given a string s, find the length of the longest substring without repeating characters.


Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:
0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int res = 0, start = 0, end = 0;
        unordered_map<char,int> mp;
        while(end < len) {
            if(mp.find(s[end]) != mp.end()) {
                start = max(start, mp[s[end]]+1);
            }
            mp[s[end]] = end;
            res = max(res, (end-start+1));
            end++;
        }
        return res;
    }
};