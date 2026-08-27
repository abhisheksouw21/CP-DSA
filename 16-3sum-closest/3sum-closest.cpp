class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());

         int n = arr.size();
       int closestSum = arr[0] + arr[1] + arr[2];


        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
               if (abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                }
                
                 if (sum < target) left++;
                else if(target<sum) right--;
                else return sum;
            }
        }
       return closestSum;
    }
};