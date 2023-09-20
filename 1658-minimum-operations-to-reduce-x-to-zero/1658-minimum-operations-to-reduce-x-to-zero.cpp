class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum<x)return -1;
        int T=totalSum-x;
        if(T==0)return n;
        unordered_map<int, int> mp;
        int sum = 0, ans = INT_MIN;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.count(sum-T)){
                ans = max(ans, i - mp[sum - T]);
            }
            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }
        if(ans == INT_MIN) return -1;
        
        return n - ans;


    }
};