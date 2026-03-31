/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    private boolean dfs(TreeNode curr, TreeNode curr2) {
        if (curr == null && curr2 == null) {
            return true;
        } else if (curr == null || curr2 == null || curr.val != curr2.val) {
            return false;
        }

        return dfs(curr.left, curr2.left) && dfs(curr.right, curr2.right);
    }
    public boolean isSameTree(TreeNode p, TreeNode q) {
        return dfs(p, q);
    }
}
