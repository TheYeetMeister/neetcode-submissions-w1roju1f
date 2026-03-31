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
    public int kthSmallest(TreeNode root, int k) {
        TreeNode curr = root;
        Stack<TreeNode> buf = new Stack<>();

        int count = 0;

        while (curr != null || !buf.isEmpty()) {
            while (curr != null) {
                buf.push(curr);

                curr = curr.left;
            }

            curr = buf.pop();

            if (++count == k) {
                return curr.val;
            }

            curr = curr.right;
        }

        return -1;
    }
}
