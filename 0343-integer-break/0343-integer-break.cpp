class Solution {
public:
    int dp[100][2];
    int integerBreak(int n) {
        memset(dp,-1,sizeof dp);
        return solve(n,0);
    }
    int solve(int rem,int take){
        if(rem==0)
            return 1;
        int& ret=dp[rem][take];
        if(~ret)return ret;
        
        for(int i=take==0?rem-1:rem;i>=1;i--){
            ret=max(ret,i*solve(rem-i,1));
        }
        return ret;
    }
};