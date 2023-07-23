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
    unordered_map<int,vector<TreeNode*>>mp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0){
            return {};
        }
        if(n==1)return {new TreeNode()};
        if(mp.count(n))return mp[n];
        vector<TreeNode*>ans;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*>left=allPossibleFBT(i);
            vector<TreeNode*>right=allPossibleFBT(n-i-1);
            for(auto node:left){
                for(auto r:right){
                    TreeNode* root = new TreeNode(0,node,r);
                    ans.push_back(root);
                }
            }
        }
        return mp[n]=ans;
    }
};