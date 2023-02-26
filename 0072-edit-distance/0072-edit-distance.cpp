class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,string& word1, string& word2){
        if(i==word1.size() || j==word2.size())return (word1.size()-i)+(word2.size()-j);
        int &ret=dp[i][j];
        if(~ret)return ret;
        ret=1e9;
        ret=1+solve(i+1,j,word1,word2);
        
        ret=min(ret,1+solve(i,j+1,word1,word2));
        ret=min(ret,1+solve(i+1,j+1,word1,word2));
        if(word1[i]==word2[j])
            ret=min(ret,solve(i+1,j+1,word1,word2));
        
        return ret;
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,word1,word2);
    }
};