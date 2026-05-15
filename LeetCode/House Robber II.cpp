class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        
        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }

private:
    int solve(vector<int>& nums, int start, int end) {
        if (start > end) return 0;
        if (start == end) return nums[start];

        int prev_profit = nums[start];
        int current_max = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; ++i) {
            int new_profit = nums[i] + prev_profit;
            
           
            int temp = current_max;
            current_max = max(current_max, new_profit);
            prev_profit = temp;
        }

        return current_max;
    }
};