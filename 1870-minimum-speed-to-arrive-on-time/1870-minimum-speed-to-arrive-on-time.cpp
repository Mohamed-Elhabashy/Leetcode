class Solution {
public:
    bool ok(int s,vector<int>& dist, double hour){
        int time=0;
        for(int i=0;i<dist.size()-1;i++){
            time+=(dist[i]+(dist[i]%s!=0?s:0))/s;
        }
        double x=time+(dist.back()/(double)s);
        return x<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1,r=10000000+1,mid,ans=-1;
        while(l<=r){
            mid=(l+r)/2;
            if(ok(mid,dist,hour)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};