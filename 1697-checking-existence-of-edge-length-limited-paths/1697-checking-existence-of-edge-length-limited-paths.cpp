class DSU {
public:
    vector<int>par;
    DSU(int n){
        par.resize(n);
        for(int i=0;i<n;i++)par[i]=i;
    }
    int FindPar(int u){
        if(par[u]==u)return u;
        return par[u]=FindPar(par[u]);
    }
    void Union(int u,int v){
        u=FindPar(u);
        v=FindPar(v);
        if(u==v)return ;
        par[v]=u;
    }
};

class Solution {
public:
    static bool cmp(vector<int>&a2,vector<int>&a1){
        return a2[2] < a1[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU d(n);
        for(int i=0;i<queries.size();i++)queries[i].push_back(i);
        sort(queries.begin(),queries.end(),cmp);
        sort(edgeList.begin(),edgeList.end(),cmp);
        vector<bool>ans(queries.size(),false);
        int j=0;
        for(int i=0;i<queries.size();i++){
            while(j<edgeList.size()&&edgeList[j][2]<queries[i][2]){
                d.Union(edgeList[j][0],edgeList[j][1]);
                j++;
            }
            if(d.FindPar(queries[i][0])==d.FindPar(queries[i][1])){
                ans[queries[i][3]]=true;
            }
        }

        return ans;
    }
};