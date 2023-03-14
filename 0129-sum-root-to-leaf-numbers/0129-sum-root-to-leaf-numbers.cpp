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
    vector<int>leaf;
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        int ans=0;
        for(auto x:leaf)ans+=x;
        return ans;
    }
    void solve(TreeNode* root,int number){
        if(root==nullptr)return ;
        if(root->right==nullptr && root->left==nullptr){
            number=(number*10)+root->val;
            leaf.push_back(number);
            return ;
        }
        solve(root->right,number*10+root->val);
        solve(root->left,number*10+root->val);
    }
};