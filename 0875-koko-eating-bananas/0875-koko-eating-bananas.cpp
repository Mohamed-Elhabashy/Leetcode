class Solution {
public:
    bool ok(int k,vector<int>& piles,int h){
        int counter=0;
        for(auto x:piles)
            counter+=(x/k)+(x%k==0?0:1);
        return counter<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=Maxelement(piles);
        while(l<r){
            int mid=(l+r)/2;
            if(ok(mid,piles,h))
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
    int Maxelement(vector<int>& piles){
        int mx=-1;
        for(auto x:piles)
            mx=max(mx,x);
        return mx;
    }
};