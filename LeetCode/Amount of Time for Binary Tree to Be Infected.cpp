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
      int timef(map<TreeNode*, TreeNode*>& m, TreeNode* target){
            queue<TreeNode*>q;
            q.push(target);
             map<TreeNode*,int>v;
             v[target]=1;
             int maxi=0;
          while(!q.empty()){
int sz = q.size();
            int f=0;
            for(int i=0;i<sz;++i){
                auto node= q.front();
                q.pop();
                if(node->left && !v[node->left] ){
                    f=1;
                    v[node->left]=1;
                    q.push(node->left);
                }
                if(node->right && !v[node->right] ){
                    f=1;
                    v[node->right]=1;
                    q.push(node->right);
                }
                if(m[node] && !v[m[node]]){
                    f=1;
                    v[m[node]]=1;
                    q.push(m[node]);
                }


            }
            if(f)maxi++;
          }
          return maxi;
      }
    TreeNode* bfs(TreeNode* root, map<TreeNode*,TreeNode*>&m, int start){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node=q.front();
            if(node->val==start) res=node;
            q.pop();
            if(node->left){
                m[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                m[node->right]=node;
                q.push(node->right);
            }

        }
        return res;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>m;
        TreeNode* target= bfs(root,m,start);
        int ans=timef(m,target);
        return ans;

    }
};