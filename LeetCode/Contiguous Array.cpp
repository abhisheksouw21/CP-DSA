class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>h;
        h[0]=-1;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();++i){
            sum+= nums[i]==1 ? 1: -1;
            if(h.find(sum)!=h.end()){
                ans=max(ans,i-h[sum]);
            }
            else{
                h[sum]=i;
            }
        }
        return ans;
    }
};