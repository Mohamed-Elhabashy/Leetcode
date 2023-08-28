class Solution {
public:
    map<int,vector<int>>mp;
    int d,dp[100001];
    int longestSubsequence(vector<int>& arr, int difference) {
        d=difference;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        int mx=0;
        for(int i=0;i<arr.size();i++){
            //cout<<i<<" "<<solve(i,arr)<<endl;
            mx=max(mx,1+solve(i,arr));
        }
        return mx;
    }
    int solve(int i,vector<int>& arr){
        if(i==arr.size())return 0;
        int& ret=dp[i];
        if(~ret)return ret;
        int value=arr[i]+d;
        ret=0;
        if(mp.count(value)==0)return ret;
        int idx=BS(mp[value],i);
        if(idx==-1)return ret;
        ret=1+solve(idx,arr);
        return ret;
    }
    int BS(vector<int>& arr,int i){
        int l=0,r=arr.size()-1,mid,ans=-1;
        while(l<=r){
            mid=(l+r)/2;
            if(arr[mid]<=i)l=mid+1;
            else{
                ans=arr[mid];
                r=mid-1;
            }
        }
        return ans;
    }
};