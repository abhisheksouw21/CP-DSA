class Solution {
public:
    int f(int a, int b){
        if(b==0){
            return a;
        }
     return f(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int n=nums.size(),Min=1001,Max=0;
        for(int i=0;i<n;i++){
            Min=min(Min,nums[i]);
            Max=max(Max,nums[i]);
        }
        return f(Max,Min);

    }
};