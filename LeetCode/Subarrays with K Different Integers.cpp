class Solution {
    int f(vector<int>& nums, int k){
        int l=0,r=0,count=0;
      unordered_map<int,int>m;
       while(r<nums.size()){
        if(m[nums[r]]==0){
            k--;
        }
        m[nums[r]]++;
        while(k<0){
            m[nums[l]]--;
            if(m[nums[l]]==0){
                k++;
            }
            l++;
        }
        count+=r-l+1;
        r++;
       }
       return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};