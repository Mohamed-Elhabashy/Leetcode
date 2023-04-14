class Solution {
public:
    int n;
    int longestPalindromeSubseq(string s) {
        n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n-1,dp,s);
    }
    int solve(int i,int j,vector<vector<int>>&dp,string& s){
        if(i==j)return 1;
        if(i>j)return 0;
        int &ret=dp[i][j];
        if(~ret)return ret;
        ret=solve(i,j-1,dp,s);
        ret=max(ret,solve(i+1,j,dp,s));
        if(s[i]==s[j])ret=(ret,2+solve(i+1,j-1,dp,s));
        return ret;
    }
};