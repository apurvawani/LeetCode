/*
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.


Example 1:
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
 

Constraints:
The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-10^4 <= root.val <= 10^4
-10^4 <= subRoot.val <= 10^4
*/

class Solution {
public:
    
    bool compare(TreeNode *x, TreeNode *y) {
        if(x == NULL && y == NULL)
            return true;
        else if(x != NULL && y != NULL) {
            if(x->val != y->val)
                return false;
            return (compare(x->left, y->left) && compare(x->right, y->right));   
        }
        else
            return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot != NULL)
            return false;
        else if(root != NULL && subRoot != NULL) {
            if(root->val == subRoot->val && compare(root, subRoot))
                return true;
            else
                return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
        }
        else
            return true;
    }
};