class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped){
        stack<int>st;
        int n=pushed.size(),i=0;
        for(int j=0;j<n;j++){
            while(i<n){
                if(st.size() && st.top()==popped[j])break;
                st.push(pushed[i++]);
            }
            if(st.top()==popped[j])st.pop();
            else return 0;
        }
        return 1;
    }
};