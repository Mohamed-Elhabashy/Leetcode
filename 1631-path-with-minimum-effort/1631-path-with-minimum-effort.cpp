class Solution {
public:
    int vis[101][101],vid=1;
    int a[4]={1,-1,0,0};
    int b[4]={0,0,1,-1};
    int n,m;
    int minimumEffortPath(vector<vector<int>>& heights) {
        n=heights.size();m=heights[0].size();
        int l=0,r=1e7,mid,ans=-1;
        while(l<=r){
            mid=(l+r)/2;
            if(BFS(heights,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
            vid++;
        }
        return ans;
    }
    bool BFS(vector<vector<int>>& heights,int val){
        vis[0][0]=vid;
        queue<pair<int,int>>q;
        q.push({0,0});
        while(q.size()){
            int X=q.front().first,Y=q.front().second;
            q.pop();
            if(X==n-1 && Y==m-1)return true;
            for(int i=0;i<4;i++){
                int x=X+a[i],y=Y+b[i];
                if(vaild(x,y) && vis[x][y]!=vid && abs(heights[x][y]-heights[X][Y])<=val){
                    vis[x][y]=vid;
                    q.push({x,y});
                }
            }
        }
        return false;
    }
    bool vaild(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }
};