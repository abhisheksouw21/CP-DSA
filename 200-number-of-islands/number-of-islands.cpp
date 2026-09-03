class Solution {
    private:
    void bfs(int r,int c,  vector<vector<int>> &vis, vector<vector<char>>& grid){
        vis[r][c]=1;
        queue<pair<int,int>>q;
        q.push({r,c});
        while(!q.empty()){
            int r= q.front().first;
             int c= q.front().second;
             q.pop();
             // traverse in the neighbours
             int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

for(int k = 0; k < 4; k++) {
    int a = r + dr[k];
    int b = c + dc[k];
    
    // Fixed column boundary check: grid[0].size()
    if(a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size() && grid[a][b] == '1' && !vis[a][b]) {
        vis[a][b] = 1;
        q.push({a, b});
    }
             }
             }
        }
    
public:
    int numIslands(vector<vector<char>>& grid) {
         int n=grid.size();
         int m= grid[0].size();
         vector<vector<int>> vis(n,vector<int>(m,0));
         int cnt=0;
         for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
               if(!vis[i][j] && grid[i][j]=='1'){
                cnt++;
                bfs(i,j,vis,grid);
               }
            }
         }
         return cnt;
    }
};