class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> cost(n,vector<int>(m,0));
        cost[0][0] = grid[0][0];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                                if(i == 0 && j == 0) continue;

                int a = (i>0) ? cost[i-1][j] : INT_MAX;
               int b = (j>0) ? cost[i][j-1] : INT_MAX;
               cost[i][j]= min(a,b) + grid[i][j];
            }
        }
        return cost[n-1][m-1];
    }
};