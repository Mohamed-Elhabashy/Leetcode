class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int one=nums[n-1]==1,gcd=nums[n-1];
        for (int i = 0; i < n - 1; i++) {
            gcd =__gcd(gcd,nums[i]);
            one+=(nums[i]==1);
        }
        if(gcd>1)return -1;
        if(one>0)return n-one;
        int ans=1e9;
        for(int i=0;i<n;i++){
            gcd=nums[i];
            for(int j=i+1;j<n;j++){
                gcd =__gcd(gcd,nums[j]);
                if(gcd==1){
                    ans=min(ans,j-i+n-1);
                    break;
                }
            }
        }
        return ans;

    }
};