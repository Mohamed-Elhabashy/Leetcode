class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    vector<vector<int>> combine(int n, int k) {
        solve(1,n,k);
        return ans;
    }
    void solve(int i,int& n,int& k){
        if(i==n+1){
            if(v.size()==k)ans.push_back(v);
            return ;
        }
        solve(i+1,n,k);
        v.push_back(i);
        solve(i+1,n,k);
        v.pop_back();
    }
};