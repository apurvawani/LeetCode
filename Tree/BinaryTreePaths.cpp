/*
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.


Example 1:
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:
Input: root = [1]
Output: ["1"]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
*/

class Solution {
public:
    
	void path(TreeNode *node, string result, vector<string>& res) {
		result += to_string(node->val);
		if(node->left == NULL && node->right == NULL)
			res.push_back(result);
		else if(node->left == NULL)
			path(node->right, result + "->", res);
		else if(node->right == NULL)
			path(node->left, result + "->", res);
		else {
			path(node->left, result + "->", res);
			path(node->right, result + "->", res);
		}
	}
	
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
		if(root == NULL)
			return res;
		path(root,"",res);
		return res;
    }
};