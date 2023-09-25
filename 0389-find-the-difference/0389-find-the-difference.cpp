class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        for(auto x:s)mp[x]++;
        for(auto x:t){
            mp[x]--;
            if(mp[x]==-1)return x;
        }
        return 'x';
    }
};