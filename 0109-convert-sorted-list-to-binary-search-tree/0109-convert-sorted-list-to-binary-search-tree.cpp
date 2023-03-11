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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(ListNode* head,int n){
        if(n<=0)return nullptr;
        int mid=n/2;
        ListNode* tmp=head;
        while(mid--){
            tmp=tmp->next;
        }
        TreeNode* ans=new TreeNode(tmp->val,solve(head,n/2),solve(tmp->next,n-(n/2)-1));
        return ans;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)return nullptr;
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        return solve(head,n);
    }
};