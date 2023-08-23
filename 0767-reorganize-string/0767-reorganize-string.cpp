class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>mp;
        for(auto x:s)mp[x]++;
        priority_queue<pair<int,char>>pq;
        for(auto m:mp){
            pq.push({m.second,m.first});
        }
        string ans="";
        while(pq.size()){
            auto x=pq.top();
            pq.pop();
            if(ans=="" || ans.back()!=x.second){
                ans+=x.second;
                if(x.first-1>0)
                pq.push({x.first-1,x.second});
            }
            else{
                if(pq.empty())return "";
                auto y=pq.top();pq.pop();
                ans+=y.second;
                if(y.first-1)
                    pq.push({y.first-1,y.second});
                pq.push(x);
            }
        }
        return ans;
    }
};