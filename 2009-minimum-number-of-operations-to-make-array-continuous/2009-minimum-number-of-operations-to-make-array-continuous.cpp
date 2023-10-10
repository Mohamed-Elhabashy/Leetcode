class Solution {
public:
    int minOperations(vector<int>& nums) {
        int sz=nums.size();
        unordered_map<int,bool>mp;
        vector<int>v;
        for(auto x:nums){
            if(mp[x]==1)continue;
            v.push_back(x);
            mp[x]=1;
        }
        sort(v.begin(),v.end());
        int ans=sz;
        for(int i=0;i<v.size();i++){
            int left=v[i];
            int right=v[i]+sz-1;
            int index=upper_bound(v.begin(),v.end(),right)-v.begin();
            ans=min(ans,sz-(index-i));
        }
        return ans;
    }
};