/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  bool getpath(TreeNode* root, vector<TreeNode*>& path, TreeNode* target){
        if(!root) return false;
        
        path.push_back(root);
        
        if(root == target){
            return true;
        }
        
        if(getpath(root->left, path, target) || getpath(root->right, path, target)) 
            return true;
            
        path.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      vector<TreeNode*> a;
        vector<TreeNode*> b;
        
        getpath(root, a, p); 
        getpath(root, b, q);
        
        int i = 0;
        TreeNode* ans = a[0];
        
        while(i < a.size() && i < b.size() && a[i] == b[i]){
            ans = a[i]; 
            i++;
        }
        
        return ans;
    }
};