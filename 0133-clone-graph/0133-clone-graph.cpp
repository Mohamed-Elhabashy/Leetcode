/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*>mp;
    Node* cloneGraph(Node* node) {
        if(node==nullptr)return nullptr;
        if(node->neighbors.size()==0)
            return new Node(1);
        
        dfs(node);
        return mp[1];
    }
    void dfs(Node* node){
        mp[node->val]=new Node(node->val);
        for(auto v:node->neighbors){
            if(!mp.count(v->val))
                dfs(v);
            mp[node->val]->neighbors.push_back(mp[v->val]);
        }
    }
};