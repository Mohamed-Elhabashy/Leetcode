class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> path;
    vector<string>ans;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto x:tickets){
            path[x[0]].push(x[1]);
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void dfs(string s){
        auto &pq=path[s];
        while(pq.size()){
            auto top=pq.top();
            pq.pop();
            dfs(top);
        }
        ans.push_back(s);
    }
};