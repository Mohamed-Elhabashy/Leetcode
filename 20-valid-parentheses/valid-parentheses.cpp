class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto c:s){
            if(c=='(' || c=='[' || c=='{'){
                st.push(c);
                continue;
            }
            if(c==')' && st.size()>0 && st.top()=='('){
                st.pop();
                continue;
            }
            if(c==']' && st.size()>0 && st.top()=='['){
                st.pop();
                continue;
            }
            if(c=='}' && st.size()>0 && st.top()=='{'){
                st.pop();
                continue;
            }
            return false;   
        }
        return st.size()==0;
    }
};