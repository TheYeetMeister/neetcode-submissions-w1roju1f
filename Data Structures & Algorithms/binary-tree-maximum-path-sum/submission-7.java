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
    public int maxPathSum(TreeNode root) {
        int res = Integer.MIN_VALUE;

        Map<TreeNode, Integer> pathLength = new HashMap<>();
        pathLength.put(null, 0);

        Stack<TreeNode> buf = new Stack<>();
        buf.push(root);

        while (!buf.isEmpty()) {
            TreeNode topNode = buf.peek();
            if (pathLength.containsKey(topNode)) {
                int leftLength = pathLength.get(topNode.left);
                int rightLength = pathLength.get(topNode.right);

                res = Math.max(topNode.val + leftLength + rightLength, res);

                pathLength.put(topNode, Math.max(topNode.val + Math.max(leftLength, rightLength), 0));
                
                buf.pop();
            } else {
                pathLength.put(topNode, 0);

                if (topNode.left != null) {
                    buf.push(topNode.left);
                }

                if (topNode.right != null) {
                    buf.push(topNode.right);
                }
            }
        }

        return res;
    }
}
