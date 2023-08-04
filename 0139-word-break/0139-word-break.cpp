class Solution {
public:
    int dp[305];
    bool ok(int i,string& s,string& str){
        if(i+str.size()>s.size())return 0;
        for(int j=0;j<str.size();j++,i++)
            if(s[i]!=str[j])return 0;
        return 1;
    }
    int solve(int i,string& s,vector<string>& wordDict) {
        if(i==s.size())
            return 1;
        int &ret=dp[i];
        if(~ret)return ret;
        ret=0;
        for(auto str:wordDict){
            if(ok(i,s,str))
            ret|=solve(i+str.size(),s,wordDict);
        }
        return ret;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof dp);
        return solve(0,s,wordDict);
    }
};