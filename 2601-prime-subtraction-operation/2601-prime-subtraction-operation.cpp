class Solution {
public:
    bool isPrime(int x){
        for(int i=2;i<x;i++)
            if(x%i==0)return false;
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int x;
            if(i==0)
                x=nums[i];
            else
                x=nums[i]-nums[i-1];
            if(x<=0)return false;
            for (int j = x - 1; j >= 2; j--) {
                if (isPrime(j)) {
                    nums[i] -= j;
                    break;
                }
            }
        }
        return true;
    }
};