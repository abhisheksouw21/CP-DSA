class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> s(nums.begin(), nums.end());
        int ans=0;
        for(int i : s){
            if(s.find(i-1)==s.end()){
                int x=i;
                int c=1;
                while(s.find(x+1)!=s.end()){
                    x++;
                    c++;
                }
                ans=max(ans,c);
            }
        }
        return ans;
    }
};