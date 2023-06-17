class Solution {
public:
    int dp[2001][2001][2];
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        memset(dp,-1,sizeof dp);
        int ans=min(solve(1,0,0,arr1,arr2),1+solve(1,0,1,arr1,arr2));
        ans=(ans>=1e9)?-1:ans;
        return ans;
    }
    int solve(int i,int j,bool f,vector<int>& arr1, vector<int>& arr2){
        if(i==arr1.size())return 0;
        int& ret=dp[i][j][f];
        if(~ret)return ret;
        int val=(f==1)?arr2[j]:arr1[j];
        ret=1e9;
        if(arr1[i]>val)ret=min(ret,solve(i+1,i,0,arr1,arr2));
        int idx=upper_bound(arr2.begin(),arr2.end(),val)-arr2.begin();
        if(idx<arr2.size() && arr2[idx]>val)ret=min(ret,1+solve(i+1,idx,1,arr1,arr2));
        return ret;
    }
};