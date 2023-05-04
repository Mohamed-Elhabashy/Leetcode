class Solution {
public:
    string predictPartyVictory(string str) {
        queue<int>r,d;
        int n=str.size();
        for(int i=0;i<n;i++){
            if(str[i]=='R')r.push(i);
            else d.push(i);
        }
        while(r.size() && d.size()){
            int i=r.front(),j=d.front();
            r.pop();d.pop();
            i<j?r.push(i+n):d.push(i+n);
        }
        return (r.empty()?"Dire":"Radiant");
    }
};