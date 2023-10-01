class Solution {
public:
    string reverseWords(string s) {
       string ans="";
        string x="";
        for(auto c:s){
            if(c==' '){
                reverse(x.begin(),x.end());
                ans+=(ans==""?"":" ")+x;
                x="";
            }
            else
                x+=c;
        }
        reverse(x.begin(),x.end());
        ans+=(ans==""?"":" ")+x;
        return ans;
    }
};