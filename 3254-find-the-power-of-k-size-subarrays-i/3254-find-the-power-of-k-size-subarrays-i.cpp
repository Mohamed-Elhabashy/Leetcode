class Solution {
public:
    int solve(vector<int>& nums,int i,int k){
        i++;k--;
        while(k--){
            if(nums[i]==nums[i-1]+1)i++;
            else
                return -1;
        }
        return nums[i-1];
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        for(int i=0;(i+k-1)<nums.size();i++){
            int x=solve(nums,i,k);
            ans.push_back(x);
        }
        return ans;
    }
};