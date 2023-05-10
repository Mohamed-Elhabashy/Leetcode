class Solution {
public:
    vector<vector<int>>ans;
    int a[4]={0,-1,0,1};
    int b[4]={1,0,-1,0};
    int num=1,n;
    bool vaild(int i,int j){
        return i>=0 && i<n && j>=0 && j<n && ans[i][j]==0;
    }
    void dfs(int i,int j,int x){
        ans[i][j]=num++;
        if(vaild(i+a[x],j+b[x]))dfs(i+a[x],j+b[x],x);
        else {
            int counter=4;
            while(counter--){
                x=(x+1)%4;
                if(vaild(i+a[x],j+b[x])){
                    dfs(i+a[x],j+b[x],x);
                    return ;
                }
            }
            
        }
    }
    vector<vector<int>> generateMatrix(int _n) {
        n=_n;
        ans.resize(n,vector<int>(n));
        dfs(0,0,0);
        return ans;
    }
};