class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        for(int j=(n+1)/2;j<n;j++){
            i+=2*nums[i]<=nums[j];
        }
        return i*2;
        
    }
};