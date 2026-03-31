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
    class NodeParameters {
        TreeNode node;
        Integer min;
        Integer max;

        public NodeParameters(TreeNode node, Integer min, Integer max) {
            this.node = node;
            this.min = min;
            this.max = max;
        }

        public boolean isNode() {
            return node != null;
        }

        public boolean isValid() {
            return (min == null || min < node.val) && (max == null || max > node.val);
        }
    }
    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }

        Stack<NodeParameters> buf = new Stack<>();
        NodeParameters curr = new NodeParameters(root, null, null);

        while (curr.isNode() || !buf.isEmpty()) {
            if (!curr.isNode()) {
                curr = buf.pop();
            }

            if (!curr.isValid()) {
                return false;
            }

            if (curr.node.right != null) {
                buf.push(new NodeParameters(curr.node.right, curr.node.val, curr.max));
            }

            curr = new NodeParameters(curr.node.left, curr.min, curr.node.val);
        }

        return true;
    }
}
