class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        
        map<int,int>m;
        long long int ans=0;
        for(int i=0;i<hours.size();++i){
          int mod = hours[i] % 24;     
            int r = (24 - mod) % 24;
         
            if(m.find(r)!=m.end()){
                ans+=m[r];
            }
            m[mod]++;
        }
        return ans;
    }
};