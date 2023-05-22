class Solution {
public:
    map<string,double>mp;
    map<string,vector<string>>graph;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<values.size();i++){
            string u=equations[i][0],v=equations[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            mp[u+">"+v]=values[i];
            mp[v+">"+u]=1/values[i];   
        }
        vector<double>ans;
        for(auto q:queries){
            string st=q[0],en=q[1];
            if(graph.count(st)==0 || graph.count(en)==0){
                ans.push_back(-1);
                continue;
            }
            if(st==en){
                ans.push_back(1);
                continue;
            }
            bool found=false;
            map<string,bool>vis;
            double val=1;
            dfs(st,en,vis,val,found);
            if(found)ans.push_back(val);
            else ans.push_back(-1);
        }
        return ans;
    }
    void dfs(string st,string en,map<string,bool>& vis,double& val,bool& found){
        vis[st]=1;
        for(auto ch:graph[st]){
            if(vis[ch]==0){
                val*=mp[st+">"+ch];
                if(ch==en){
                    found=1;
                    return ;
                }
                dfs(ch,en,vis,val,found);
                if(found)return ;
                else val/=mp[st+">"+ch];
            }
        }
    }
};