class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=(lower_bound(nums.begin(),nums.end(),target)-nums.begin());
        if((l<nums.size() && nums[l]!=target) || l==nums.size())l=-1;
        int r=(upper_bound(nums.begin(),nums.end(),target)-nums.begin())-1;
        if((r>=0 && nums[r]!=target) || r<0 || r==nums.size())r=-1;
        //cout<<l<<" "<<r<<endl;;
        return vector<int>{l,r};
    }
};