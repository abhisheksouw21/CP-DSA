class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int c = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != 1e9){
                int s = i, t = 0;
                
                while(nums[s] != 1e9){
                    int temp = s;
                    s = nums[s];
                    nums[temp] = 1e9;  
                    t++;
                }
                
                c = max(c, t);
            }
        }
        
        return c;
    }
};