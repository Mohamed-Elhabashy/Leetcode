class Solution {
public:
    vector<pair<int,double>>adj[10000+2];
    double probability[10002];
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            double c=succProb[i];
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }
        probability[start]=1.0;
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start});
        while(pq.size()){
            auto x=pq.top();
            pq.pop();
            
            if(x.second==end)return probability[end];
            for(auto v:adj[x.second]){
                if(v.second*x.first>probability[v.first]){
                    probability[v.first]=v.second*x.first;
                    pq.push({v.second*x.first,v.first});
                }
            }
        }
        return 0.0;
    }
    
};