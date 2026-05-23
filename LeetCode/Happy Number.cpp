class Solution {
public:
    int next(int n){
       int ans=0;
       while(n>0){
        int d=n%10;
        n=n/10;
        ans+=d*d;
       }
       return ans;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=next(n);
        while(fast!=1 && fast != slow){
            slow=next(slow);
            fast=next(next(fast));
        }
      return fast==1;
    }
};