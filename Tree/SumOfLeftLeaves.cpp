/*
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
 

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:
Input: root = [1]
Output: 0
 

Constraints:
The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000
*/

class Solution {
public:
    
    bool isLeaf(TreeNode *node) {
        return (node->left == NULL && node->right == NULL); 
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root != NULL) {
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                if(node->left) {
                    if(isLeaf(node->left))
                        sum += node->left->val;
                    else
                        q.push(node->left);   
                }
                if(node->right)
                    q.push(node->right);
            }
        }
        
        return sum; 
    }
};