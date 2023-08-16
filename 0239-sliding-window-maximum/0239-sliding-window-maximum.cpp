class Solution {
public:
    unordered_map<int,int>mp;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
            mp[nums[i]]++;
        }        
        vector<int>ans;
        ans.push_back(pq.top().first);
        for(int i=k,j=0;i<nums.size();i++,j++){
            mp[nums[j]]--;
            mp[nums[i]]++;
            while(pq.size() && pq.top().second<=j)pq.pop();
            pq.push({nums[i],i});
            ans.push_back(pq.top().first);           

        }
        return ans;
    }
};