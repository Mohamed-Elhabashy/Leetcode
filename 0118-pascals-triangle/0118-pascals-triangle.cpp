class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans(n);
        ans[0]=vector<int>{1};
        for(int i=1;i<n;i++){
            vector<int>t;
            t.push_back(1);
            for(int j=1;j<ans[i-1].size();j++){
                t.push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
            
            t.push_back(1);
            ans[i]=t;
        }
        return ans;
    }
};