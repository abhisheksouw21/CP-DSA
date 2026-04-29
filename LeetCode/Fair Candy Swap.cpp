#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int n = aliceSizes.size();
        int m = bobSizes.size();

        int sum1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sum2 = accumulate(bobSizes.begin(), bobSizes.end(), 0);

        int diff = (sum1 - sum2) / 2;

        sort(aliceSizes.begin(), aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());

        int i = 0, j = 0;

        while (i < n && j < m) {
            int curr = aliceSizes[i] - bobSizes[j];

            if (curr == diff) {
                return {aliceSizes[i], bobSizes[j]};
            }
            else if (curr < diff) {
                i++;
            }
            else {
                j++;
            }
        }

        return {};
    }
};