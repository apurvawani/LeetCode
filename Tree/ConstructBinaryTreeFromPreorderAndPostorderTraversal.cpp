/*
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree 
of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.


Example 1:
Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]

Example 2:
Input: preorder = [1], postorder = [1]
Output: [1]
 

Constraints:
1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.
*/

class Solution {
public:
    
    map<int,int> index;
    
    TreeNode* listToTree(vector<int>& preorder, vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd) {
        if(preStart <= preEnd || postStart <= postEnd) {
            TreeNode* root = new TreeNode(preorder[preStart]);
            
            if(preStart == preEnd || postStart == postEnd)
                return root;
            
            int ind = index[preorder[preStart+1]];
            int len = ind - postStart + 1;
            
            root->left = listToTree(preorder, postorder, preStart+1, preStart+len, postStart, ind);
            root->right = listToTree(preorder, postorder, preStart+len+1, preEnd, ind+1, postEnd-1);
            
            return root;
        }
        return NULL;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = postorder.size();
        for(int i = 0 ; i < n ; i++)
            index[postorder[i]] = i;
        
        return listToTree(preorder, postorder, 0, n-1, 0, n-1);            
    }
};