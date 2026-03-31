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
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }

        Stack<TreeNode> buf = new Stack<>();
        buf.push(root);
        HashSet<TreeNode> visited = new HashSet<>();

        while (!buf.isEmpty()) {
            TreeNode curr = buf.peek();
            if (curr == null) {
                buf.pop();
                continue;
            }


            if (visited.contains(curr)) {
                TreeNode tmp = curr.left;
                curr.left = curr.right;
                curr.right = tmp;
                buf.pop();
            } else {
                buf.push(curr.left);
                buf.push(curr.right);
                visited.add(curr);
            }
        }

        return root;
    }
}
