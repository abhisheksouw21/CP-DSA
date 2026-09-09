class Solution {
public:
    long long countCommas(long long n) {
        
        long long acc = 0;
        long long i;
        int commas = 0;
        for(i = 1000; i <= n; i*=1000){
            acc += (i-i/1000)*(commas++);
        }
        i/=1000;
        acc += (n-i+1)*(commas);
        return acc;
    }
};