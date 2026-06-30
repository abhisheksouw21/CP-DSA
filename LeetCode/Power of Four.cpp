class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n>0) && (fmod(log(n)/log(2),2)==0);
    }
};