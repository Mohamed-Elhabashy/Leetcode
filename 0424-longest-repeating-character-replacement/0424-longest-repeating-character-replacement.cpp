class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>frq(26);
        int st=0;
        int mx=0,ans=0;
        for(int i=0;i<s.size();i++){
            frq[s[i]-'A']++;
            mx=max(mx,frq[s[i]-'A']);
            if(i-st+1 <= mx+k){
                ans=max(ans,i-st+1);
            }
            else{
                frq[s[st]-'A']--;
                st++;
            }
        }
        return ans;
    }
};