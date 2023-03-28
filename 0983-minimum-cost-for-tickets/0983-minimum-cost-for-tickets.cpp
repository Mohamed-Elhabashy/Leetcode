class Solution {
public:
    unordered_map<int,bool>traveldays;
    vector<int>dp;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(auto d:days)traveldays[d]=1;
        dp.resize(366,-1);
        return solve(days[0],costs);
    }
    int solve(int day,vector<int>& costs){
        if(day>=366)return 0;
        int& ret=dp[day];
        if(~ret)return ret;
        if(traveldays[day]==0)return ret=solve(day+1,costs);
        ret=costs[0]+solve(day+1,costs);
        ret=min(ret,costs[1]+solve(day+7,costs));
        ret=min(ret,costs[2]+solve(day+30,costs));
        return ret;
    }
};