class Solution {
public:
    int a[8]={-2,2,-1,1,-2,2,-1,1};
    int b[8]={1,1,2,2,-1,-1,-2,-2};
    map<pair<int,pair<int,int>>,double>mp;
    double knightProbability(int n, int k, int row, int column) {
        return solve(row,column,k,n);
    }
    double solve(int i,int j,int rem,int n){
        if(mp.count({i,{j,rem}}))return mp[{i,{j,rem}}];
        if(i<0 || i>=n || j>=n || j<0)return 0;
        if(rem==0)return 1;
        double total=0;
        for(int x=0;x<8;x++)
            total+=solve(i+a[x],j+b[x],rem-1,n);
        mp[{i,{j,rem}}]=total/8.0;
        return mp[{i,{j,rem}}];
    }
};