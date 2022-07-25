/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
You can return the answer in any order.


Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:
Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:
The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000
*/

class Solution {
public:
    
    unordered_map<TreeNode*,TreeNode*> parent;
    
    void markParent(TreeNode* node, TreeNode* p) {
        parent[node] = p;
        if(node->left)
            markParent(node->left, node);
        if(node->right)
            markParent(node->right, node);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root) {
            markParent(root, NULL);
            queue<TreeNode*> q;
            unordered_map<TreeNode*, bool> visited;
            int level = 0;
            q.push(target);
            visited[target] = true;
            while(!q.empty()) {
                if(level++ == k)
                    break;
                int size = q.size();
                while(size--) {
                    auto node = q.front();
                    q.pop();
                    if(node->left && !visited[node->left]) {
                        q.push(node->left);
                        visited[node->left] = true;
                    }
                    if(node->right && !visited[node->right]) {
                        q.push(node->right);
                        visited[node->right] = true;
                    }
                    if(parent[node] && !visited[parent[node]]) {
                        q.push(parent[node]);
                        visited[parent[node]] = true;
                    }
                }
            }
            while(!q.empty()) {
                ans.push_back(q.front()->val);
                q.pop();
            }
        }
        return ans;
    }
};