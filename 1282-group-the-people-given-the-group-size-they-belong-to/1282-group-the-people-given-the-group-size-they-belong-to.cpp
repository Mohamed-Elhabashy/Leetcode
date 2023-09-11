class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int,int>>v;
        for(int i=0;i<groupSizes.size();i++){
            v.push_back({groupSizes[i],i});
        }
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        for(int i=0;i<v.size();i++){
            vector<int>tmp;
            int x=v[i].first;
            for(int j=i;j<i+x;j++){
                tmp.push_back(v[j].second);
            }
            ans.push_back(tmp);
            i=i+x-1;
        }
        return ans;
    }
};