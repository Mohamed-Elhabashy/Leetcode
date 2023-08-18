class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<int,int>adj;
        map<pair<int,int>,bool>mp;
        for(auto v:roads){
            mp[{min(v[0],v[1]),max(v[0],v[1])}]=1;
            adj[v[0]]++;
            adj[v[1]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sz=adj[i]+adj[j];
                if(mp[{i,j}]==1)sz--;
                ans=max(ans,sz);
            }
        }
        return ans;
    }
};