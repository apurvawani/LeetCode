/*
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.


Example 1:
Input: root = [4,2,6,1,3]
Output: 1


Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:
The number of nodes in the tree is in the range [2, 10^4].
0 <= Node.val <= 10^5
*/

class Solution {
public:
    
    int res = INT_MAX;
    TreeNode *prev = NULL;
    
    void diff(TreeNode *node) {
        if(node->left)
            diff(node->left);
        if(prev)
            res = min(res, (node->val - prev->val));
        prev = node;
        if(node->right)
            diff(node->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        diff(root);    
        return res;
    }
};