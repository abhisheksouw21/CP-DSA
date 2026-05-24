class Solution {
public:
    int findNthDigit(int n) {
        long long int l=1;
        long long int cnt=9;
        long long int s=1;
        while(n>l*cnt){
            n-=l*cnt;
            l++;
            cnt*=10;
            s*=10;
        }
       long long int num=s+(n-1)/l;
        string s1= to_string(num);
        return s1[(n-1)%l]-'0';
    }
};