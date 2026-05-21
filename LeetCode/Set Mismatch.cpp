class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int d=-1,n=nums.size();
        for(int i=0;i<n;++i){
            int idx = abs(nums[i])-1;
            if(nums[idx]<0) d=abs(nums[i]);
            else{
                nums[idx]*=-1;
            }
        }
        int m=-1;
        for(int i=0;i<n;++i){
            if(nums[i]>0){
              m=i+1;
              break; 
            }
        }
        return {d,m};
    }
};