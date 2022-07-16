/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:
The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100

*/

class Solution {
public:
    
    bool checkSymmetry(TreeNode *x , TreeNode *y) {
        if(x == NULL && y == NULL)
            return true;
        if(x != NULL && y != NULL) {
            if(x->val == y->val) {
                return (checkSymmetry(x->left, y->right) && (checkSymmetry(x->right, y->left))); 
            }
        }
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return true;
        if(root->left != NULL && root->right != NULL) {
            if(root->left->val == root->right->val) {
                return checkSymmetry(root->left, root->right);
            }
            else
                return false;
        }
        return false;
    }
};