class Solution {
public:
    int largestVariance(string s) {
        unordered_map<char,int>mp;
        for(auto x:s)mp[x]++;
        int ans=0;
        for(int z=1;z<=2;z++){
            for(char i='a';i<='z';i++)
            {
                for(char j='a';j<='z';j++)
                {
                    if(i==j || mp[i]==0 || mp[j]==0)continue;

                    int first=0,second=0;
                    for(auto c:s){
                        if(c!=i && c!=j)continue;
                        if(c==i)first++;
                        if(c==j)second++;
                        if(second>first)first=second=0;
                        if(first>second && second>0)ans=max(ans,first-second);
                    }
                }
            }
            reverse(s.begin(),s.end());
        }
        return ans;
    }
};