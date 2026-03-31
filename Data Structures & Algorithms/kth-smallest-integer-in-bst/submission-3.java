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
    int count;
    int k;
    int val;

    private void dfs(TreeNode curr) {
        if (curr == null) {
            return;
        }

        dfs(curr.left);
        if (++count == k) {
            val = curr.val;
            return;
        }
        dfs(curr.right);
    }

    public int kthSmallest(TreeNode root, int k) {
        this.k = k;
        count = 0;

        dfs(root);

        return val;
    }
}
