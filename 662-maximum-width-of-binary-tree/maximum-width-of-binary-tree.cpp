/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
       if (!root) return 0;
        
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int x = q.size();
            long long mn = q.front().second; // subtract min to avoid integer overflow
            long long f = 0, l = 0;
            
            for (int i = 0; i < x; ++i) {
                long long id = q.front().second - mn;
                TreeNode* node = q.front().first;
                q.pop();
                
                if (i == 0) f = id;
                if (i == x - 1) l = id;
                
                if (node->left) {
                    q.push({node->left, id * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, id * 2 + 2});
                }
            }
            ans = max(ans, l - f + 1);
        }
        
        return ans;
    }
};