class Trie{
    struct Node{
        bool isLeaf;
        vector<int>next;
        Node(){
            isLeaf=0;
            next = vector<int>(26,-1);
        }
    };
    vector<Node>trie;
    public:
        Trie(){
            trie.push_back(Node());
        }
        void insert(string str){
            int rootIndex=0;
            for(int i=0;i<str.size();i++){
                if(trie[rootIndex].next[str[i]-'a']==-1){
                    trie[rootIndex].next[str[i]-'a']=trie.size();
                    trie.push_back(Node());
                }
                rootIndex=trie[rootIndex].next[str[i]-'a'];
            }
            trie[rootIndex].isLeaf=1;
        }
        bool searchHelp(string& str,int rootIndex,int strIndex){
            if(rootIndex==-1)return false;
            if(strIndex==str.size())return trie[rootIndex].isLeaf;
            if(str[strIndex]!='.')
                return searchHelp(str,trie[rootIndex].next[str[strIndex]-'a'],strIndex+1);
            for(int i=0;i<26;i++){
                if(searchHelp(str,trie[rootIndex].next[i],strIndex+1))
                    return true;
            }
            return false;
        }
        bool search(string str){
            return searchHelp(str,0,0);
        }
};

class WordDictionary {
public:
    Trie trie;
    WordDictionary() {
        trie = Trie();
    }
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */