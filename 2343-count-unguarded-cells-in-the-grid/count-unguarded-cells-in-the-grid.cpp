class Solution {
public:
    int a[4]={1,-1,0,0};
    int b[4]={0,0,1,-1};
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> temp(n, vector<int>(m, 0));
        for(auto num:walls){
            int x=num[0],y=num[1];
            temp[x][y]=2;
        }
        for(auto num:guards){
            int x=num[0],y=num[1];
            temp[x][y]=2;
        }
        for(auto num:guards){
            int x=num[0],y=num[1];

            for(int i=0;i<4;i++){
                int xx=x+a[i],yy=y+b[i];
                while(xx>=0 && xx<n && yy>=0 && yy<m){
                    if(temp[xx][yy]==2)break;
                    temp[xx][yy]=1;
                    xx+=a[i];
                    yy+=b[i];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)ans+=(temp[i][j]==0);
        }
        return ans;
    }
};