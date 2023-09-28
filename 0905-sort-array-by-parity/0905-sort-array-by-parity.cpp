class Solution {
public:
    static bool cmp(const int &s,const int &f){
        if(s%2==f%2){
            return s<f;
        }
        if(s%2==0)return true;
        return false;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        return nums;
    }
};