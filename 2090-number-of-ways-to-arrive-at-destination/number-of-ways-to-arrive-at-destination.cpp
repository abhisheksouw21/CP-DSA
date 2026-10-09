class Solution {
    vector<vector<pair<int, int>>> constructadj(int V, vector<vector<int>>& edges){
        vector<vector<pair<int, int>>> adj(V);

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        return adj;
    }
public:
    int countPaths(int V, vector<vector<int>>& roads) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

      vector<vector<pair<int, int>>> adj= constructadj(V, roads);
   vector<long long> dist(V, 1e18); 
        vector<long long> ways(V, 0);
        int mod = 1e9 + 7;
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
       
           while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (dis > dist[node]) continue;
            
            for(auto it: adj[node]){
                int adjNode = it.first;
                long long edgeweight = it.second;
                
             
                if(dis + edgeweight < dist[adjNode]){
                    dist[adjNode] = dis + edgeweight;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                
                else if(dis + edgeweight == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        
        return ways[V-1] % mod;
    }
};