class Solution {
public:
    vector<int>ans;
    int vis[11][11];
    int a[4]={0,-1,0,1};
    int b[4]={1,0,-1,0};
    bool vaild(int i,int j,vector<vector<int>>& matrix){
        return i>=0 && i<matrix.size() && j>=0 && j<matrix[0].size() && !vis[i][j];
    }
    void dfs(int i,int j,vector<vector<int>>& matrix,int x){
        vis[i][j]=1;
        ans.push_back(matrix[i][j]);
        if(vaild(i+a[x],j+b[x],matrix))dfs(i+a[x],j+b[x],matrix,x);
        else {
            int counter=4;
            while(counter--){
                x=(x+1)%4;
                if(vaild(i+a[x],j+b[x],matrix)){
                    dfs(i+a[x],j+b[x],matrix,x);
                    return ;
                }
            }
            
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        dfs(0,0,matrix,0);
        return ans;
    }
};