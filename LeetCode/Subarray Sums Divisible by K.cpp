class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> p(n + 1);
        p[0] = 0;

        for (int i = 1; i <= n; ++i) {
            p[i] = p[i - 1] + nums[i - 1];
        }

        map<int, int> m;

        for (int i = 0; i <= n; ++i) {
            int rem = ((p[i] % k) + k) % k;
            m[rem]++;
        }

        int ans = 0;

        for (auto &it : m) {
            int freq = it.second;
            ans += (freq * (freq - 1)) / 2;
        }

        return ans;
    }
};