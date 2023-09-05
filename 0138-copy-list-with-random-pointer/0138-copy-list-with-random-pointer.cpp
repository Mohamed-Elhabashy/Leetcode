/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node* copyRandomList(Node* head) {
        if(head==nullptr)return NULL;
        return solve(head);
    }
    Node* solve(Node* node){
        if(mp[node])return mp[node];
        Node* tmp=new Node(node->val);
        mp[node]=tmp;
        if(node->next)tmp->next=solve(node->next);
        if(node->random)tmp->random=solve(node->random);
        return tmp;
    }
};