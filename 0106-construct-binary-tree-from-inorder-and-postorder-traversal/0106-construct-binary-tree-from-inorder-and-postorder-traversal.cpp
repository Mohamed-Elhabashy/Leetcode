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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int sz=inorder.size();
        return solve(0,sz-1,inorder,postorder,sz);
    }
    TreeNode* solve(int i,int j,vector<int>& inorder,vector<int>& postorder,int& rootvalue){
        if(i>j)return nullptr;
        rootvalue--;
        if(i==j)return new TreeNode(inorder[i]);
        
        TreeNode* root=new TreeNode(postorder[rootvalue]);
        int idx=-1;
        for(int x=i;x<=j;x++){
            if(postorder[rootvalue]==inorder[x])
            {
                idx=x;
                break;
            }
        }
        root->right=solve(idx+1,j,inorder,postorder,rootvalue);
        root->left=solve(i,idx-1,inorder,postorder,rootvalue);
        return root;
    }
};