class Solution {
public:
    int dp[501][501][2];
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,0,nums1,nums2);
    }
    int solve(int i,int j,bool take,vector<int>& nums1, vector<int>& nums2){
        if(i==nums1.size() || j==nums2.size())return take==1?0:-1e9;
        int& ret=dp[i][j][take];
        if(~ret)return ret;
        ret=solve(i+1,j,take,nums1,nums2);
        ret=max(ret,solve(i,j+1,take,nums1,nums2));
        ret=max(ret,(nums1[i]*nums2[j])+solve(i+1,j+1,1,nums1,nums2));
        return ret;
    }
};