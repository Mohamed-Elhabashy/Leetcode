class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minpos=-1,maxpos=-1,l=-1;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK)
                l=i;
            if(nums[i]==minK)
                minpos=i;
            if(nums[i]==maxK)
                maxpos=i;
            ans+=max(0,min(minpos,maxpos)-l);
        }
        return ans;
    }
};
