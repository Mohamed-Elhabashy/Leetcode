class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int cnt=nums.size()/3;
        vector<int>ans;
        for(auto x:nums)mp[x]++;
        for(auto m:mp)
            if(m.second>cnt)ans.push_back(m.first);
        return ans;
    }
};