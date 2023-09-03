class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<char>v1,v2;
        for(int i=0;i<s1.size();i++){
            if(i&1)v1.push_back(s1[i]);
            else v2.push_back(s1[i]);
        }
        vector<char>x1,x2;
        for(int i=0;i<s2.size();i++){
            if(i&1)x1.push_back(s2[i]);
            else x2.push_back(s2[i]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(x1.begin(),x1.end());
        sort(x2.begin(),x2.end());
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=x1[i])return 0;
        }for(int i=0;i<v2.size();i++){
            if(v2[i]!=x2[i])return 0;
        }
        return 1;
    }
};