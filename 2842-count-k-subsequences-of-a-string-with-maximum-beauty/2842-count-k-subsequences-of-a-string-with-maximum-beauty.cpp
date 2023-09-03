class Solution {
public:
    int MOD=1e9+7;
    map<pair<int,pair<int,int>>, long long>mp;
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        map<char,int>frq;
        for(auto x:s)frq[x]++;
        if(frq.size()<k)return 0;
        vector<int>v;
        for(char i='a';i<='z';i++){
            if(frq[i]>0)
                v.push_back(frq[i]);
        }
        sort(v.rbegin(),v.rend());
        int mx=0;
        for(int i=0;i<k;i++)mx+=v[i];
        return solve(0,k,mx,v);
    }
    long long solve(int i, int remK, int remS,vector<int>& v) {
        if(remK==0 && remS==0)return 1;
        if(i==v.size() || remK<=0 || remS<=0)return 0;
        if(mp.count({i,{remK,remS}}))return mp[{i,{remK,remS}}];
        long long& ret=mp[{i,{remK,remS}}];
        ret=solve(i+1,remK,remS,v)%MOD;
        ret+=v[i]*solve(i+1,remK-1,remS-v[i],v)%MOD;
        ret%=MOD;
        return ret;
    }
};