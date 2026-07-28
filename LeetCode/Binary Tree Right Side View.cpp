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
     void f(TreeNode* root,int l,vector<int>&ans){
        if(root==nullptr) return;
        if(ans.size()==l) ans.push_back(root->val);
        f( root->right,l+1,ans);
        f( root->left,l+1,ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
         f(root,0,ans);
         return ans;
        //  vector<int> ans;
        // if(root==nullptr) return ans;
        // queue<TreeNode*>q;
        // q.push(root);
        // while(!q.empty()){
        //     int size=q.size();
        //     vector<int>temp;
        //     for(int i=0;i<size;++i){
        //         TreeNode* node= q.front();
        //         q.pop();
        //         if(node->left!=nullptr) q.push(node->left);
        //           if(node->right!=nullptr) q.push(node->right);
        //           temp.push_back(node->val);
        //     }
        //     ans.push_back(temp[size-1]);
        // }
        // return ans;
    }
};