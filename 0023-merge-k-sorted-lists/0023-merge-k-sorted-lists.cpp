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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<pair<int,ListNode*>>vec;
        for(auto head:lists){
            while(head){
                vec.push_back({head->val,head});
                head=head->next;
            }
        }
        if(vec.empty())return nullptr;
        sort(vec.begin(),vec.end());
        return solve(0,vec);
    }
    ListNode* solve(int i,vector<pair<int,ListNode*>>& v){
        if(i==v.size())return nullptr;
        ListNode* cur = v[i].second;
        cur->next=solve(i+1,v);
        return cur;
    }
};