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
    Map<Integer, Integer> valToIndexInorder;
    int[] preorder;
    int[] inorder;

    private TreeNode dfs(int preOrderStart, int preOrderEnd, 
                        int inOrderStart, int inOrderEnd) {
        if (preOrderStart >= preOrderEnd) {
            return null;
        }

        int nodeVal = preorder[preOrderStart];
        int inOrderIndex = valToIndexInorder.get(nodeVal);

        int numOfLeft = inOrderIndex - inOrderStart;


        TreeNode left = dfs(preOrderStart + 1, preOrderStart + numOfLeft + 1,
                            inOrderStart, inOrderIndex);

        TreeNode right = dfs(preOrderStart + numOfLeft + 1, preOrderEnd,
                            inOrderIndex + 1, inOrderEnd);

        return new TreeNode(nodeVal, left, right);
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        this.preorder = preorder;
        this.inorder = inorder;
        valToIndexInorder = new HashMap<>();

        for (int i = 0; i < inorder.length; ++i) {
            valToIndexInorder.put(inorder[i], i);
        }

        return dfs(0, preorder.length, 0, inorder.length);
    }
}
