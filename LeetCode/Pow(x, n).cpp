class Solution {
public:
    double f(double x, long long n) {
        if (n == 0) return 1.0;
        
        double ans = f(x, n / 2);
        
        if (n % 2 == 0) {
            return ans * ans;
        } else {
            return ans * ans * x;
        }
    }
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1.0 / x;
            N = -N;     
        }
        double a = f(x,n);
        return a;
   }
};