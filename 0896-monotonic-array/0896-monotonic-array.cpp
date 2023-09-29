class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool flag=true;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                flag=false;
                break;
            }
        }
        bool flag1=true;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                flag1=false;
                break;
            }
        }
        return flag||flag1;
    }
};