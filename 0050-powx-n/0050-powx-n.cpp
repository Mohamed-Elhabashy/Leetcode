class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        double ans=solve(x,abs(n));
        if(n>0)return ans;
        return 1/ans;
    }
    double solve(double x,int n){
        if(n==1)return x;
        double ans=myPow(x,n/2);
        return ans*ans*(n&1?x:1);
    }
};