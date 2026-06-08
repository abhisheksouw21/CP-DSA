class Solution {
    
    int atMost(const vector<int>& nums, int k) {
        int left = 0;
        int oddCount = 0;
        int result = 0;
        
        for (int right = 0; right < nums.size(); ++right){
            if (nums[right] % 2 != 0) {
                oddCount++;
            }
            
            while (oddCount > k) {
                if (nums[left] % 2 != 0) {
                    oddCount--;
                }
                left++;
            }
            
          
            result += right - left + 1;
        }

        return result;
}


public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};