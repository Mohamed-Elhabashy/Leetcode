class Solution {
public:
    int dp[100000][2];
    string stoneGameIII(vector<int>& v) {
        memset(dp,-1,sizeof dp);
        int sum=0;
        for(auto x:v)sum+=x;
        int alice=solve(0,1,v);
        int bob=sum-alice;
        if(alice>bob)return "Alice";
        else if(alice<bob)return "Bob";
        return "Tie";
    }
    int solve(int i,bool turn,vector<int>& v){
        if(i>=v.size())return 0;
        int& ret=dp[i][turn];
        if(~ret)return ret;
        if(turn){
            int sum=v[i];
            ret=sum + solve(i+1,!turn,v);
            if(i+1<v.size()){
                sum+=v[i+1];
                ret=max(ret,sum + solve(i+2,!turn,v));
            }
            if(i+2<v.size()){
                sum+=v[i+2];
                ret=max(ret,sum + solve(i+3,!turn,v));
            }
            return ret;
        }
        ret=solve(i+1,!turn,v);
        ret=min(ret,solve(i+2,!turn,v));
        ret=min(ret,solve(i+3,!turn,v));
        return ret;
    }
};