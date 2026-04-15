class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int t1=0;
        int t2=0;
        int mx = nums[0];
        int mn= nums[0];
        int sum=0;
        for(auto i : nums){
            t1= max(t1,0) + i;
            mx = max(mx,t1);

            t2=min(t2,0)+i;
            mn=min(mn,t2);
            sum+=i;
        }
        if(sum==mn) return mx;
        return max(mx,sum-mn);
    }
};