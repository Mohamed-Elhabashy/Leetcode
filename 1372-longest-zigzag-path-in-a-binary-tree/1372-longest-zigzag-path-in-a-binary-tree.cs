/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    int ans=0;
    public int LongestZigZag(TreeNode root) {
        if(root.left is null && root.right is null)return 0;
        solve(root.left,false,1);
        solve(root.right,true,1);
        return ans;
    }
    void solve(TreeNode root,bool Goleft,int len){
        if(root==null)return ;
        ans=Math.Max(ans,len);
        if(Goleft){
            solve(root.left,false,len+1);
            solve(root.right,true,1);
        }
        else{
            solve(root.right,true,len+1);
            solve(root.left,false,1);
        }
    }
}