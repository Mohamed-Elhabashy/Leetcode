class Solution {
public:
    long long getSum(long long n){
        return (n*(n+1))/2;
    }
    int maxValue(int n, int index, int maxSum) {
        int l=1,r=maxSum,mid;
        while(l<r){
            mid=(l+r+1)/2;
            if(ok(mid,n,index,maxSum))l=mid;
            else r=mid-1;
        }
        return l;
    }
    bool ok(int mid,int n,int index,int maxSum){
        long long sum=0;
         
        if(index==0)sum+=mid;
        else{
            if(index+1>=mid){
                sum+=getSum(mid);
                sum+=index-mid+1;
            }
            else{
                sum+=getSum(mid);
                sum-=getSum(mid-(index+1));
            }
        }
        
        if(index!=n-1){
            if(n-1-index+1>=mid){
                sum+=getSum(mid)-mid;
                sum+=(n-1-index+1)-mid;
            }
            else{
                sum+=getSum(mid);
                sum-=getSum(mid-(n-1-index+1))+mid;
            }
        }
        return sum<=maxSum;   
    }
    
};