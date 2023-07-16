class Solution {
public:
    int n,dp[61][(1<<16)+2];
    unordered_map<string,int>mp;
    vector<int>ans;
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n=req_skills.size();
        int index=0;
        for(auto s:req_skills)mp[s]=index++;
        memset(dp,-1,sizeof dp);
        solve(0,0,people);
        build(0,0,people);
        return ans; 
    }
    void build(int i,int msk,vector<vector<string>>& people){
        if(countBits(msk))return ;
        if(i==people.size())return ;
        int& ret=dp[i][msk];
        int ch1=solve(i+1,msk,people);
        int ch2=1+solve(i+1,GetMsk(msk,people[i]),people);
        if(ch1==ret)build(i+1,msk,people);
        else{
            ans.push_back(i);
            build(i+1,GetMsk(msk,people[i]),people);
        }
    }
    int solve(int i,int msk,vector<vector<string>>& people){
        if(countBits(msk))return 0;
        if(i==people.size())return 1e9;
        int& ret=dp[i][msk];
        if(~ret)return ret;
        ret=solve(i+1,msk,people);
        ret=min(ret,1+solve(i+1,GetMsk(msk,people[i]),people));
        return ret;
    }
    bool countBits(int msk){
        int count=0;
        for(int i=0;i<16;i++)count+=((1<<i)&msk)>0?1:0;
        return count>=n;
    }
    int GetMsk(int msk,vector<string>& skills){
        for(auto x:skills){
            if(mp.count(x))
            msk|=(1<<mp[x]);
        }
        return msk;
    }
};