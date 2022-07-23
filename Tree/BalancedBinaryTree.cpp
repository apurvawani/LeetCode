/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:
A binary tree in which the left and right subtrees of every node differ in height by no more than 1.


Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true
 

Constraints:
The number of nodes in the tree is in the range [0, 5000].
-10^4 <= Node.val <= 10^4
*/

class Solution {
public:
    
    int height(TreeNode *node) {
        if(node == NULL)
            return 0;
        else if(node->left == NULL && node->right == NULL)
            return 1;
        else
            return max(height(node->left), height(node->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        if(abs(height(root->left) - height(root->right)) > 1)
            return false;
        else
            return (isBalanced(root->left) && isBalanced(root->right));
    }
};