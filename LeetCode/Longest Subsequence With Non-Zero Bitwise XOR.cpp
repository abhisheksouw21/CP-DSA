class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x=0;
        bool f=false;
        for(int i : nums){
            x^=i;
            if(x!=0){
                f=true;
            }
        }
        if(x!=0) return nums.size();
        if(f) return nums.size()-1;
        return 0;
    }
};