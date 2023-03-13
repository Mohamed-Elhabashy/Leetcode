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
    bool isValidBST(TreeNode* root) {
        return solve(root,nullptr,nullptr);
    }
    bool solve(TreeNode* root,TreeNode* mn,TreeNode* mx){
        if(root==nullptr)return true;
        if((mn!=nullptr && root->val>=mn->val) || (mx!=nullptr && root->val<=mx->val))
            return false;
        return solve(root->right,mn,root) && solve(root->left,root,mx);
    }
};