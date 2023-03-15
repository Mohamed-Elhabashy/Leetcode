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
        vector<TreeNode*>vec{root};
        bool ans=false;
        for(int i=0;i<vec.size();i++){
            TreeNode* node=vec[i];
            if(node!=nullptr){
                vec.push_back(node->left);
                vec.push_back(node->right);
                if(ans)
                    return false;
            }
            else
                ans=true;
        }
        return ans;
    }
};