class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int a=1,b=1;
      int ans=INT_MIN;
      for(int i=0;i<nums.size();++i){
        if(a==0)a=1;
        if(b==0)b=1;
        a*=nums[i];
        b*=nums[nums.size()-1-i];
        ans=max(ans,max(a,b));
      }  
      return ans;
    }
};