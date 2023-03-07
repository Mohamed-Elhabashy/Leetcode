class Solution {
public:
    bool ok(long long mid,vector<int>& time, int totalTrips){
        unsigned long long count=0;
        for(auto x:time){
            count+=mid/x;
        }
        return count>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        unsigned long long l=0,r=1000000000000000000;
        while(l<r){
            long long mid=(l+r)/2;
            
            if(ok(mid,time,totalTrips))
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};