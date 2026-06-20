class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s=INT_MIN;
        int h= INT_MIN;
        int r=0;
        for(int i:prices){
            int t=s;
            s=i+h;
            h=max(h,r-i);
            r=max(r,t);
        }
        return max(r,s);
    }
};