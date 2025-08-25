#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void findSubsetSums(const vector<int>& arr, int index, long long currentSum, vector<long long>& sums) {
    if (index == arr.size()) {
        sums.push_back(currentSum);
        return;
    }
    findSubsetSums(arr, index + 1, currentSum, sums);
    findSubsetSums(arr, index + 1, currentSum + arr[index], sums);
}

int maximizeCPU(vector<int> requirements, int processingCapacity) {
    int n = requirements.size();
    if (n == 0) {
        return 0;
    }

    vector<int> first_half(requirements.begin(), requirements.begin() + n / 2);
    vector<int> second_half(requirements.begin() + n / 2, requirements.end());

    vector<long long> sums1, sums2;
    findSubsetSums(first_half, 0, 0, sums1);
    findSubsetSums(second_half, 0, 0, sums2);

    sort(sums2.begin(), sums2.end());

    long long max_sum = 0;
    for (long long s1 : sums1) {
        if (s1 <= processingCapacity) {
            long long remaining_capacity = processingCapacity - s1;
            
            auto it = upper_bound(sums2.begin(), sums2.end(), remaining_capacity);
            
            if (it != sums2.begin()) {
                long long s2 = *(--it);
                max_sum = max(max_sum, s1 + s2);
            }
        }
    }

    return static_cast<int>(max_sum);
}