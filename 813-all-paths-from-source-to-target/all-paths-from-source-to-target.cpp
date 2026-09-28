class Solution {
  void dfs(vector<vector<int>>& graph,int node, vector<int>&p,vector<vector<int>>&r){
        int a=graph.size()-1;
        if(node==a){
            r.push_back(p);
            return;
        }
        for( auto i : graph[node]){
            p.push_back(i);
             dfs(graph,i,p,r);
             p.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>r;
        vector<int>p;
        p.push_back(0);
        dfs(graph,0,p,r);
       return r;
    }
};