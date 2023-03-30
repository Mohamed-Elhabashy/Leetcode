class Solution {
public:
    unordered_map<string,bool>ans;
    bool isScramble(string s1, string s2){
        if(s1==s2)return 1;
        if(s1.size()==1)return 0;
        string key=s1+s2;
        if(ans.count(key))return ans[key];
        int sz=s1.size();
        ans[key]=0;
        for(int i=1;i<sz;i++){
            ans[key]|=( isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)) );
            ans[key]|=( isScramble(s1.substr(i),s2.substr(0,sz-i)) && isScramble(s1.substr(0,i),s2.substr(sz-i)) );
        }
        return ans[key];
    }
};