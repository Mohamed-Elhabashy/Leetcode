class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int idx=0,n=points.size(),ans=0;
        unordered_map<int,bool>mp;
        vector<int>dis(n,2e9);
        for(int i=1;i<=n-1;i++){
            int mn=INT_MAX,idxMn=-1;
            mp[idx]=1;
            for(int j=0;j<n;j++){
                if(mp[j]==1)continue;
                int d=abs(points[j][0]-points[idx][0])+abs(points[j][1]-points[idx][1]);
                dis[j]=min(dis[j],d);
                if(dis[j]<mn){
                    mn=dis[j];
                    idxMn=j;
                }
            }
            ans+=mn;
            idx=idxMn;
        }
        return ans;
    }
};