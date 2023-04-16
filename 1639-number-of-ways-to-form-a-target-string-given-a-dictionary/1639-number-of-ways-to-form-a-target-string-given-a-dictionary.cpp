class Solution {
public:
    int frq[1000][26];
    long long dp[1000][1000];
    int MOD=1e9+7,len;
    int numWays(vector<string>& words, string target) {
        len=words[0].size();
        for(int i=0;i<len;i++){
            for(int j=0;j<words.size();j++){
                frq[i][words[j][i]-'a']++;
            }
        }
        memset(dp,-1,sizeof dp);
        return solve(0,0,target);
    }
    long long solve(int idxW,int idxT,string& target){
        if(idxT==target.size())return 1;
        if(idxW==len)return 0;
        long long& ret=dp[idxW][idxT];
        if(~ret)return ret;
        ret=solve(idxW+1,idxT,target);
        ret+=frq[idxW][target[idxT]-'a']*solve(idxW+1,idxT+1,target);
        ret%=MOD;
        return ret;
    }
};