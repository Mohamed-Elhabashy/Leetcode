class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=0;i<31;i++){
            int d1=(((1<<i)&a)>0),d2=(((1<<i)&b)>0);
            int t=(((1<<i)&c)>0);
            if((d1|d2)==t)continue;
            if((d1|d2)==0){
                ans++;
            }
            else{
                ans+=(d1==1)+(d2==1);
            }
        }
        return ans;
    }
};