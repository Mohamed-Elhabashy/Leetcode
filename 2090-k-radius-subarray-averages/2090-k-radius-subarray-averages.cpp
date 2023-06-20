class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long sum=0;
        int n=nums.size();
        vector<int>ans(n,-1);
        int l=0,r=2*k,pos=k;
        
        if(r>=n)return ans;
        for(int i=r;i>=0;i--)sum+=nums[i];
        ans[pos++]=sum/(2*k+1);
        r++;
        while(pos<n-k){
            sum-=nums[l];
            sum+=nums[r];
            l++;r++;
            ans[pos++]=sum/(2*k+1);
        }
        return ans;
        
    }
};