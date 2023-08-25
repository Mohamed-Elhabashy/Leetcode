class Solution {
public:
    int dp[101][101];
    string s1,s2,s3;
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())return 0;
        memset(dp,-1,sizeof dp);
        this->s1=s1;
        this->s2=s2;
        this->s3=s3;
        return solve(0,0);
    }
    bool solve(int x,int y){
        if(x+y==s3.size())return 1;
        int& ret=dp[x][y];
        if(~ret)return ret;
        ret=0;
        if(x<s1.size() && s1[x]==s3[x+y])ret|=solve(x+1,y);
        if(y<s2.size() && s2[y]==s3[x+y])ret|=solve(x,y+1);
        return ret;
    }
};