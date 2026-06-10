class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int ans=10;
        int cnt=9;
        int a=9;
        for(int i=2;i<=n && a>0;i++){
            cnt*=a;
            ans+=cnt;
            a--;
        }
        return ans;
    }
};