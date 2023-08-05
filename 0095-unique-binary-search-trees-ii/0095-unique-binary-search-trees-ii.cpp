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
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
    vector<TreeNode*> solve(int i,int j){
        vector<TreeNode*> ans;
        if(i>j){
            ans.push_back(NULL);
            return ans;
        }
        for(int x=i;x<=j;x++)
        {
            vector<TreeNode*> left=solve(i,x-1);
            vector<TreeNode*> right=solve(x+1,j);
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root=new TreeNode(x,l,r);
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};