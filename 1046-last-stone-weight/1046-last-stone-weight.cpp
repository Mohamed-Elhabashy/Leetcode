class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        
        for(auto v:stones)q.push(v);
        
         while(!q.empty()){
             if(q.size()==1){
                return q.top();
            }
            int mx=q.top();
            q.pop();
            int mn=q.top();
            q.pop();
            q.push(mx-mn);
        }
        return 0;
    }
};