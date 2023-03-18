class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto x:words)mp[x]++;
        vector<string>frequency[501];
        for(auto m:mp)
            frequency[m.second].push_back(m.first);
        vector<string>ans;
        for(int i=500;i>=1 && k ;i--){
            if(frequency[i].size()==0)continue;
            sort(frequency[i].begin(),frequency[i].end());
            for(int j=0;j<frequency[i].size() && k ;j++,k--){
                ans.push_back(frequency[i][j]);
            }
        }
        return ans;
    }
};