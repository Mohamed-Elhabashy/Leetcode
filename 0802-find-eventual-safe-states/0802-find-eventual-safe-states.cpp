class Solution {
public:
    bool dp[10004],vis[10004];
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        for(int i=0;i<graph.size();i++){
            if(!vis[i])dfs(i,graph);
            if(dp[i])ans.push_back(i);
        }
        return ans;
    }
    void dfs(int u,vector<vector<int>>& graph){
        if(graph[u].size()==0){
            dp[u]=1;
            return ;
        }
        vis[u]=1;
        bool flag=1;
        for(auto v:graph[u]){
            if(vis[v]){
                flag&=dp[v];
                continue;
            }
            dfs(v,graph);
            flag&=dp[v];
        }
        dp[u]=flag;
    }
};