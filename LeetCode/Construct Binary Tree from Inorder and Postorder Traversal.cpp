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
    TreeNode* f(vector<int>& inorder,
       int is,int ie,vector<int>& postorder,int ps,int pe, map<int,int>&m){
         if(ps>pe|| is>ie) return NULL;
          TreeNode* root=new TreeNode(postorder[pe]);
          int ir=m[root->val];
          int nl=ir-is;
          root->left=f(inorder,is,ir-1,postorder,ps,ps+nl-1,m);
           root->right=f(inorder,ir+1,ie,postorder,ps+nl,pe-1,m);
           return root;
       }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          map<int,int>m;
       for(int i = 0; i < inorder.size(); i++){
    m[inorder[i]] = i;
}
return f(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,m);
    }
};