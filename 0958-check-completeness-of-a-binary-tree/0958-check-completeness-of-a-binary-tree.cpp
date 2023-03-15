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
    bool isCompleteTree(TreeNode* root) {
        int h=CountLevel(root);
        vector<int>LastLevel;
        bool ans= solve(root,1,h,LastLevel);
        if(LastLevel.size()==0)return ans;
        for(int i=0;i<LastLevel.size()-1;i++){
            if(LastLevel[i]==0 && LastLevel[i+1]!=0)return false;
        }
        return ans;
    }
    int CountLevel(TreeNode* root){
        if(root==nullptr)return 0;
        return 1+max(CountLevel(root->left),CountLevel(root->right));
    }
    bool solve(TreeNode* root,int curlevel,int h,vector<int>& LastLevel){
        if(root==nullptr)return true;
        if(curlevel<h-1 && (root->left==nullptr || root->right==nullptr))return false;
        if(curlevel==h-1){
            LastLevel.push_back(root->left==nullptr?0:root->left->val);
            LastLevel.push_back(root->right==nullptr?0:root->right->val);
        }
        
        return solve(root->left,curlevel+1,h,LastLevel) && solve(root->right,curlevel+1,h,LastLevel);
    }
};