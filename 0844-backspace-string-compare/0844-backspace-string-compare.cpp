class Solution {
public:
    bool backspaceCompare(string s, string s1) {
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(ans.size()>0)
                ans.pop_back();
            }
            else
                ans+=s[i];
        }
        string ans1="";
        for(int i=0;i<s1.length();i++){
            if(s1[i]=='#'){
                if(ans1.size()>0)
                ans1.pop_back();
            }
            else
                ans1+=s1[i];
        }
        return ans==ans1;
}
};