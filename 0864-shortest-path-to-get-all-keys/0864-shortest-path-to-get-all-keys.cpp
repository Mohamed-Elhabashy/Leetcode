class Solution {
public:
    int a[4]={0,0,1,-1};
    int b[4]={1,-1,0,0};
    int vis[33][33][(1<<6)];
    bool vaild(int i,int j,int rows,int cols){
        return i>=0 && i<rows && j>=0 && j<cols;
    }
    int CountBit(int msk){
        int counter=0;
        for(int i=0;i<6;i++)counter+=(msk&(1<<i))>0?1:0;
        return counter;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        int StartR,StartC,rows,cols,Keys;
        rows=grid.size(),cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]>='a' && grid[i][j]<='z')Keys++;
                if(grid[i][j]=='@')StartR=i,StartC=j;
            }
        }
        queue<vector<int>>q;
        q.push({StartR,StartC,0});
        vis[StartR][StartC][0]=1;
        int moves=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto cur=q.front();
                q.pop();
                if(CountBit(cur[2])==Keys)return moves;
                for(int i=0;i<4;i++){
                    int newR=cur[0]+a[i];
                    int newC=cur[1]+b[i];
                    if(!vaild(newR,newC,rows,cols))continue;
                    if(grid[newR][newC]=='#')continue;
                    
                    if(grid[newR][newC]>='A' && grid[newR][newC]<='Z'){
                        int idx=grid[newR][newC]-'A';
                        if(!((1<<idx)&cur[2]))continue;
                    }
                    int newMask=cur[2];
                    if(grid[newR][newC]>='a' && grid[newR][newC]<='z'){
                        int idx=grid[newR][newC]-'a';
                        newMask|=(1<<idx);
                    }
                    if(vis[newR][newC][cur[2]]==1)continue;
                    vis[newR][newC][cur[2]]=1;
                    q.push({newR,newC,newMask});
                }
            }
            moves++;
        }
        return -1;
    }
};