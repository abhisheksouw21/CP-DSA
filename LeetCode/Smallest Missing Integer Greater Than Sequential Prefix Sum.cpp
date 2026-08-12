class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int a=nums[0];
      
        for(int i=1;i<nums.size();++i){
            if(nums[i]==nums[i-1]+1){
                a+=nums[i];
            }
            else{
                break;
            }
        }
        unordered_set<int> st(nums.begin(), nums.end());
     while(st.count(a)) a++;
     return a;
    }
};