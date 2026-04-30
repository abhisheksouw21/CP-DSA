class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
         vector<int>v(100,0);
         for(int i=0;i<dominoes.size();++i){
               int a= max(dominoes[i][0],dominoes[i][1]);
               int b= min(dominoes[i][0],dominoes[i][1]);
               int num = b*10+a;
               v[num]++;
         }  
         int ans=0;
         for(int i=0;i<100;++i){
             int temp= v[i]*(v[i]-1);
             temp = temp/2;
             ans+=temp;
         }
         return ans;
    }
};