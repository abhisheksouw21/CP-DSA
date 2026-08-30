class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        // approch kuch nahi he isme
       int mx=INT_MIN;
       int n=nums.size();
       int a=0;
       int b=0;
       int mn=INT_MAX;
        for(int i=0;i<nums.size();++i){
            if(nums[i]<mn){
               mn=nums[i];
               b=i;
            }
            if(nums[i]>mx){
               mx=nums[i];
               a=i;
            }
        }
        
        if(a>b) swap(a,b);
        int x= b+1;
        int y=n-1-a+1;
        int z=a+1+n-1-b+1; 
        return min(x,min(y,z));
    }
};