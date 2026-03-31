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
    int res;
    private int dfs(TreeNode curr) {
        if (curr == null) {
            return 0;
        }

        int left = Math.max(dfs(curr.left), 0);
        int right = Math.max(dfs(curr.right), 0);

        res = Math.max(curr.val + left + right, res);

        return curr.val + Math.max(left, right);
    }

    public int maxPathSum(TreeNode root) {
        res = Integer.MIN_VALUE;

        dfs(root);

        return res;
    }
}
