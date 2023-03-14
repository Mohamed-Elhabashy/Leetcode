class Solution {
public:
    int solve(int i,vector<int>&dp,vector<int>& cost){
        if(i>=cost.size())return 0;
        int& ret=dp[i];
        if(~ret)return ret;
        ret=cost[i]+solve(i+1,dp,cost);
        ret=min(ret,cost[i]+solve(i+2,dp,cost));
        return ret;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);
        return min(solve(0,dp,cost),solve(1,dp,cost));
    }
};