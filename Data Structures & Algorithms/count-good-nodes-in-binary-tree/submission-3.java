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
    public int goodNodes(TreeNode root) {
        int count = 0;

        Stack<Pair<TreeNode, Integer>> buf = new Stack<>();
        TreeNode curr = root;
        int prevMax = root.val;

        while (curr != null || !buf.isEmpty()) {
            if (curr == null) {
                Pair<TreeNode, Integer> top = buf.pop();

                curr = top.getKey();
                prevMax = top.getValue();
            }

            if (curr.val >= prevMax) {
                prevMax = curr.val;
                ++count;
            }

            if (curr.right != null) {
                buf.push(new Pair(curr.right, prevMax));
            }

            curr = curr.left;
        }

        return count;
    }
}
