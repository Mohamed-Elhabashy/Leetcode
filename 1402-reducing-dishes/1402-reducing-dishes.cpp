class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        n=satisfaction.size();
        dp.resize(n,vector<int>(n+1,-1));
        return solve(0,1,satisfaction);
    }
    int solve(int idx,int time,vector<int>& satisfaction){
        if(idx==n)return 0;
        int& ret=dp[idx][time];
        if(~ret)return ret;
        ret=solve(idx+1,time,satisfaction);
        ret=max(ret,satisfaction[idx]*time+solve(idx+1,time+1,satisfaction));
        return ret;
    }
};