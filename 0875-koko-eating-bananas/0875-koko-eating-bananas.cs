public class Solution {
    public int MinEatingSpeed(int[] piles, int h) {
        int l=1,r=Maxelemnt(piles);
        while(l<r){
            int mid=(l+r)/2;
            if(ok(mid,piles,h))
                r=mid;
            else 
                l=mid+1;
        }
        return l;
    }
    int Maxelemnt(int[] piles){
        int mx=-1;
        foreach(var num in piles)
            mx=Math.Max(mx,num);
        return mx;
    }
    bool ok(int k,int[] piles,int h){
        int counter=0;
        foreach(var num in piles){
            counter+=(num/k)+(num%k==0?0:1);
        }
        return counter<=h;
    }
}