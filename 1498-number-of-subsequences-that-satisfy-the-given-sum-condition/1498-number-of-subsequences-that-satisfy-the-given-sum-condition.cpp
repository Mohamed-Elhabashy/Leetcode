class Solution {
public:
    vector<int>pow;
    int MOD=1e9+7;
    void gen(int n){
        pow.resize(n);
        pow[0]=1;
        for(int i=1;i<n;i++){
            pow[i]=(pow[i-1]*2)%MOD;
        }
    }
    int numSubseq(vector<int>& nums, int target){
        gen(nums.size());
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1,ans=0;
        while(l<=r){
            //cout<<l<<" "<<r<<endl;
            if(nums[l]+nums[r]<=target){
                ans+=pow[r-l]%MOD;
                ans%=MOD;
                l++;
            }
            else
                r--;
        }
        return ans;
    }
};