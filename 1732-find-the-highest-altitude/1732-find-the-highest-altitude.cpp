class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0,ans=0;
        for(auto x:gain){
            sum+=x;
            ans=max(ans,sum);
        }
        return ans;
    }
};