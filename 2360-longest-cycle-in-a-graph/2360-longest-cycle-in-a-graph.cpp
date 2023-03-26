class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>vis(n);
        int ans=-1;
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            vector<int>nodes;
            dfs(i,edges,vis,nodes,ans);
        }
        return ans;
    }
    void dfs(int u,vector<int>&edges,vector<int>&vis,vector<int>&node,int& ans){
        if(u==-1)return;
        if(vis[u]){
            int index=-1;
            for(int i=0;i<node.size();i++){
                if(node[i]==u){
                    index=i;
                    break;
                }
            }
            if(index==-1)return ;
            ans=max(ans,(int)node.size()-index);
            return ;
        }
        vis[u]=1;
        node.push_back(u);
        dfs(edges[u],edges,vis,node,ans);
        
    }
};