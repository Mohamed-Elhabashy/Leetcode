class Solution {
public:
    string decodeAtIndex(string s, int k) {
        
        int n=s.size();
        cout<<k<<endl;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!(s[i]>='0' and s[i]<='9')){
                cnt++;
                if(cnt==k){
                    string ans;
                    ans+=s[i];
                    return ans;
                }
            }else{
                int dig=s[i]-'0';
                if(k<=(double)cnt*dig){
                    return decodeAtIndex(s,k-cnt);
                }
                cnt=cnt*dig;
            }
        }
        return "";
    }
};
