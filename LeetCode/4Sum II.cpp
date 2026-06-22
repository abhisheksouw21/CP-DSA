class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans=0;
        unordered_map<int,int>m;
         for(int a : nums1){
            for(int b:nums2){
                m[a+b]++;
            }
         }
         for(int c : nums3){
            for(int d :nums4){
               auto it = m.find(-(c+d));
               if(it!=m.end()){
                ans+=it->second;
               }
            }
         }
         return ans;
    }
};