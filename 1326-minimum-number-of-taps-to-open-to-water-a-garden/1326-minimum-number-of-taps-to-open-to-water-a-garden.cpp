class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>vec(n+1);
        for(int i=0;i<=n;i++){
            int st=max(0,i-ranges[i]);
            int en=min(n,i+ranges[i]);
            vec[st]=max(vec[st],en);
        }
        int ans=0;
        int l=0,r=0;
        for(int i=0;i<=n;i++){
            if(i>r){
                return -1;
            }
            if(i>l){
                ans++;
                l=r;
            }
            r=max(r,vec[i]);
        }
        return ans;
    }
};