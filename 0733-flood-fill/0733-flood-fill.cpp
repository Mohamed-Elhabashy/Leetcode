class Solution {
public:
    bool vis[50][50];
    int a[4]={0,0,1,-1};
    int b[4]={1,-1,0,0};
    bool vaild(int r,int c,vector<vector<int>>& image){
        return r>=0 && r<image.size() && c>=0 && c<image[0].size() && !vis[r][c];
    }
    void dfs(int r,int c,vector<vector<int>>& image,int color){
        vis[r][c]=1;
        for(int x=0;x<4;x++){
            if(vaild(r+a[x],c+b[x],image) && image[r+a[x]][c+b[x]]==image[r][c])dfs(r+a[x],c+b[x],image,color);
        }
        image[r][c]=color;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(sr,sc,image,color);
        return image;
    }
};