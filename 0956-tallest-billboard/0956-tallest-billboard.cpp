class Solution {
public:
    int dp[20][10001];
    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof dp);
        return max(solve(0,0,rods)/2,0);
    }
    int solve(int i,int sum,vector<int>& rods){
        if(i==rods.size()){
            if(sum==0)return 0;
            else return -1e9;
        }
        int& ret=dp[i][sum+5000];
        if(~ret)return ret;
        ret=solve(i+1,sum,rods);
        ret=max(ret,rods[i]+solve(i+1,sum+rods[i],rods));
        ret=max(ret,rods[i]+solve(i+1,sum-rods[i],rods));
        return ret;
    }
};