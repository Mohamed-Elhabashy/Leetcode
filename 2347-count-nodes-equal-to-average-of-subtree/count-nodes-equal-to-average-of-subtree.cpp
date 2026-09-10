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
    int ans=0;
    pair<int,int> sum(TreeNode* root){
        if(root == nullptr)return {0,0};
        auto left = sum(root->left);
        auto right = sum(root->right);
        int total_sum = root->val + left.first + right.first;
        int children = 1 + left.second + right.second;
        if(total_sum/children == root->val )ans++;
        return {total_sum,children};
    }
    int averageOfSubtree(TreeNode* root) {
        auto x = sum(root);
        return ans;
    }
};