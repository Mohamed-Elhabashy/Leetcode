class Solution {
public:
    bool vis[300][300];
    int a[4]={0,0,1,-1};
    int b[4]={1,-1,0,0};
    bool vaild(int r,int c,vector<vector<char>>& grid){
        return r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && !vis[r][c] && grid[r][c]=='1';
    }
    void dfs(int r,int c,vector<vector<char>>& grid){
        vis[r][c]=1;
        for(int x=0;x<4;x++){
            if(vaild(r+a[x],c+b[x],grid))dfs(r+a[x],c+b[x],grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    dfs(i,j,grid);
                }
        }
        return ans;
    }
};