/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

 

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums is sorted in a strictly increasing order.
*/

class Solution {
public:
    
    TreeNode* util(vector<int>&nums, int left, int right) {
        if(left <= right) {
            int mid = (left+right)>>1;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = util(nums, left, mid-1);
            root->right = util(nums, mid+1, right);
            return root;   
        }
        return NULL;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return NULL;
        if(n == 1) {
            TreeNode *root = new TreeNode(nums[0]);
            return root;
        }
        else
            return util(nums, 0, n-1);
    }
};