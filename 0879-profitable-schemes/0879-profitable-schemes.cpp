class Solution {
public:
    int minProfit,n;
    int dp[101][101][101],MOD=1e9+7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        this->n=n;
        this->minProfit=minProfit;
        memset(dp,-1,sizeof dp);
        return solve(0,0,0,group,profit);
    }
    int solve(int i,int Profit,int Counter,vector<int>& group, vector<int>& profit){
        if(i==group.size())
            return Profit>=minProfit;
        if(Profit>=100)Profit=100;
        int& ret=dp[i][Profit][Counter];
        if(~ret)return ret;
        ret=solve(i+1,Profit,Counter,group,profit)%MOD;
        if(Counter+group[i]<=n)ret+=solve(i+1,Profit+profit[i],Counter+group[i],group,profit)%MOD;
        ret%=MOD;
        return ret;
    }
};