class Solution {

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int a= cost[0];
        int b=cost[1];
        if(n<=2) return min(a,b);
        for(int i=2;i<n;++i){
            int temp= cost[i]+min(a,b);
            a=b;
            b=temp;
        }
        return min(a,b);
    }
};