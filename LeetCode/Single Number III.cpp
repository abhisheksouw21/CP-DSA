class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int q = 0;
        for(int i : nums){
            q ^= i;
        }

long long x = q & (- (long long)q);
        int a = 0, b = 0;
        for(int i : nums){
            if(i & x) a ^= i;
            else b ^= i;
        }

        return {a, b};
    }
};