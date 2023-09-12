class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(),s.end());
        cout<<s<<endl;
        unordered_map<char,int>mp;
        for(auto x:s)mp[x]++;
        int ans=0;
        for(char i='a';i<='z';i++){
            while(true){
                bool flag=true;
                for(char j='a';j<='z';j++){
                    if(mp[i]==0){
                        flag=true;
                        break;
                    }
                    if(i==j)continue;
                    if(mp[i]==mp[j]){
                        flag=false;
                        mp[i]--;
                        ans++;
                    }
                }
                if(flag)break;
            }
        }
        return ans;
    }
};