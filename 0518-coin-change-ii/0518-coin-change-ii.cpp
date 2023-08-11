class Solution {
public:
    int dp[301][5001];
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof dp);
        return solve(0,amount,coins);
    }
    int solve(int i,int rem,vector<int>& coins){
        if(rem==0)return 1;
        if(rem<0 || i>=coins.size())return 0;
        int& ret=dp[i][rem];
        if(~ret)return ret;
        ret=solve(i,rem-coins[i],coins);
        ret+=solve(i+1,rem,coins);
        return ret;
    }
};