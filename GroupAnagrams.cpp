/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1 :
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

Constraints:
1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int n = strs.size();
        map<string , vector<string>> v;
        string temp;
        for(int i = 0 ; i < n ; i++) {
            temp = strs[i];
            sort(temp.begin() , temp.end());
            v[temp].push_back(strs[i]);
        }
        for(auto x : v) {
            result.push_back(x.second);
        }
        return result;
    }
};
