class Solution {
public:
    int n,m;
    int a[4]={1,-1,0,0};
    int b[4]={0,0,1,-1};
    bool vaild(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n=mat.size();m=mat[0].size();
        vector<vector<int>> dis(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }
        while(q.size()){
            auto cur=q.front();
            int i=cur.first,j=cur.second;
            q.pop();
            for(int x=0;x<4;x++){
                int newi=a[x]+i;
                int newj=b[x]+j;
                if(vaild(newi,newj) && dis[newi][newj]==-1){
                    dis[newi][newj]=dis[i][j]+1;
                    q.push({newi,newj});
                }
            }
        }
        return dis;
    }
};