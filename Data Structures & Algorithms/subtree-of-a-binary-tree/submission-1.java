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
    private boolean sameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        }

        Stack<TreeNode> pBuf = new Stack<>();
        Stack<TreeNode> qBuf = new Stack<>();

        TreeNode currP = p;
        TreeNode currQ = q;

        while (currP != null || currQ != null || !pBuf.isEmpty() && !qBuf.isEmpty()) {
            if (currP == null && currQ == null) {
                currP = pBuf.pop();
                currQ = qBuf.pop();
            }

            if (currP == null || currQ == null || currP.val != currQ.val) {
                return false;
            }

            if (currP.right != null || currQ.right != null) {
                pBuf.push(currP.right);
                qBuf.push(currQ.right);
            }

            currP = currP.left;
            currQ = currQ.left;
        }

        return pBuf.isEmpty() && qBuf.isEmpty();
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (root == null && subRoot == null) {
            return true;
        }

        Stack<TreeNode> buf = new Stack<>();
        TreeNode curr = root;

        while (curr != null || !buf.isEmpty()) {
            if (curr == null) {
                curr = buf.pop();
            }

            if (sameTree(curr, subRoot)) {
                return true;
            }

            if (curr.right != null) {
                buf.push(curr.right);
            }

            curr = curr.left;
        } 
        return false;
    }
}
