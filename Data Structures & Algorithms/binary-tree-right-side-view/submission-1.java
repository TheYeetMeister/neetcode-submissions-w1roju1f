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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();

        if (root == null) {
            return res;
        }

        Queue<TreeNode> buf = new LinkedList<>();
        buf.add(root);

        while (!buf.isEmpty()) {
            int size = buf.size();
            TreeNode curr = null;

            for (int i = 0; i < size; ++i) {
                curr = buf.poll();

                if (curr.left != null) {
                    buf.add(curr.left);
                }

                if (curr.right != null) {
                    buf.add(curr.right);
                }
            }

            res.add(curr.val);
        }

        return res;
    }
}
