class Solution {
public:
    int reverseDegree(string s) {
        int ans=0,i=1;
        for(auto x:s){
            int pos = 26 - (x-'a');
            ans+=pos*i++;
        }
        return ans;
    }
};