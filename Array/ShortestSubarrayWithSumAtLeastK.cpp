/*
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. 
If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

 

Example 1:
Input: nums = [1], k = 1
Output: 1

Example 2:
Input: nums = [1,2], k = 4
Output: -1

Example 3:
Input: nums = [2,-1,2], k = 3
Output: 3
 

Constraints:
1 <= nums.length <= 10^5
-10^5 <= nums[i] <= 10^5
1 <= k <= 10^9
*/

struct Pair {
    long total, index;  
};

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long res = INT_MAX, sum = 0;
        long n = nums.size(), i = 0;
        deque<Pair> dq;
        
        while(i < n) {
            sum += nums[i++];
            if(sum >= k)
                res = min(res, i);
                
            while(!dq.empty() && (sum - dq.front().total) >= k) {
                struct Pair p = dq.front();
                res = min(res, i-p.index-1);
                dq.pop_front();
            }
            
            while(!dq.empty() && sum < dq.back().total)
                dq.pop_back();
            
            struct Pair p = {sum, i-1};
            dq.push_back(p);
                
        }
        
        if(res == INT_MAX)
            return -1;
        else 
            return res;
    }
};