class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)     {
        vector<pair<int,int>>v;
        for(int i=0;i<capital.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.rbegin(),v.rend());
        priority_queue<int>pq;
        while(k--){
            while(v.size() && v.back().first<=w){
                pq.push(v.back().second);
                v.pop_back();
            }
            if(pq.empty())
                break;
            w+=pq.top();
            pq.pop();
            
        }
        return w;
    }
};