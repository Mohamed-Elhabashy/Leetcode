class BrowserHistory {
public:
    vector<string>History;
    int idx=-1;
    BrowserHistory(string homepage) {
        History.clear();
        History.push_back(homepage);
        idx=0;
    }
    
    void visit(string url){
        if(idx==History.size()-1){
            idx++;
            History.push_back(url);
        }
        else{
            History[++idx]=url;
            while(History.size()>idx+1)History.pop_back();
        }
    }
    
    string back(int steps) {
        if(idx-steps>=0)idx-=steps;
        else idx=0;
        return History[idx];
    }
    
    string forward(int steps) {
        if(idx+steps<History.size())idx+=steps;
        else idx=History.size()-1;
            
        return History[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */