class Solution {
public:
    int maxOperations(string s) {
        int ans=0,one=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')one++;
            else {
                while(i+1<s.size() && s[i+1]=='0'){
                    i++;
                }
                ans+=one;
            }
        }
        return ans;
    }
};