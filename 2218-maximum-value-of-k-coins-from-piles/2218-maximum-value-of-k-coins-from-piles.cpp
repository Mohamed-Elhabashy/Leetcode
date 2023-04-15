class Solution {
public:
    int dp[1000][2001];
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof dp);
        return solve(0,k,piles);
    }
    int solve(int i,int rem,vector<vector<int>>& piles){
        if(rem==0 || i==piles.size())return 0;
        int& ret=dp[i][rem];
        if(~ret)return ret;
        int sum=0;
        ret=solve(i+1,rem,piles);
        for(int j=0;j<min(rem,(int)piles[i].size());j++){
            sum+=piles[i][j];
            ret=max(ret,sum+solve(i+1,rem-j-1,piles));
        }
        
        return ret;
    }
};