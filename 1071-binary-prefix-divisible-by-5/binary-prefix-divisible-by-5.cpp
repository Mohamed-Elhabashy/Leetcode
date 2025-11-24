class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>ans;
        int mod=0;
        for(int x:nums){
            mod*=2;
            mod+=x;
            mod%=5;
            ans.push_back(mod==0);
        }
        return ans;
    }
};