class Solution {
public:
    string str[10];
    vector<string>ans;
    string cur="";
    void build(){
        char c='a';
        for(int i=2;i<=6;i++){
            str[i]=c++;
            str[i]+=c++;
            str[i]+=c++;
        }
        str[7]="pqrs";
        str[8]="tuv";
        str[9]="wxyz";
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return ans;
        build();
        solve(0,digits);
        return ans;
    }
    void solve(int i,string& d){
        if(i==d.size()){
            ans.push_back(cur);
            return ;
        }
        string& s=str[d[i]-'0'];
        for(int x=0;x<s.size();x++){
            cur+=s[x];
            solve(i+1,d);
            cur.pop_back();
        }
    }
};