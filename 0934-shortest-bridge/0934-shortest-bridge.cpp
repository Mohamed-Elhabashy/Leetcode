class Solution {
public:
    bool vis[101][101],n;
    int ans=1e9;
    int a[4]={1,-1,0,0};
    int b[4]={0,0,1,-1};
    bool vaild(int i,int j,vector<vector<int>>& grid){
        return i>=0 && i<grid.size() && j>=0 && j<grid.size() && !vis[i][j] && grid[i][j];
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<pair<int,int>>>vec;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(!vis[i][j] && grid[i][j]){
                    vector<pair<int,int>>tmp;
                    dfs(i,j,tmp,grid);
                    vec.push_back(tmp);
                }
            }
        }
        for(int i=0;i<vec.size();i++){
            for(int j=i+1;j<vec.size();j++){
                solve(i,j,vec);
            }
        }
        return ans;
    }
    void dfs(int i,int j,vector<pair<int,int>>& tmp,vector<vector<int>>& grid){
        vis[i][j]=1;
        tmp.push_back({i,j});
        for(int x=0;x<4;x++){
            int ii=i+a[x],jj=j+b[x];
            if(vaild(ii,jj,grid))dfs(ii,jj,tmp,grid);
        }
    }
    void solve(int i,int j,vector<vector<pair<int,int>>>&v){
        for(int x=0;x<v[i].size();x++){
            for(int y=0;y<v[j].size();y++){
                int r1=v[i][x].first,c1=v[i][x].second;
                int r2=v[j][y].first,c2=v[j][y].second;
                int dis=abs(r1-r2)+abs(c1-c2)-1;
                ans=min(ans,dis);
            }
        }
    }
};