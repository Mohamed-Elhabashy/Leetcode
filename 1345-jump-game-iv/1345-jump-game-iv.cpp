class Solution {
public:
    int dis[50002],OO = 0x3f3f3f3f;
    map<int,vector<int>>mp;
    int minJumps(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        return bfs(0,arr);
    }
    int bfs(int src,vector<int>& arr){
        memset(dis,OO,sizeof dis);
        dis[src]=0;
        queue<int>q;
        q.push(src);
        int target=arr.size()-1;
        while(q.size()){
            int u=q.front();
            q.pop();
            for(auto m:mp[arr[u]]){
                if(dis[u]+1<dis[m]){
                    dis[m]=dis[u]+1;
                    q.push(m);
                }
            }
            if(u+1<arr.size() && dis[u]+1<dis[u+1]){
                dis[u+1]=dis[u]+1;
                q.push(u+1);
            }
            if(u-1>=0 && dis[u]+1<dis[u-1]){
                dis[u-1]=dis[u]+1;
                q.push(u-1);
            }
            mp[arr[u]].clear();
        }
        return dis[target];
    }
};