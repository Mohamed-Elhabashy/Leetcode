class Solution {
public:
    int solve(int i,vector<int>& dp){
        if(i>dp.size())return 0;
        if(i==dp.size())return 1;
        if(~dp[i])return dp[i];
        dp[i]=solve(i+1,dp);
        dp[i]+=solve(i+2,dp);
        return dp[i];
    }
    int climbStairs(int n) {
        vector<int>dp(n,-1);
        return solve(0,dp);
    }
};