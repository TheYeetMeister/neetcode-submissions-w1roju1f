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
    private boolean dfs(TreeNode curr, int min, int max) {
        if (curr == null) {
            return true;
        } else if (curr.val > min && curr.val < max) {
            return dfs(curr.left, min, curr.val) && dfs(curr.right, curr.val, max);
        } else {
            return false;
        }
    }
    public boolean isValidBST(TreeNode root) {
        return dfs(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
}
