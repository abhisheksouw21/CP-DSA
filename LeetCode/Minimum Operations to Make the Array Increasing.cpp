class Solution {
public:
    int minOperations(vector<int>& nums) {
       int ans=0;
       for(int i=1;i<nums.size();++i){
        if(nums[i] <= nums[i-1]) {
        int temp = nums[i-1]+1;
        ans+=(temp-nums[i]);
        nums[i]=temp;
        }
       }
       return ans; 
    }
};