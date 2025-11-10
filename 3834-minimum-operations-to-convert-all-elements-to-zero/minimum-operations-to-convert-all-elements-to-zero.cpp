class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        stack<int>st;
        for(auto x:nums){
            while(!st.empty() && st.top()>x)st.pop();
            if(x==0)continue;
            if(st.empty() || st.top() < x){
                ans++;
                st.push(x);
            }
        }
        return ans;
    }
};