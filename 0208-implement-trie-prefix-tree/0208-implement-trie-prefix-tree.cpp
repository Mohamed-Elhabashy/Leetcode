class Trie {
public:
    unordered_map<string,bool>mp;
    Trie() {
        mp.clear();
    }
    
    void insert(string word) {
        mp[word]=1;
    }
    
    bool search(string word) {
        if(mp.count(word))return true;
        return false;
    }
    bool startsWith(string prefix) {
        for(auto m:mp){
            int idx=0;
            for(char c:m.first){
                if(idx<prefix.size() && c==prefix[idx]){
                    idx++;
                }
                else
                    break;
            }
            if(idx==prefix.size())return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */