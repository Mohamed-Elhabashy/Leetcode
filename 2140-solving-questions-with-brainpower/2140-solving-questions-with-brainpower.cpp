class Solution {
public:
    long long dp[100000];
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof dp);
        return solve(0,questions);
    }
    long long solve(int i,vector<vector<int>>& questions){
        if(i>=questions.size())return 0;
        long long& ret=dp[i];
        if(~ret)return ret;
        ret=solve(i+1,questions);
        ret=max(ret,questions[i][0]+solve(i+questions[i][1]+1,questions));
        return ret;
    }
};