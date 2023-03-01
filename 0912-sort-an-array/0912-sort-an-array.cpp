class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int>frq;
        int l=1e9,r=-1e9;
        for(auto x:nums){
            frq[x]++;
            l=min(l,x);
            r=max(r,x);
        }
        int idx=0;
        for(int i=l;i<=r;i++){
            while(frq[i]--)
                nums[idx++]=i;
        }
        return nums;
    }
};