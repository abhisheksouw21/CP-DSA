class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> m;
        int l=0,mx=0;
        for(int r=0;r<fruits.size();++r){
            m[fruits[r]]++;
            while(m.size()>2){
                 m[fruits[l]]--;
            if( m[fruits[l]]==0){
                m.erase(fruits[l]);
            }
            l++;
            }
            mx=max(mx,r-l+1);
        }
     return mx;
    }
};