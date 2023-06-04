class Solution {
public:
    int n;
    bool vis[201];
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,isConnected);
                ans++;
            }
        }
        return ans;
    }
    void dfs(int u,vector<vector<int>>& isConnected){
        vis[u]=1;
        for(int i=0;i<n;i++){
            if(isConnected[u][i] && !vis[i])dfs(i,isConnected);
        }
    }
};