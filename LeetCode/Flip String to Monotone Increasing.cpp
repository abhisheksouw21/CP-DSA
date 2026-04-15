class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans=0;
        int c1=0;
        for(auto i : s){
            if(i=='0'){
                ans=min(ans+1,c1);
            }
            else{
                ++c1;
            }
        }
        return ans;
    }
};