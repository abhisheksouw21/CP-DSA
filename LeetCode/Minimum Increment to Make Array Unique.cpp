class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int ans=0;
       for(int i=1;i<nums.size();++i){
        if(nums[i] <= nums[i-1]){
                int needed = nums[i-1] + 1;
                ans += (needed - nums[i]);
                nums[i] = needed;
            }
       }
       return ans; 
    }
};