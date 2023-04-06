class Solution {
public:
    int a[4]={1,-1,0,0};
    int b[4]={0,0,-1,1};
    vector<vector<bool>>vis;
    int n,m;
    bool vaild(int i,int j,vector<vector<int>>& grid){
        return i>=0 && i<n && j>=0 && j<m ;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();m=grid[0].size();
        vis.resize(n,vector<bool>(m,0));
        int ans=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    if(dfs(i,j,grid)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
    bool dfs(int i,int j,vector<vector<int>>& grid){
        if(!vaild(i,j,grid))return 0;
        if(vis[i][j] || grid[i][j])return 1;
        vis[i][j]=1;
        bool flag=1;
        for(int x=0;x<4;x++){
            int ii=i+a[x],jj=j+b[x];
            flag&=dfs(ii,jj,grid);
            
        }
        return flag;
    }
};