class Solution {
public:
    vector<int>adj[100002];
    vector<int>vis,stack;
    vector<vector<int>>dp;
    bool cycle=0;
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vis.resize(n);stack.resize(n);
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
    void dfs(int u,string& colors){
        vis[u]=1;
        stack[u]=1;
        vector<int>tmp(26);
        for(auto v:adj[u]){
            if(vis[v]){
                if(stack[v])
                    cycle=1;
                for(int i=0;i<26;i++)
                    tmp[i]=max(tmp[i],dp[v][i]);
                continue;
            }
            dfs(v,colors);
            for(int i=0;i<26;i++)
                tmp[i]=max(tmp[i],dp[v][i]);
        }
        tmp[colors[u]-'a']++;
        stack[u]=0;
        dp[u]=tmp;
    }
};