class Solution {
public:
    vector<int>adj[5001];
    bool vis[2001],nodes[2001];
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto edge:prerequisites)
            adj[edge[1]].push_back(edge[0]);
        for(int i=0;i<numCourses;i++){
            if(!vis[i] && detectcycle(i))
                return 0;
        }
        return 1;
    }
    bool detectcycle(int u){
        vis[u]=1;
        nodes[u]=1;
        for(auto v:adj[u]){
            if(!vis[v] && detectcycle(v))return 1;
            else if(nodes[v])return 1;
        }
        nodes[u]=0;
        return 0;
    }
};