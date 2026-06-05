class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>v;
        for(int i=0;i<profit.size();++i){
            v.push_back({difficulty[i],profit[i]});
        }
        sort(v.begin(),v.end());
        sort(worker.begin(),worker.end());
        int i=0,j=0;
        int mx=0,ans=0;
        while(i<worker.size()){
           while(j < v.size() && v[j].first <= worker[i]) {
                mx = max(mx, v[j].second); 
                j++;
            }
           
                i++;
                ans+= mx;
            
        }
        return ans;
    }
};