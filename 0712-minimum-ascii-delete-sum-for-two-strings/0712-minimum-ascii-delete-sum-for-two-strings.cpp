class Solution {
public:
    int dp[1001][1001];
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,s1,s2);
    }
    int solve(int i,int j,string& s1,string& s2){
        if(i==s1.size() || j==s2.size()){
            int sum=0;
            for(int x=i;x<s1.size();x++)sum+=(int)s1[x];
            for(int x=j;x<s2.size();x++)sum+=(int)s2[x];
            return sum;
        }
        int&ret=dp[i][j];
        if(~ret)return ret;
        ret=(int)s1[i]+solve(i+1,j,s1,s2);
        ret=min(ret,(int)s2[j]+solve(i,j+1,s1,s2));
        if(s1[i]==s2[j])ret=min(ret,solve(i+1,j+1,s1,s2));
        return ret;
    }
};