class Solution {
public:
    int dp[1002][1002];
    static bool cmp(string& s,string f){
        return s.size()<f.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        memset(dp,-1,sizeof dp);
        return solve(0,1001,words);
    }
    
    int solve(int i,int last,vector<string>& words){
        if(i==words.size())return 0;
        int& ret=dp[i][last];
        if(~ret)return ret;
        
        ret=solve(i+1,last,words);
        if(last==1001 || check(words[last],words[i])){
            ret=max(ret,1+solve(i+1,i,words));
        }
        return ret;
    }
      bool check(string &prev,string &cur){
        if(prev.size()+1!=cur.size())return 0;
        int i=0,j=0;
        while(j<cur.size()){
            if(i<prev.size() && prev[i]==cur[j]){
                i++;j++;
            }else{
                j++;
            }
        }
        return i==prev.size() && j==cur.size();
    }
};