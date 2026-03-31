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
    public boolean isBalanced(TreeNode root) {
        if (root == null) {
            return true;
        }

        Stack<TreeNode> buf = new Stack<>();
        HashMap<TreeNode, Integer> height = new HashMap<>();
        height.put(null, 0);
        buf.push(root);

        while (!buf.empty()) {
            TreeNode top = buf.peek();

            if (!height.containsKey(top)) {
                height.put(top, 0);
                
                if (top.left != null) {
                    buf.push(top.left);
                }

                if (top.right != null) {
                    buf.push(top.right);
                }
            } else {
                int left = height.get(top.left);
                int right = height.get(top.right);

                if (Math.abs(left - right) > 1) {
                    return false;
                }

                height.put(top, 1 + Math.max(left, right));
                buf.pop();
            }
        }

        return true;
    }
}
