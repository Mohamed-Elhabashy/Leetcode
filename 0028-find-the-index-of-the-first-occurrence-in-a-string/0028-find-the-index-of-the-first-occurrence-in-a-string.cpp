class Solution {
public:
    bool solve(int i,string& haystack, string& needle){
        if(i+needle.size()>haystack.size())return 0;
        for(int x=i,y=0;y<needle.size();x++,y++){
            if(haystack[x]!=needle[y])return 0;
        }
        return 1;
    }
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++){
            if(solve(i,haystack,needle))return i;
        }
        return -1;
    }
};