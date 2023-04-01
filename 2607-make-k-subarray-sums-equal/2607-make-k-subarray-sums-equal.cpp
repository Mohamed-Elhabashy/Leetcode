class Solution {
public:
    vector<vector<int>>adj;
    vector<int>vis;
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n=arr.size();
        adj.resize(n);
        vis.resize(n);
        for(int i=0;i<n;i++){
            adj[i].push_back((i+k)%n);
            adj[(i+k)%n].push_back(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>tmp;
                dfs(i,tmp,arr);
                sort(tmp.begin(),tmp.end());
                int value=tmp[tmp.size()/2];
                for(auto x:tmp)ans+=abs(value-x);
            }
        }
        return ans;
    }
    void dfs(int u,vector<int>& tmp,vector<int>& arr){
        vis[u]=1;
        tmp.push_back(arr[u]);
        for(auto v:adj[u]){
            if(!vis[v])dfs(v,tmp,arr);
        }
    }
    

};