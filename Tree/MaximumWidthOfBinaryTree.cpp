/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 
Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
 

Constraints:
The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100
*/

typedef long long int ll;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if(root) {
			queue<pair<TreeNode*, int>> q;
			q.push({root,0});
			while(!q.empty()) {
				int size = q.size();
				int min_id = q.front().second;
				int first, last;
				for(int i = 0 ; i < size ; i++) {
                    int cur_id = q.front().second - min_id;
					TreeNode* cur_node = q.front().first;
					q.pop();
					if(i == 0)
						first = cur_id;
					if(i == size-1)
						last = cur_id;
					if(cur_node->left)
						q.push({cur_node->left, (ll)cur_id*2+1});
					if(cur_node->right)
						q.push({cur_node->right, (ll)cur_id*2+2});
				}
				ans = max(ans, (last-first+1));
			}
        }
        return ans;
    }
};