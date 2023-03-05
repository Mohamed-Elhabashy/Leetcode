class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mp;
        map<char,bool>taken;
        for(int i=0;i<s.size();i++){
            if((mp.count(s[i]) && mp[s[i]]!=t[i]) || (mp[s[i]]!=t[i] && taken[t[i]]==1)){
                cout<<i<<endl;
                return 0;
            }
            mp[s[i]]=t[i];
            taken[t[i]]=1;
        }
        return 1;
    }
};