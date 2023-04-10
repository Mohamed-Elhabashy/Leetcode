class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto c:s){
            if(c==']' && st.size()>0 && st.top()=='['){
                st.pop();
            }
            else if(c=='}' && st.size()>0 && st.top()=='{'){
                st.pop();
            }
            else if(c==')' && st.size()>0 && st.top()=='('){
                st.pop();
            }
            else if(c=='('||c=='[' || c=='{')st.push(c);
            else return false;
        }
        if(st.size()>0)return false;
        return true;
    }
};