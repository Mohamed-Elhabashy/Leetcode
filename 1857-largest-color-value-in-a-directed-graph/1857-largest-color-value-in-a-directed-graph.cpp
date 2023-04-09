class Solution {
public:
    vector<vector<int>>adj;
    vector<int>vis,stack;
    vector<vector<int>>dp;
    bool cycle=0;
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vis.resize(n);stack.resize(n);adj.resize(n);
        dp.resize(n,vector<int>(26));
        for(auto edge:edges){
            if(edge[0]==edge[1])return -1;
            adj[edge[0]].push_back(edge[1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(i,colors);
            for(int j=0;j<26;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        
        return cycle?-1:ans;
    }
    void calculate(vector<int>& v1,vector<int>& v2){
        for(int i=0;i<26;i++)
            v1[i]=max(v1[i],v2[i]);
    }
    void dfs(int u,string& colors){
        vis[u]=1;
        stack[u]=1;
        vector<int>tmp(26);
        for(auto v:adj[u]){
            if(vis[v]){
                if(stack[v])
                    cycle=1;
                calculate(dp[u],dp[v]);
                continue;
            }
            dfs(v,colors);
            calculate(dp[u],dp[v]);
        }
        dp[u][colors[u]-'a']++;
        stack[u]=0;
    }
};