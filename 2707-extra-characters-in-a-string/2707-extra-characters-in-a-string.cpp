class Solution {
public:
    int dp[55];
    map<string,bool>mp;
    string str;
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp,-1,sizeof dp);
        str=s;
        for(auto str:dictionary){
            mp[str]=1;
        }
        return solve(0);
    }
    int solve(int i){
        if(i==str.size())return 0;
        int& ret=dp[i];
        if(~ret)return ret;
        ret=1+solve(i+1);
        string tmp="";
        for(int j=i;j<str.size();j++){
            tmp+=str[j];
            if(mp.count(tmp))ret=min(ret,solve(j+1));
        }
        return ret;
    }
};