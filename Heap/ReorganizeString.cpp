/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
Return any possible rearrangement of s or return "" if not possible.

 
Example 1:
Input: s = "aab"
Output: "aba"

Example 2:
Input: s = "aaab"
Output: ""
 

Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.
*/

class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        for(auto c : s)
            mp[c]++;
        
        priority_queue<pair<int,char>> pq;
        for(auto x : mp)
            pq.push({x.second , x.first});
        
        string res = "";
        while(pq.size() > 1) {
            pair<int,char> x = pq.top();
            pq.pop();
            pair<int,char> y = pq.top();
            pq.pop();
            res += x.second;
            res += y.second;
            x.first--;
            y.first--;
            if(x.first > 0)
                pq.push(x);
            if(y.first > 0)
                pq.push(y);
        }
        if(!pq.empty()) {
            if(pq.top().first > 1)
                return "";
            res += pq.top().second;
        }
        return res;
    }
};