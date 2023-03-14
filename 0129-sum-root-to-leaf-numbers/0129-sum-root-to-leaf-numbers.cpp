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
    int sumNumbers(TreeNode* root) {
        int sumleaf=0;
        solve(root,0,sumleaf);
        return sumleaf;
    }
    void solve(TreeNode* root,int number,int& sumleaf){
        if(root==nullptr)return ;
        if(root->right==nullptr && root->left==nullptr){
            number=(number*10)+root->val;
            sumleaf+=number;
            return ;
        }
        solve(root->right,number*10+root->val,sumleaf);
        solve(root->left,number*10+root->val,sumleaf);
    }
};