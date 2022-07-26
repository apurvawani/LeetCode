/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and 
postorder is the postorder traversal of the same tree, construct and return the binary tree.


Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
*/

class Solution {
public:
    
    int rootIndex;
    map<int,int> index;
    
    TreeNode* listToTree(vector<int>& postorder, int left, int right) {
        if(left <= right) {
            TreeNode* root = new TreeNode(postorder[rootIndex--]);
            root->right = listToTree(postorder, index[root->val]+1, right);
            root->left = listToTree(postorder, left, index[root->val]-1);
            return root;
        }
        return NULL;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        rootIndex = n-1;
        for(int i = 0 ; i < n ; i++)
            index[inorder[i]] = i;
        return listToTree(postorder, 0, n-1);
    }
};