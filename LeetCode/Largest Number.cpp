class Solution {
public:
    static bool f(int n1, int n2) {
        string a = to_string(n1);
        string b = to_string(n2);
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), f);

       
        if (nums[0] == 0) return "0";

        string ans = "";

        for (int i : nums) {
            ans += to_string(i);
        }

        return ans;
    }
};