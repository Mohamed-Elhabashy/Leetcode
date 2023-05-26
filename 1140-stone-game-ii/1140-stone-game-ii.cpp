class Solution {
public:
    int dp[101][101][2];
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof dp);
        return solve(0,1,1,piles);
    }
    int solve(int i,int m,bool turn,vector<int>& piles){
        if(i>=piles.size())return 0;
        int& ret=dp[i][m][turn];
        if(~ret)return ret;
        int sum=0,ans=turn==1?0:INT_MAX;
        for(int count=1;count<=2*m;count++){
            int idx=i+count-1;
            if(idx>=piles.size())break;
            sum+=piles[idx];
            if(turn){
                ans=max(ans,sum+solve(idx+1,max(count,m),!turn,piles));
            }
            else 
                ans=min(ans,solve(idx+1,max(count,m),!turn,piles));
        }
        return ret=ans;
    }
};