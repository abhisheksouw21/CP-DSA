class Solution {
public:
    void f(int s,int k,int t,vector<int>&c,vector<vector<int>>& r){
        if(t==0 && c.size()==k ){
            r.push_back(c);
            return;
        }
        if(c.size()==k || t<0){
            return;
        }
        for(int i=s;i<=9;++i){
            c.push_back(i);
            f(i+1,k,t-i,c,r);
            c.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>c;
        vector<vector<int>> r;
        f(1,k,n,c,r);
        return r;
    }
};