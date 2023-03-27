class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        unordered_map<int,vector<int>>mp1,mp2;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    mp1[j].push_back(i);
                    mp2[i].push_back(j);
                }
                while(nums[i]%j==0){
                    nums[i]/=j;
                }
            }
            if(nums[i]>1){
                mp1[nums[i]].push_back(i);
                mp2[i].push_back(nums[i]);
            }
        }
        int mxIndex=0;
        for(int i=0;i<=n-2;i++){
            for(auto x:mp2[i]){
                mxIndex=max(mxIndex,mp1[x].back());
            }
            if(mxIndex==i)return i;
        }
        return -1;
    }
};