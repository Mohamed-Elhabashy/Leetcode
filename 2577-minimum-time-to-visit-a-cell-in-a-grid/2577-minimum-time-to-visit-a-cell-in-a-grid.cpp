class Solution {
public:
    int a[4]={1,-1,0,0};
    int b[4]={0,0,-1,1};
    int n,m;
    bool vaild(int i,int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1]>1 && grid[1][0]>1)return -1;
        n=grid.size(),m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{0,0}});
        while(pq.size()){
            int time=-pq.top().first,i=pq.top().second.first,j=pq.top().second.second;
            pq.pop();
            if(dis[i][j]<time)continue;
            for(int x=0;x<4;x++){
                int ii=i+a[x];
                int jj=j+b[x];
                if(!vaild(ii,jj) || dis[ii][jj]!=1e9)continue;
                if(grid[ii][jj]<=time+1){
                    dis[ii][jj]=time+1;
                    pq.push({-(time+1),{ii,jj}});
                }
                else{
                    int newtime=(grid[ii][jj]%2 == time%2)?grid[ii][jj]+1:grid[ii][jj];
                    dis[ii][jj]=newtime;
                    pq.push({-newtime,{ii,jj}});
                }
            }
        }
        return dis[n-1][m-1];
        
    }
};