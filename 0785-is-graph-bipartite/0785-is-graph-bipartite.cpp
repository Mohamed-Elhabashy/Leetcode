class Solution {
public:
    bool ans=true;
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n);
        for(int i=0;i<n;i++)
            if(color[i]==0){
                color[i]=1;
                dfs(i,graph,color);
            }
        return ans;
    }
    void dfs(int u,vector<vector<int>>& graph,vector<int>& color){
        for(auto v:graph[u]){
            if(color[v]==color[u])
            {
                ans=false;
                return ;
            }
            if(color[v]!=0)continue;
            (color[u]==1)?color[v]=2:color[v]=1;
            dfs(v,graph,color);
        }
    }
};