class Solution {
public:
    int dp[100000][2];
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,prices,fee);
    }
    int solve(int i,bool sell,vector<int>& prices, int fee){
        if(i==prices.size())return 0;
        int& ret=dp[i][sell];
        if(~ret)return ret;
        ret=solve(i+1,sell,prices,fee);
        if(!sell)
            ret=max(ret,-prices[i]-fee+solve(i+1,!sell,prices,fee));
        else
            ret=max(ret,prices[i]+solve(i+1,!sell,prices,fee));
        return ret;
    }
};