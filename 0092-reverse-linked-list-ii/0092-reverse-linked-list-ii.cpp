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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<ListNode*>arr;
        while(head){
            arr.push_back(head);
            head=head->next;
        }
        cout<<1<<endl;
        reverse(arr.begin()+left-1,arr.begin()+right);
        cout<<2<<endl;
        for(int i=0;i<arr.size()-1;i++){
           arr[i]->next=arr[i+1];
        }
        arr[arr.size()-1]->next=NULL;
        return arr[0];
    }
};