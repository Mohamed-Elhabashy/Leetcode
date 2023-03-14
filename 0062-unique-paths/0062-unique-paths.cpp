class Solution {
public:
    int solve(int r,int c,vector<vector<int>>& dp,int m,int n){
        if(r==m && c==n)return 1;
        int& ret=dp[r][c];
        if(~ret)return ret;
        ret=0;
        if(r+1<=m)ret+=solve(r+1,c,dp,m,n);
        if(c+1<=n)ret+=solve(r,c+1,dp,m,n);
        return ret;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int> (n+1, -1));
        return solve(1,1,dp,m,n);
    }
};