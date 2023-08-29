class Solution {
public:
    int dp[100001];
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        memset(dp,-1,sizeof dp);
        return solve(0,intervals);
    }
    int solve(int i,vector<vector<int>>& intervals){
        if(i>=intervals.size())return 0;
        int& ret = dp[i];
        if(~ret)return ret;
        int idx=BS(i,intervals);
        ret=(idx-i-1)+solve(idx,intervals);
        ret=min(ret,1+solve(i+1,intervals));
        return ret;
    }
    int BS(int i,vector<vector<int>>& v){
        int l=0,r=v.size()-1,mid,ans=v.size();
        while(l<=r){
            mid=(l+r)/2;
            if(v[mid][0]>=v[i][1]){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};