class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>ans,lis;
        for(auto x:obstacles){
            int idx=upper_bound(lis.begin(),lis.end(),x)-lis.begin();
            if(idx==lis.size())lis.push_back(x);
            else lis[idx]=x;
            ans.push_back(idx+1);
        }
        return ans;
    }
};