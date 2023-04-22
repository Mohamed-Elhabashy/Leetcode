class Solution {
public:
    int dp[500][500];
    int minInsertions(string s) {
        memset(dp,-1,sizeof dp);
        return solve(0,s.size()-1,s);
    }
    int solve(int i,int j,string& s){
        if(i>=j)return 0;
        int& ret=dp[i][j];
        if(~ret)return ret;
        if(s[i]==s[j])return ret=solve(i+1,j-1,s);
        ret=1+solve(i+1,j,s);
        ret=min(ret,1+solve(i,j-1,s));
        return ret;
    }
};