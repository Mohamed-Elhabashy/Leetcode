class Solution {
public:
    string str="";
    vector<string> ans;
    bool checkVaild(string s){
        stack<char>st;
        for(auto c:s){
            if(c=='('){
                st.push(c);
                continue;
            }
            if(c==')' && st.size()>0 && st.top()=='('){
                st.pop();
                continue;
            }
           
            return false;   
        }
        return st.size()==0;
    }
    void solve(int n,int m){
        if(n==0 && m==0){
            if(checkVaild(str))ans.push_back(str);
            return;
        }
        if(n>0){
            str+='(';
            solve(n-1,m);
            str.pop_back();
        }
        if(m>0){
            str+=')';
            solve(n,m-1);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(n,n);
        return ans;
    }
};