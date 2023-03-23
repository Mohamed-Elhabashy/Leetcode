class Solution {
public:
    void dfs(int u,vector<int>&vis,vector<vector<int>>&adj){
        vis[u]=1;
        for(auto v:adj[u]){
            if(!vis[v])dfs(v,vis,adj);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        vector<vector<int>>adj(n);
        vector<int>vis(n);
        for(auto edge:connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                comp++;
            }
        }
        return comp-1;
    }
};