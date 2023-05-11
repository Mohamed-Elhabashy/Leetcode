class Solution {
public:
    int dp[500][500];
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,nums1,nums2);
    }
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2){
        if(i==nums1.size() || j==nums2.size())return 0;
        int& ret=dp[i][j];
        if(~ret)return ret;
        ret=solve(i+1,j,nums1,nums2);
        ret=max(ret,solve(i,j+1,nums1,nums2));
        for(int x=j;x<nums2.size();x++){
            if(nums1[i]==nums2[x])ret=max(ret,1+solve(i+1,x+1,nums1,nums2));
        }
        for(int x=i;x<nums1.size();x++){
            if(nums1[x]==nums2[j])ret=max(ret,1+solve(x+1,j+1,nums1,nums2));
        }
        return ret;
    }
};