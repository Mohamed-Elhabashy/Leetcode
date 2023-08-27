class Solution {
public:
    int dp[2001][2001];
    bool canCross(vector<int>& stones) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,stones);
    }
    bool solve(int i,int last,vector<int>& v){
        if(i==v.size()-1)return 1;
        int& ret=dp[i][last];
        if(~ret)return ret;
        ret=0;
        int k=v[i]-v[last];
        int idx1=BS(v,v[i]+k);
        if(idx1!=-1 && idx1>i)
            ret|=solve(idx1,i,v);
        int idx2=BS(v,v[i]+k-1);
        if(idx2!=-1 && idx2>i)
            ret|=solve(idx2,i,v);
        int idx3=BS(v,v[i]+k+1);
        if(idx3!=-1 && idx3>i)
            ret|=solve(idx3,i,v);
        //cout<<i<<" "<<last<<" "<<k<<" "<<idx1<<" "<<idx2<<" "<<idx3<<endl;
        return ret;
    }
    int BS(vector<int>& v,int value){
        int l=0,r=v.size()-1,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(v[mid]==value)return mid;
            else if(v[mid]>value)r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
};