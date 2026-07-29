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
 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //   vector<TreeNode*> a;
    //     vector<TreeNode*> b;
        
    //     getpath(root, a, p); 
    //     getpath(root, b, q);
        
    //     int i = 0;
    //     TreeNode* ans = a[0];
        
    //     while(i < a.size() && i < b.size() && a[i] == b[i]){
    //         ans = a[i]; 
    //         i++;
    //     }
        
    //     return ans;

    if(root == nullptr || p == root || root == q) 
            return root;
            
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if(l == nullptr){
            return r;
        }
        else if(r == nullptr){
            return l;
        }
        else {
            return root;
        }

    }
};