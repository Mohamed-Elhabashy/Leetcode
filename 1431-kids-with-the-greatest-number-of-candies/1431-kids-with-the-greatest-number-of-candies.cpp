class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int sz=candies.size(),mx=0;
        for(auto x:candies)mx=max(mx,x);
        vector<bool>ans(sz,false);
        for(int i=0;i<sz;i++){
            int x=candies[i]+extraCandies;
            if(x>=mx)ans[i]=true;
        }
        return ans;
    }
};