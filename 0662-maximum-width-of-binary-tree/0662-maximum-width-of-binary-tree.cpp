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
    map<int,int>mp;
    int ans=1;
    int widthOfBinaryTree(TreeNode* root) {
        solve(root,1,1);
        return ans; 
    }
    void solve(TreeNode* root,unsigned long long index,int level){
        if(root==nullptr)return ;
        if(mp.count(level)==0)mp[level]=index;
        ans=max(ans,(int)(index-mp[level]+1));
        solve(root->left,index*2-1,level+1);
        solve(root->right,index*2,level+1);
    }
};