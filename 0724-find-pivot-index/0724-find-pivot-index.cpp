class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>cm(nums.size()),pref(nums.size());
        cm[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            cm[i]=cm[i-1]+nums[i];
        pref[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
            pref[i]=pref[i+1]+nums[i];
        for(int i=0;i<nums.size();i++){
            if(cm[i]-nums[i]==pref[i]-nums[i])return i;
        }
        return -1;
    }
};