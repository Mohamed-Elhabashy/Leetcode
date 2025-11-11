class Solution {
public:
    int dp[601][101][101];
    vector<pair<int,int>>v;
    int findMaxForm(vector<string>& strs, int n, int m) {
        memset(dp,-1,sizeof dp);
        for(auto x:strs){
            int one=0,zero=0;
            for(auto s:x){
                if(s=='0')zero++;
                else one++;
            }
            cout<<zero<<" "<<one<<endl;
            v.push_back({zero,one});
        }
        return solve(0,n,m);
    }
    int solve(int i , int remZero,int remOne){
        if(i==v.size())return 0;
        int& ret=dp[i][remZero][remOne];
        if(~ret)return ret;
        ret=solve(i+1,remZero,remOne);
        if(v[i].first<=remZero && v[i].second<=remOne)
            ret=max(ret,1+solve(i+1,remZero-v[i].first,remOne-v[i].second));
        return ret;
    }
};