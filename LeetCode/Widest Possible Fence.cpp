class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int,int>m;
        for(int i : planks){
            m[i]++;
        }
        vector<int>v;
        for(auto i : m){
            v.push_back(i.first);
        }
         unordered_map<int,int>w;
        for(int i : v ){
            w[i]+=m[i];
            w[i+i]+=m[i]/2;
        }
        for(int i=0;i<v.size();++i){
            for(int j=i+1;j<v.size();++j){
                w[v[i]+v[j]]+=min(m[v[i]],m[v[j]]);
            }
        }
        int ans=0;
        for(auto i : w){
            ans=max(ans,i.second);
        }
        return ans;
    }
};