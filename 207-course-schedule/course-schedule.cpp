class Solution {
    vector<vector<int>> constructadj(int V, vector<vector<int>>& edges) {
                vector<vector<int>> adj(V);
                for (auto it : edges) {
                    adj[it[0]].push_back(it[1]); 
                }
                return adj;
                  }
  public:
    bool canFinish(int n, vector<vector<int>>& pre) {
         vector<vector<int>> adj = constructadj(n, pre);
         vector<int> indegree(n, 0);
             queue<int> q;
             vector<int> list;
         for (int i = 0; i < n; i++) {
                for (int next : adj[i])
                    indegree[next]++;
            }

            
            for (int i = 0; i < n; i++)
                if (indegree[i] == 0)
                    q.push(i);

           
            while (!q.empty()) {
                int top = q.front();
                q.pop();
                list.push_back(top);
                for (int next : adj[top]) {
                    indegree[next]--;
                    if (indegree[next] == 0)
                        q.push(next);
                }
            }
         return list.size()==n;
        
    }
};