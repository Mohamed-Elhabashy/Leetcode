class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int,int>mp;
        int Xor=0;
        mp[0]=1;
        long long ans=0;
        for(auto x:nums)
        {
            Xor^=x;
            ans+=mp[Xor];
            mp[Xor]++;
        }
        return ans;
    }
};