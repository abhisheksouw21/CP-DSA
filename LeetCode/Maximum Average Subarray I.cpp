class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int sum=0;
        double ans=INT_MIN;
        while(j<nums.size()){
            sum+=nums[j];
            if(j-i+1<k){
               j++;
            }
            else{
              ans = max(ans, (double)sum / k);
                sum-=nums[i];
                i++;
                j++;    
            }
        }
        return ans;
    }
};