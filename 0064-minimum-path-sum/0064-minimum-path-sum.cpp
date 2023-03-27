class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        return solve(0,0,grid);
    }
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i==n-1 && j==m-1)return grid[i][j];
        int& ret=dp[i][j];
        if(~ret)return ret;
        ret=1e9;
        if(j+1<m)ret=min(ret,grid[i][j]+solve(i,j+1,grid));
        if(i+1<n)ret=min(ret,grid[i][j]+solve(i+1,j,grid));
        return ret;
    }
};