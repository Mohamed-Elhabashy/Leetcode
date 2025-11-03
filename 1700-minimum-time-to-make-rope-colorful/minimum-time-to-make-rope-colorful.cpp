class Solution {
public:
    int dp[100001][27];
    string str;
    int minCost(string colors, vector<int>& neededTime) {
        memset(dp, -1, sizeof dp);

        str=colors;
        return solve(0,26,neededTime);
    }
    int solve(int i,int chr,vector<int>& neededTime){
        if(i==str.size())return 0;
        int& ret=dp[i][chr];
        if(~ret)return ret;
        ret=neededTime[i] + solve(i+1,chr,neededTime);
        if(chr==26 || (str[i]-'a')!=chr)ret=min(ret,solve(i+1,str[i]-'a',neededTime));
        return ret;
    }
};