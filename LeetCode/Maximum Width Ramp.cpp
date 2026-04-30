class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int>r(n);
        r[n-1]=nums[n-1];
        for(int i=n-2;i>=0;--i){
            r[i]=max(r[i+1],nums[i]);
        }
        int l=0,rt=0;
        int ans=0;
        while(rt<n){
            while(l<rt && nums[l] > r[rt]){
                l++;
            }
         ans=max(ans,rt-l);
         rt++;
        }
      return ans;
    }
};