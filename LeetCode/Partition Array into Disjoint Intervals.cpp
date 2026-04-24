class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int mx=nums[0];
        int ans=1;
        int l_mx=nums[0];
        for(int i=1;i<nums.size();++i){
            mx=max(mx,nums[i]);
            if(l_mx>nums[i]){
                ans=i+1;
                l_mx=mx;
            }
        }
        return ans;
    }
};