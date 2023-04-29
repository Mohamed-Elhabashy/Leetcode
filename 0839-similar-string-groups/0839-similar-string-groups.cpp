class Solution {
public:
    vector<int>adj[301];
    bool Check(string& s1,string& s2){
        int n=s1.size(),cnt=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i])cnt++;
        }
        return cnt<=2;
    }
    void dfs(int u,vector<int>& vis){
        vis[u]=1;
        for(auto v:adj[u])
            if(!vis[v])dfs(v,vis);
    }
    int numSimilarGroups(vector<string>& strs) {
        int sz=strs.size();
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                if(Check(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(sz);
        int ans=0;
        for(int i=0;i<sz;i++){
            if(!vis[i]){
                dfs(i,vis);
                ans++;
            }
        }
        return ans;
    }
};