public class Solution {
    public int LongestPalindrome(string s) {
        int[] frqSmall=new int[26];
        int[] frqCaptial=new int[26];
        
        foreach(var c in s){
            if(c>='a' && c<='z')
                frqSmall[c-'a']++;
            else
                frqCaptial[c-'A']++;
        }
        int counter=0;
        for(int i=0;i<26;i++){
            counter+=(frqSmall[i]%2==0?frqSmall[i]:frqSmall[i]-1);
            counter+=(frqCaptial[i]%2==0?frqCaptial[i]:frqCaptial[i]-1);
        }
        return counter + (s.Length-counter==0?0:1);
    }
}