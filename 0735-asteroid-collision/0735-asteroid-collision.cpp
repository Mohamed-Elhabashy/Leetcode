class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto x:asteroids){
            bool f=1;
            while(!st.empty() && st.top()>0 && x<0){
                if(abs(x)>abs(st.top())){
                    st.pop();
                    continue;
                }
                else if(abs(x)==abs(st.top()))st.pop();
                f=0;
                break;
            }
            if(f)st.push(x);
        }
        vector<int>ans(st.size());
        for(int i=st.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};