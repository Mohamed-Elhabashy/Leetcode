class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        for(auto c:s){
            if(c==']'){
                string x="";
                while(st.top()!='['){
                    x+=st.top();
                    st.pop();
                }
                st.pop();
                string repeat="";
                while(st.size() && st.top()>='0' && st.top()<='9'){
                    repeat+=st.top();
                    st.pop();
                }
                reverse(repeat.begin(),repeat.end());
                int NumberRepeat=stoi(repeat);
                while(NumberRepeat--){
                    for(int i=x.size()-1;i>=0;i--)st.push(x[i]);
                }
            }
            else{
                st.push(c);
            }
        }
        string ans="";
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};