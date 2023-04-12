class Solution {
public:
    string simplifyPath(string path) {
        vector<string>v;
        int sz=path.size();
        string p="";
        for(int i=0;i<sz;i++){
            if(path[i]=='/'){
                if(p.size())v.push_back(p);
                p="";
                continue;
            }
            if(path[i]=='.' && p==""){
                string str="";
                while(i<sz && path[i]=='.'){
                    str+='.';i++;
                }
                i--;
                if(str.size()<=2){
                    if(i+1==sz || (path[i+1]=='/')){
                        if(str.size()==2 && v.size())v.pop_back();
                    }
                    else
                        p+=str;
                }
                else if(str.size()>=3)p+=str;
                continue;
            }
            p+=path[i];
        }
        if(p.size())v.push_back(p);
        string ans="";
        for(auto p:v){
            ans+="/";
            ans+=p;
        }
        if(ans=="")ans+="/";
        return ans;
    }
};