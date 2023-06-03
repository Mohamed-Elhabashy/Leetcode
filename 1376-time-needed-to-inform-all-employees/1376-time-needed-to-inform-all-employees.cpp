class Solution {
public:
    vector<int>adj[100001];
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i=0;i<n;i++){
            if(i==headID)continue;
            adj[manager[i]].push_back(i);
        }
        return dfs(headID, informTime);
    }
    int dfs(int u,vector<int>& informTime){
        int mx=0;
        for(auto v:adj[u]){
            mx=max(mx,informTime[u]+dfs(v,informTime));
            
        }
        return mx;
    }
};