class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>&s,vector<int>&f){return s[1]<f[1];});
        vector<int>frq(2001);
        int ans=0;
        for(int i=0;i<tasks.size();i++){
            int l=tasks[i][0],r=tasks[i][1],time=tasks[i][2];
            for(int j=l;j<=r;j++)time-=frq[j];
            if(time<=0)continue;
            for(int j=r;time;j--){
                if(frq[j])continue;
                frq[j]=1;
                ans++;
                time--;
            }
        }
        return ans;
    }
};