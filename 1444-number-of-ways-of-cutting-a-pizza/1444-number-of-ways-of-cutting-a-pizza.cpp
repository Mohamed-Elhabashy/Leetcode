class Solution {
public:
    int dp[51][51][12],MOD=1e9+7;
    vector<vector<int>>cm;
    int row,col;
    int ways(vector<string>& pizza, int k) {
        memset(dp,-1,sizeof dp);
        row=pizza.size();
        col=pizza[0].size();
        cm.resize(row+1,vector<int>(col+2,0));
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                cm[i][j] = cm[i][j+1];
                for (int l = i; l < row; l++)
                    cm[i][j] += (pizza[l][j] == 'A');
            }
        }
        
        return solve(0,0,k,pizza);
    }
    int count(int r,int c,int x,int y)
    {
        return cm[r][c]-cm[x][y];
    }
    int solve(int r,int c,int rem,vector<string>& pizza)
    {
        if(rem==1){
            if(cm[r][c])return 1;
            return 0;
        }
        if(r==row || c==col)return 0;
        int &ret=dp[r][c][rem];
        if(~ret)return ret;
        ret=0;
        for(int i=r;i<row;i++){
            int apple=count(r,c,i+1,c);
            if(apple)
                ret+=solve(i+1,c,rem-1,pizza);
            ret%=MOD;
        }
        for(int i=c;i<col;i++){
            int apple=count(r,c,r,i+1);
            if(apple)
                ret+=solve(r,i+1,rem-1,pizza);
            ret%=MOD;
        }
        return ret;
    }
};