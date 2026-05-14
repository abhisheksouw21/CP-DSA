class Solution {
public:
    int memo[101];
    int robfrom(int i,vector<int>& nums){
        if (i >= nums.size()) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
         int ans= max(robfrom(i+1,nums) , robfrom(i+2,nums)+nums[i] );
         return memo[i]=ans;
    }
    int rob(vector<int>& nums) {
        for (int i = 0; i < 101; i++) memo[i] = -1;
        return robfrom(0,nums);
    }
};