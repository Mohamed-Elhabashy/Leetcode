class Solution {
public:
    double dp[102][102];
    bool vis[102][102];
    int p;
    double champagneTower(int poured, int query_row, int query_glass) {
        p=poured;
        return min(1.0,solve(query_row,query_glass));
    }
    double solve(int i,int j){
        if(i<0 || j<0 || j>i)return 0;
        if(i==0 && j==0)return p;
        double& ret=dp[i][j];
        if(vis[i][j])return ret;
        vis[i][j]=1;
        ret=max((solve(i-1,j-1)-1)/2,0.0);
        ret+=max((solve(i-1,j)-1)/2,0.0);
        return ret;
    }
};