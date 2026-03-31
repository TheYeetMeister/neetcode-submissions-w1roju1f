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
    private void invertNode(TreeNode curr) {
        if (curr != null) {
            invertNode(curr.left);
            invertNode(curr.right);

            TreeNode tmp = curr.left;
            curr.left = curr.right;
            curr.right = tmp;
        }
    }
    public TreeNode invertTree(TreeNode root) {
        invertNode(root);
        return root;
    }
}
