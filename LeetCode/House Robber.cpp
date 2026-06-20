class Solution {
    vector<int> dp;

    int robFrom(int i, vector<int>& nums) {
        if (i >= nums.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int ans = max(
            robFrom(i + 1, nums),
            robFrom(i + 2, nums) + nums[i]
        );

        dp[i] = ans;
        return ans;
    }

public:
    int rob(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return robFrom(0, nums);
    }
};