class Solution {
public:
    int dp[1000][1000];
    int longestPalindromeSubseq(string s) {
        return solve(0,s.size()-1,s);
    }
    int solve(int i,int j,string& s){
        if(i==j)return 1;
        if(i>j)return 0;
        int &ret=dp[i][j];
        if(ret)return ret;
        if(s[i]==s[j])return ret=2+solve(i+1,j-1,s);
        ret=solve(i,j-1,s);
        ret=max(ret,solve(i+1,j,s));
        return ret;
    }
};