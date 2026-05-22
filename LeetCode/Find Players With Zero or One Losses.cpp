class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
          vector<int>v(100001, -1);
          for(auto i : matches){
            int a=i[0];
            int b=i[1];
            if(v[a]==-1){
                v[a]=0;
            }
             if(v[b]==-1){
                v[b]=1;
            }
             else{
                v[b]++;
             }
          }
         vector<vector<int>> ans(2,vector<int>());
         for(int i=0;i<100001;++i){
            if(v[i]==0){
                ans[0].push_back(i);
            }
            if(v[i]==1){
                ans[1].push_back(i);
            }
         }
         return ans;
    }
};