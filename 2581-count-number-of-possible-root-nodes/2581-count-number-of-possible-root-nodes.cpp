class Solution {
public:
    map<pair<int,int>,int>mp;
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int CorrectGuess=0;
        int n=edges.size()+1;
        for(auto edge:guesses)
            mp[{edge[0],edge[1]}]=1;
        
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>par(n,-1);
        dfs1(0,-1,adj,par);
        for(int i=0;i<n;i++){
            if(mp.count({par[i],i}))CorrectGuess++;
        }
        int ans=CorrectGuess>=k;
        for(auto v:adj[0])
            dfs2(v,0,adj,CorrectGuess,ans,k);
        return ans;
    }
    void dfs1(int u,int p,vector<vector<int>>&adj,vector<int>&par){
        for(auto v:adj[u]){
            if(v==p)continue;
            par[v]=u;
            dfs1(v,u,adj,par);
        }
    }
    void dfs2(int u,int p,vector<vector<int>>&adj,int CorrectGuess,int& ans,int k){
        if(mp.count({u,p}))CorrectGuess++;
        if(mp.count({p,u}))CorrectGuess--;
        if(CorrectGuess>=k)
            ans++;
        
        for(auto v:adj[u]){
            if(v==p)continue;
            dfs2(v,u,adj,CorrectGuess,ans,k);
        }
    }
};