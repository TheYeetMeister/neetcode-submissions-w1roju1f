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
    private int dfs(TreeNode curr, int prevMax) {
        if (curr == null) {
            return 0;
        }

        if (curr.val < prevMax) {
            return dfs(curr.left, prevMax) + dfs(curr.right, prevMax);
        } else {
            return 1 + dfs(curr.left, curr.val) + dfs(curr.right, curr.val);
        }
    }
    public int goodNodes(TreeNode root) {
        return dfs(root, root.val);
    }
}
