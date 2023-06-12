class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int st=-1,en=-1;
        for(int i=0;i<nums.size();i++){
            if(st==-1){
                st=nums[i];
                int j=i+1;
                en=nums[i];
                while(j<nums.size()&& (1LL*nums[j])-nums[j-1]==1){
                    en=nums[j];
                    j++;
                }
                if(st!=en)
                    ans.push_back(to_string(st)+"->"+to_string(en));
                else{
                    ans.push_back(to_string(st));
                }
                i=j-1;
                st=-1;
            }
        }
        return ans;
    }
};