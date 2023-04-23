class Solution {
public:
    int dp[100000],MOD=1e9+7;
    int numberOfArrays(string s, int k) {
        memset(dp,-1,sizeof dp);
        return solve(0,s,k);
    }
    int solve(int i,string& s,int k){
        if(i==s.size())return 1;
        int& ret=dp[i];
        if(~ret)return ret;
        ret=0;
        long long number=0;
        for(int j=i;j<s.size();j++){
            number*=10;
            number+=s[j]-'0';
            if(number>=1 && number<=k)
                ret+=solve(j+1,s,k)%MOD;
            else break;
            ret%=MOD;
        }
        return ret;
    }
};