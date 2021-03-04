/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:
Input: nums = []
Output: []

Example 3:
Input: nums = [0]
Output: []

Constraints:
1. 0 <= nums.length <= 3000
2. -10^5 <= nums[i] <= 10^5

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return {};
        
        sort(nums.begin() , nums.end());
        vector<vector<int>> result;
        
        for(int i = 0 ; i < n-2 ; i++) {
            if(i == 0 || nums[i] != nums[i-1]) {
                int k = i+1 , j = n-1;
                while(k < j) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == 0) {
                        result.push_back({nums[i] , nums[k] , nums[j]});
                        while(k < j && nums[k] == nums[k+1])k++;
                        while(k < j && nums[j] == nums[j-1])j--;
                        k++;
                        j--;
                    }
                    else if(sum > 0)j--;
                    else k++;
                }
            }
        }
        return result;
    }
};
