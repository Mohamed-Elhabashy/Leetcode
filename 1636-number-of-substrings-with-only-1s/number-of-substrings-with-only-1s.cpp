class Solution {
public:
    int MOD=1e9+7;
    int numSub(string s) {
        int ans=0;
        long long counter=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                counter=0;
                while(i<s.size() && s[i]=='1'){
                    i++;
                    counter++;
                }

                ans+=solve(counter);
                ans%=MOD;
            }
        }
        return ans;
    }
    long long solve(long long x){
        return ((x*(x+1))/2)%MOD;
    }
};