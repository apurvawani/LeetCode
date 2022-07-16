/*
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1
 

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
-100 <= Node.val <= 100
*/

class Solution {
public:
    
    int height(TreeNode* x) {
        if(x == NULL)
            return 0;
        return max(height(x->left), height(x->right)) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
        int cur_h = height(root->left) + height(root->right);
        
        return max(cur_h , max(ld, rd));
    }
};