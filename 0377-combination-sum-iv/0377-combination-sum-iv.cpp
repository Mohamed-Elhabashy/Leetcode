class Solution {
public:
    int dp[201][1001];
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof dp);
        return solve(0,target,nums);
    }
    int solve(int i,int rem,vector<int>& nums){
        if(rem==0)return 1;
        if(i==nums.size())return 0;
        int &ret=dp[i][rem];
        if(~ret)return ret;
        ret=0;
        ret+=solve(i+1,rem,nums);
        if(rem-nums[i]>=0)
            ret+=solve(0,rem-nums[i],nums);
        return ret;
    }
};