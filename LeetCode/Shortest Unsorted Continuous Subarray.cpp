class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int mn=INT_MAX;
        int mx=INT_MIN;
        bool f=false;
        for(int i=1;i<n;++i){
             if(nums[i]<nums[i-1]) f= true;
             if(f) mn=min(mn,nums[i]);
        }
        f=false;
        for(int i=n-2;i>=0;--i){
             if(nums[i]>nums[i+1])f=true;
              if(f) mx=max(mx,nums[i]); 
        } 
        int l,r;
        for(l=0;l<n;++l){
            if(nums[l]>mn)break;
        } 
       for(r = n - 1; r >= 0; --r){
    if(nums[r] < mx) break;
}
        return r-l<0 ? 0 : r-l+1;
    }
};