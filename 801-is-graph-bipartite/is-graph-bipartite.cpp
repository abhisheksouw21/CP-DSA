class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // graph with linear structur it bipartite
        // graph with even circle
        int V=graph.size();
        int color[V];
        for(int i=0;i<V;++i) color[i]=-1;
        
        for(int i=0; i<V; ++i) {
            // Only start a new BFS if the node hasn't been colored yet
            if(color[i] == -1) {
                queue<int>q;
                q.push(i);
                color[i]=0;
                
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it : graph[node]){
                        if(color[it]==-1){
                            color[it]= !color[node];
                            q.push(it);
                        }
                        else if(color[it] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }  
        return true;
    }
};