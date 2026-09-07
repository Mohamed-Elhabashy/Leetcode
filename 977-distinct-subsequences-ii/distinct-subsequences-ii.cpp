class Solution {
public:
    string s;
    int dp[2002];
    const int MOD = 1e9 + 7;

    int solve(int i){
        if(i==s.size())return 1;
        int& ret = dp[i];
        if(~ret)return ret;
        bool used[26] = {};
        ret=1;
        for(int j=i;j<s.size();j++){
            int ch = s[j]-'a';
            if(used[ch])continue;
            used[ch]=1;
            ret+=solve(j+1);
            ret%=MOD;
        }
        return ret;

    }
    int distinctSubseqII(string str) {
        s=str;
        memset(dp, -1, sizeof(dp));

        return (solve(0)-1 + MOD) % MOD;
    }
};