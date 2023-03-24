class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,bool>>>adj(n);
        for(auto edge:connections){
            adj[edge[0]].push_back({edge[1],1});
            adj[edge[1]].push_back({edge[0],0});
        }
        int ans=0;
        dfs(0,-1,adj,ans);
        return ans;
    }
    void dfs(int u,int p,vector<vector<pair<int,bool>>>&adj,int& ans){
        for(auto v:adj[u]){
            if(v.first==p)continue;
            ans+=v.second;
            dfs(v.first,u,adj,ans);
        }
    }
};