class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>vis(n+1);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0],v=roads[i][1],c=roads[i][2];
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }
        int ans=INT_MAX;
        dfs(1,adj,vis,ans);
        return ans;
    }
    void dfs(int u,vector<vector<pair<int,int>>>&adj,vector<int>&vis,int& ans){
        vis[u]=1;
        for(auto v:adj[u]){
            ans=min(ans,v.second);
            if(vis[v.first])continue;
            dfs(v.first,adj,vis,ans);
        }
    }
};