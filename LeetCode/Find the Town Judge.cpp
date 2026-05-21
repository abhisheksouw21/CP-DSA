class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       vector<int> trustScore(n + 1, 0);
        
        for (int i = 0; i < trust.size(); i++) {
            trustScore[trust[i][0]]--; 
            trustScore[trust[i][1]]++; 
        }
        
        int ans = -1; 
        
        
        for (int i = 1; i <= n; i++) {
            if (trustScore[i] == n - 1) {
                ans = i;
                break;
            }
        }
        
        return ans; 
    }
};