class Solution {
public:
    bool check(string s1,string& s){
        string x=s1;
        while(x.size()<s.size()){
            x+=s1;
            if(x==s)return 1;
        }
        return 0;
    }
    bool repeatedSubstringPattern(string s) {
        string tmp="";
        for(int i=0;i<s.size()-1;i++){
            tmp+=s[i];
            if(check(tmp,s))return 1;
        }
        return 0;
    }
};