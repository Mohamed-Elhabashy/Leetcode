class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(auto x:nums){
            int a=100000;
            for(int i=0;i<=60;i+=3){
                a=min(a,abs(x-i));
            }
            ans+=a;
        }
        return ans;
    }
};