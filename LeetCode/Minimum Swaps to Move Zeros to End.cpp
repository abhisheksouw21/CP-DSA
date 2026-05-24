class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n= nums.size()-count(nums.begin(),nums.end(),0);
        return count(nums.begin(),nums.begin()+n,0);
    }
};