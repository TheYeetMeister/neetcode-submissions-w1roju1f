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
    class DepthPair {
        TreeNode node;
        int depth;

        DepthPair(TreeNode node, int depth) {
            this.node = node;
            this.depth = depth;
        }
    }

    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        Stack<DepthPair> buf = new Stack<>();
        buf.push(new DepthPair(root, 1));
        int maxDepth = 1;

        while (!buf.isEmpty()) {
            DepthPair top = buf.pop();
            TreeNode node = top.node;

            if (node.left != null) {
                maxDepth = Math.max(top.depth + 1, maxDepth);
                buf.push(new DepthPair(node.left, top.depth + 1));
            }

            if (node.right != null) {
                maxDepth = Math.max(top.depth + 1, maxDepth);
                buf.push(new DepthPair(node.right, top.depth + 1));
            }
        }

        return maxDepth;
    }
}
