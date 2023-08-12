class Solution {
public:
    int dp[101][101],n,m;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof dp);
        n=obstacleGrid.size(),m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;
        return solve(0,0,obstacleGrid);
    }
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i==n-1 && j==m-1)return 1;
        int& ret=dp[i][j];
        if(~ret)return ret;
        ret=0;
        if(j+1<m && grid[i][j+1]==0)
            ret+=solve(i,j+1,grid);
        if(i+1<n && grid[i+1][j]==0)
            ret+=solve(i+1,j,grid);
        return ret;
    }
};