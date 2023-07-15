class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>>dp(events.size()+1,vector<int>(k+1,-1));
        return solve(0,k,events,dp);
    }
    int solve(int i,int rem,vector<vector<int>>& events,vector<vector<int>>&dp){
        if(i>=events.size())return 0;
        int&ret=dp[i][rem];
        if(~ret)return ret;
        ret=solve(i+1,rem,events,dp);
        if(rem){
            vector<int> v={events[i][1],INT_MAX,INT_MAX};
            int idx=upper_bound(events.begin(),events.end(),v)-events.begin();
            ret=max(ret,events[i][2]+solve(idx,rem-1,events,dp));
        }
        return ret;
    }
};