class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l=0,r=2e4,mid,ans;
        while(l<=r){
            mid=(l+r)/2;
            if(ok(row,col,cells,mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
    bool ok(int row, int col, vector<vector<int>>& cells,int mid){
        vector<vector<int>>graph(row,vector<int>(col,0));
        for(int i=0;i<min(mid,(int)cells.size());i++){
            int x=cells[i][0]-1,y=cells[i][1]-1;
            graph[x][y]=1;
        }
        for(int i=0;i<col;i++){
            bool flag=0;
            if(graph[0][i]==0)
                dfs(0,i,flag,graph,row,col);
            if(flag)return 1;
        }
        return 0;
    }
    int a[4]={0,0,1,-1};
    int b[4]={-1,1,0,0};
    bool vaild(int i,int j,int row,int col,vector<vector<int>>&graph){
        return i>=0 && i<row && j>=0 && j<col && graph[i][j]!=1;
    }
    void dfs(int i,int j,bool& flag,vector<vector<int>>&graph,int row,int col){
        if(i==row-1){
            flag=1;
            return;
        }
        graph[i][j]=1;
        for(int x=0;x<4;x++){
            int ii=a[x]+i;
            int jj=b[x]+j;
            if(vaild(ii,jj,row,col,graph))dfs(ii,jj,flag,graph,row,col);
        }
    }
};