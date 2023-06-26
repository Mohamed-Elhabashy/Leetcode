class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>>pq;
        int n=costs.size();
        int l=0,r=n-1;
        long long ans=0;
        if(2*candidates>=n){
            sort(costs.begin(),costs.end());
            for(int i=0;i<k;i++)ans+=costs[i];
        }
        else{
            while(candidates--){
                pq.push({-costs[l++],0});
                pq.push({-costs[r--],-1});
            }
            while(k--){
                auto p=pq.top();pq.pop();
                ans+=-p.first;
                if(l<=r){
                    if(p.second==0)
                        pq.push({-costs[l++],0});
                    else
                        pq.push({-costs[r--],-1});
                }
            }
        }
        return ans;
    }
};