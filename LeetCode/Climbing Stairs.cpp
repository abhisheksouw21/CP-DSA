class Solution {
public:
    int climbStairs(int n) {
         double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;
    return round((pow(phi, n+1) - pow(psi, n+1)) / sqrt(5));
    }
};