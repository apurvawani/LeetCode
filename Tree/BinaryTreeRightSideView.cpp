/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.


Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,null,3]
Output: [1,3]

Example 3:
Input: root = []
Output: []
 

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root) {
            queue<pair<TreeNode*,int>> q;
            map<int,int> mp;
            q.push({root,0});
            while(!q.empty()) {
                auto [node, level] = q.front();
                q.pop();
                if(mp.find(level) == mp.end())
                    mp[level] = node->val;
                if(node->right)
                    q.push({node->right,level+1});
                if(node->left)
                    q.push({node->left,level+1});
            }
            
            for(auto &x : mp) {
                ans.push_back(x.second);
            }
        }
        return ans;
    }
};