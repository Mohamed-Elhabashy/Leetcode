class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        int mn=nums.back();
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<=mn){
                mn=nums[i];
                continue;
            }
            int x=nums[i]/mn;
            if(nums[i]%mn)x++;
            mn=nums[i]/x;
            ans+=x-1;
        }
        return ans;
    }
};