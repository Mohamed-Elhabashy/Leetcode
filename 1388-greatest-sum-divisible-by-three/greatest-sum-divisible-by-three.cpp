class Solution {
public:
    int dp[40003][4];
    int maxSumDivThree(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,nums);
    }
    int solve(int i,int mod,vector<int>& nums){
        if(i==nums.size()){
            if(mod==0)return 0;
            return -1e9;
        }
        int& ret=dp[i][mod];
        if(~ret)return ret;
        ret=solve(i+1,mod,nums);
        ret=max(ret,nums[i]+solve(i+1,(mod+nums[i])%3,nums));
        return ret;
    }
};