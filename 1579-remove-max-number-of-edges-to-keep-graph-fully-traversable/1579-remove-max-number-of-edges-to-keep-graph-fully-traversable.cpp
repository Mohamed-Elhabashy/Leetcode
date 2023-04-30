class Solution {
public:
    int NotUsed=0;
    void iota(int n,vector<int>& par){
        for(int i=0;i<n;i++)par[i]=i;
    }
    int Findpar(vector<int>& par,int u){
        if(par[u]==u)return u;
        return par[u]=Findpar(par,par[u]);
    }
    bool Union(vector<int>& par,int u,int v){
        u=Findpar(par,u);
        v=Findpar(par,v);
        if(u==v)return false;
        par[u]=v;
        return true;
    }
    void solve(vector<vector<int>>& edges,vector<int>& par,int& Connected,int type){
        for(auto edge:edges){
            if(edge[0]!=type)continue;
            if(Union(par,edge[1],edge[2]))Connected--;
            else NotUsed++;
        }
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int>par(n+1);
        iota(n,par);
        int Connected=n;
        solve(edges,par,Connected,3);//both
        cout<<Connected<<endl;
        vector<int>AlicePar=par;
        int AliceConnected=Connected;
        solve(edges,AlicePar,AliceConnected,1);//Alice
        if(AliceConnected!=1)return -1;
        vector<int>BobPar=par;
        int BobConnected=Connected;
        solve(edges,BobPar,BobConnected,2);//Bob
        if(BobConnected!=1)return -1;
        
        return NotUsed;
    }
};