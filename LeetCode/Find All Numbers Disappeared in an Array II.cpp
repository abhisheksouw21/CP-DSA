class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
       sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        if(nums[0]>lower){
         ans.push_back({lower, min(upper, nums[0]-1)});
        }
        
        for(int i=1;i<n;++i){
            if(nums[i-1]==nums[i]) continue;
            int start = max(lower, nums[i-1] + 1);
            int end = min(upper, nums[i] - 1);
            
            if(start <= end){
                ans.push_back({start, end});
            }
             if(nums[i]>upper){
            break;
        }
        }
         int last_val = max(lower - 1, nums[n-1]);
        if(last_val < upper){
             ans.push_back({last_val + 1, upper});
        }
       
        return ans;
    }
};