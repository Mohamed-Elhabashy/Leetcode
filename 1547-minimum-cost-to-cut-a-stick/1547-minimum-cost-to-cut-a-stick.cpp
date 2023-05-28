class Solution {
public:
    map<pair<int,int>,int>dp;
    int minCost(int n, vector<int>& cuts) {
        return solve(0,n,cuts);
    }
    int solve(int l,int r,vector<int>& cuts)
    {
        if(dp.count({l,r}))return dp[{l,r}];
        bool flag=1;
        dp[{l,r}]=1e9;
        for(auto x:cuts){
            if(x>l && x<r){
                flag=0;
                dp[{l,r}]=min(dp[{l,r}],r-l+solve(l,x,cuts)+solve(x,r,cuts));
            }
        }
        if(flag)dp[{l,r}]=0;
        return dp[{l,r}];
    }
};