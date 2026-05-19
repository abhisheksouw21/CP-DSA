class Solution {
public:
     vector<vector<int>>ans;
     void solve(vector<int>&ip,vector<int>op,int i,int target){
        if(target==0){
            ans.push_back(op);
            return;
        }
        if(target<0 || i==ip.size()){
            return;
        }
        if(ip[i]<=target){
            op.push_back(ip[i]);
            solve(ip,op,i,target-ip[i]);
            op.pop_back();
        }
        solve(ip,op,i+1,target);
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>op;
        solve(candidates,op,0,target);
        return ans;
    }
};