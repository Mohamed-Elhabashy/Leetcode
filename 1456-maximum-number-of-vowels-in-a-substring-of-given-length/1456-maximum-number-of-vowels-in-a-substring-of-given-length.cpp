class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                cnt++;
        }
        int ans=cnt;
        for(int i=k,j=0;i<s.size();i++,j++){
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')
                cnt--;
            
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                cnt++;
            ans=max(ans,cnt);
        }
        return ans;
    }
};