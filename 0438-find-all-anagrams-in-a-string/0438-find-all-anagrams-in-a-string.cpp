class Solution {
public:
    bool ok(vector<int> &frq1,vector<int> &frq2) {
        for(int i=0; i<26; i++)
            if(frq1[i]!=frq2[i])
                return 0;

        return 1;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>frq2(26),frq1(26);
        for(auto c:p)
            frq2[c-'a']++;
        vector<int>ans;
        int sz1=s.size(),sz2=p.size();
        if(sz2>sz1)return ans;
        for(int i=0; i<sz2; i++)
            frq1[s[i]-'a']++;
        if(ok(frq1,frq2))
            ans.push_back(0);
        for(int i=0,j=sz2; j<sz1; i++,j++)
        {

            frq1[s[i]-'a']--;

            frq1[s[j]-'a']++;
            if(ok(frq1,frq2))
                ans.push_back(i+1);
        }

        return ans;
    }
};
