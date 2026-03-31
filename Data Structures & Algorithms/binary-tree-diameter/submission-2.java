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
    int longestDiameter;

    private int getLongestBranch(TreeNode curr) {
        if (curr == null) {
            return 0;
        }

        int left = getLongestBranch(curr.left);
        int right = getLongestBranch(curr.right);
        longestDiameter = Math.max(left + right, longestDiameter);

        return Math.max(left, right) + 1;
    }

    public int diameterOfBinaryTree(TreeNode root) {
        longestDiameter = 0;

        getLongestBranch(root);

        return longestDiameter;
    }
}
