public class Solution {
    public string MergeAlternately(string word1, string word2) {
        string ans="";
        for(int i=0;i<Math.Min(word1.Length,word2.Length);i++){
            ans+=word1[i];
            ans+=word2[i];
        }
        if(word1.Length>word2.Length){
            ans+=word1.Substring(word2.Length);
        }
        
        if(word2.Length>word1.Length){
            ans+=word2.Substring(word1.Length);
        }
        return ans;
    }
}