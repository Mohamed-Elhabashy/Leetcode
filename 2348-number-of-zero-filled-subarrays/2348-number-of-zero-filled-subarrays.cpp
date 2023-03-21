class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                int idx=i;
                while(idx<nums.size() && nums[idx]==0)idx++;
                int len=idx-i;
                ans+=(1LL*len*(len+1))/2;
                i=idx-1;
            }
        }
        return ans;
    }
};