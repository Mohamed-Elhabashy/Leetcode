class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>vis(n);
        int numberOfNode=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int CountNode=0;
                dfs(i,adj,vis,CountNode);
                ans+=(1LL*numberOfNode*CountNode);
                numberOfNode+=CountNode;
            }
        }
        return ans;
    }
    void dfs(int u,vector<vector<int>>&adj,vector<int>&vis,int& CountNode){
        vis[u]=1;
        CountNode++;
        for(auto v:adj[u]){
            if(!vis[v])
                dfs(v,adj,vis,CountNode);
        }
    }
};
        