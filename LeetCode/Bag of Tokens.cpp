class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i=0;
        int j=tokens.size()-1;
        int ans=0;
        sort(tokens.begin(),tokens.end());
        while(i<=j){
            if(power>=tokens[i]){
                ans++;
                power-=tokens[i];
                i++;
            }
            else if(i<j && ans>0){
                ans--;
                power+=tokens[j];
                 j--;
            }
            else{
                return ans;
            }
        }
     return ans;
    }
};