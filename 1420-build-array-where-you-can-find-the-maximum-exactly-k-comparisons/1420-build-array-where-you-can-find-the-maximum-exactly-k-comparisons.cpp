class Solution {
public:
    int dp[52][101][101],n,m,MOD=1e9+7;
    int numOfArrays(int n, int m, int k) {
        this->n=n;
        this->m=m;
        memset(dp,-1,sizeof dp);
        return solve(0,0,k)%MOD;
    }
    int solve(int i,int last,int rem){
        if(i==n)return rem==0;
        if(rem<0)return 0;
        int& ret=dp[i][last][rem];
        if(~ret)return ret;
        ret=0;
        for(int j=1;j<=last;j++){
            ret+=solve(i+1,last,rem)%MOD;
            ret%=MOD;
        }
        
        for(int j=last+1;j<=m;j++){
            ret+=solve(i+1,j,rem-1)%MOD;
            ret%=MOD;
        }
        return ret;
    }
};