/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        vector<ListNode*>v;
        while(head){
            v.push_back(head);
            head=head->next;
        }
        if(v.size()==0)return nullptr;
        if(v.size()==1)return v[0];
        
        for(int i=1;i<v.size();i+=2){
            swap(v[i],v[i-1]);
        }
        for(int i=0;i<v.size()-1;i++){
            v[i]->next=v[i+1];
        }
        v[v.size()-1]->next=nullptr;
        return v[0];
        
        
    }
};