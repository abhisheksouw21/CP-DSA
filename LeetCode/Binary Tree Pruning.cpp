
class Solution {
    bool f(TreeNode* root){
        if(!root) return false; 
        
        bool r = f(root->right);
        bool l = f(root->left);
        
        if(l == false){
            root->left = nullptr; 
        }
        if(r == false){
            root->right = nullptr; 
        }
        if(root->val == 0 && !l && !r){
            return false;
        }
        
        return true;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(f(root)) return root;
        return nullptr; 
    }
};