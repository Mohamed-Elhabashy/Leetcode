class Solution {
public:
    int a[8]={1,-1,0,0,1,-1,-1,1};
    int b[8]={0,0,1,-1,1,-1,1,-1};
    bool vaild(int i,int j,vector<vector<int>>&grid){
        return i>=0 && i<grid.size() && j>=0 && j<grid.size() && grid[i][j]==0 ;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0])return -1;
        return bfs(grid);
    }
    int bfs(vector<vector<int>>& grid)
    {
        int n=grid.size();
        vector<vector<int>>dis(n,vector<int>(n,-1));
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        dis[0][0]=1;
        while(q.size()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int distance=q.front().second;
            q.pop();
            for(int x=0;x<8;x++){
                int newi=a[x]+i;
                int newj=b[x]+j;
                if(vaild(newi,newj,grid) && dis[newi][newj]==-1){
                    q.push({{newi,newj},distance+1});
                    dis[newi][newj]=distance+1;
                }
            }
        }
        return dis[n-1][n-1];
    }
};