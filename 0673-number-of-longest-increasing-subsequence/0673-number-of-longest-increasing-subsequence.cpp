class Solution {
public:
    int length[2001],count[2001];
    vector<int>v;
    int findNumberOfLIS(vector<int>& nums) {
        v=nums;
        int mx=0;
        for(int i=0;i<nums.size();i++){
            solve(i);
            if(length[i]>mx)mx=length[i];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(length[i]==mx)ans+=count[i];
        }
        return ans;
    }
    void solve(int i){
        if(length[i]!=0)return ;
        length[i]=1;
        count[i]=1;
        for(int j=0;j<i;j++){
            if(v[j]<v[i]){
                solve(j);
                if(length[j]+1>length[i]){
                    length[i]=length[j]+1;
                    count[i]=0;
                }
                if(length[j]+1==length[i])count[i]+=count[j];
            }
        }
    }
    
};