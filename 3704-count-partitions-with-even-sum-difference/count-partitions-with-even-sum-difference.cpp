class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sumR=0,sumL=0,ans=0;
        for(auto x:nums)sumR+=x;
        for(int i=0;i<nums.size()-1;i++){
            sumL+=nums[i];
            if((sumL-(sumR-sumL))%2==0)ans++;
        }
        return ans;
    }
};