/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
 

Constraints:
1 <= nums.length <= 10^5
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
*/

class Solution {
public:
    
    static int compare(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto x : nums) {
            mp[x]++;
        }
        vector<pair<int,int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), compare);
        
        vector<int> result(k);
        for(int i = 0 ; i < k ; i++) {
            result[i] = v[i].first;
        }
        
        return result;
    }
};