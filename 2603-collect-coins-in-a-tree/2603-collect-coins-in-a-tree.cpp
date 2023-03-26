class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n=coins.size(),TotalEdges=2*edges.size(),del=0;
        set<int>adj[n];
        for(int i=0;i<n-1;i++){
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(adj[i].size()==1 && !coins[i])q.push(i);
        }
        while(q.size()){
            int u=q.front();
            q.pop();
            if(adj[u].size()==0)continue;
            int par=*adj[u].begin();
            adj[u].erase(adj[u].begin());
            adj[par].erase(adj[par].find(u));
            del+=2;
            if(adj[par].size()==1 && !coins[par])q.push(par);
        }
        for(int i=0;i<n;i++){
            if(adj[i].size()==1)q.push(i);
        }
        for(int i=1;i<=2;i++){
            int sz=q.size();
            while(sz--){
                int u=q.front();
                q.pop();
                if(adj[u].size()==0)continue;
                int par=*adj[u].begin();
                adj[u].erase(adj[u].begin());
                adj[par].erase(adj[par].find(u));
                del+=2;
                if(adj[par].size()==1)q.push(par);
            }
        }
        return TotalEdges-del;
    }
};