class Solution {
public:
    int bits[30]={},value=0;
    void add(int x){
        for(int i=0;i<30;i++)
        {
            if(x&(1<<i)){
                bits[i]++;
                value|=(1<<i);
            }
        }
    }
    void remove(int x){
        for(int i=0;i<30;i++)
        {
            if(x&(1<<i)){
                bits[i]--;
                if(bits[i]==0)
                    value&=~(1<<i);
            }
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans=1e9;
        for(int i=0,j=0;j<nums.size();j++){
            add(nums[j]);
            while(value>=k && i<=j){
                ans=min(ans,j-i+1);
                remove(nums[i++]);
            }
        }
        return ans==1e9?-1:ans;
    }
};