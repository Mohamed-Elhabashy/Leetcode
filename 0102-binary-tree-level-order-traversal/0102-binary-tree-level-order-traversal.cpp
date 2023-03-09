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
    vector<vector<int>>ans{2000};
    int maxLevel=-1;
    void dfs(TreeNode* root,int level){
        if(root==nullptr)return ;
        maxLevel=max(maxLevel,level);
        ans[level].push_back(root->val);
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root,0);
        ans.resize(maxLevel+1);
        return ans;
    }
};