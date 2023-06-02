class Solution {
public:
    map<pair<int,int>,vector<pair<int,int>>>adj;
    map<pair<int,int>,int>frq;
    int maximumDetonation(vector<vector<int>>& bombs) {
        for(int i=0;i<bombs.size();i++){
            long long x1=bombs[i][0],y1=bombs[i][1],r=(1LL*bombs[i][2]*bombs[i][2]);
            frq[{x1,y1}]++;
            for(int j=0;j<bombs.size();j++){
                if(i==j)continue;
                int x2=bombs[j][0],y2=bombs[j][1];
                long long dis=(1LL*abs(x2-x1)*abs(x2-x1))+(1LL*abs(y2-y1)*abs(y2-y1));
                if(dis<=r)adj[{x1,y1}].push_back({x2,y2});
            }
        }
        int ans=0;
        for(int i=0;i<bombs.size();i++){
            map<pair<int,int>,bool>vis;
            int counter=frq[{bombs[i][0],bombs[i][1]}]-1;
            dfs(bombs[i][0],bombs[i][1],counter,vis);
            ans=max(ans,counter);
        }
        return ans;
    }
    void dfs(int i,int j,int& counter,map<pair<int,int>,bool>& vis){
            vis[{i,j}]=1;
            counter++;
            for(auto x:adj[{i,j}]){
                if(vis[x])continue;
                dfs(x.first,x.second,counter,vis);
            }
        }
};