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
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int longestDiameter = 0;

        Stack<TreeNode> buf = new Stack<>();
        buf.push(root);
        HashMap<TreeNode, Integer> branchLength = new HashMap<>();
        branchLength.put(null, 0);

        while (!buf.isEmpty()) {
            TreeNode top = buf.peek();

            if (branchLength.containsKey(top)) {
                int left = branchLength.get(top.left);
                int right = branchLength.get(top.right);
                longestDiameter = Math.max(left + right, longestDiameter);
                branchLength.put(top, Math.max(left, right) + 1);

                buf.pop();
            } else {
                branchLength.put(top, 0);
                
                if (top.left != null) {
                    buf.push(top.left);
                }

                if (top.right != null) {
                    buf.push(top.right);
                }
            }
        }

        return longestDiameter;
    }
}
