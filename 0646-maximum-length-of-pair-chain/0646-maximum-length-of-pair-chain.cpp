class Solution {
public:
    int dp[1001][1002];
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp,-1,sizeof dp);
        pairs.push_back({-2000,-2000});
        return solve(0,pairs.size()-1,pairs);
    }
    int solve(int i,int last,vector<vector<int>>& pairs){
        if(i==pairs.size()-1)return 0;
        int& ret=dp[i][last];
        if(~ret)return ret;
        ret=solve(i+1,last,pairs);
        if(pairs[i][0]>pairs[last][1])ret=max(ret,1+solve(0,i,pairs));
        return ret;
    }
};