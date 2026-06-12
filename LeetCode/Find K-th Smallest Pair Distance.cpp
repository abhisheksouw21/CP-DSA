class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int lt=0;
        int h=nums[n-1]-nums[0];
        while(lt<h){
            int m=lt+(h-lt)/2;
            int cnt=0;
            int l=0;
            for(int r=0;r<n;++r){
                while(nums[r]-nums[l]>m){
                    l++;
                }
                cnt+=r-l;
            }
            if(cnt>=k){
                h=m;
            }
            else{
                lt=m+1;
            }
        }
        return lt;
    }
};