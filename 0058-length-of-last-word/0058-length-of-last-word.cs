public class Solution {
    public int LengthOfLastWord(string s) {
        int idx=s.Length-1;
        while(idx>=0 && s[idx]==' ')idx--;
        int ans=0;
        while(idx>=0 && s[idx]!=' '){idx--;ans++;}
        return ans;
    }
}