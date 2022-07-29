/*
Given the root of a binary tree, return the inorder traversal of its nodes values.


Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]
 

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

//Space - O(N)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root != NULL) {
            stack<TreeNode*> s;
            TreeNode *ptr = root;
            while(ptr || !s.empty()) {
                while(ptr) {
                    s.push(ptr);
                    ptr = ptr->left;
                }
                ptr = s.top();
                s.pop();
                res.push_back(ptr->val);
                ptr = ptr->right;
            }
        }
        return res;
    }
};


//Morris Traversal : Space -  O(1)
class Solution {
public:
    
    vector<int> inorder(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur = root;
        while(cur) {
            if(cur->left == NULL) {
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else {
                TreeNode* prev = cur->left;
                while(prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                if(prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                }
                else {
                    prev->right = NULL;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }            
        }
        return ans;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root)
            return inorder(root);
        return res;
    }
};