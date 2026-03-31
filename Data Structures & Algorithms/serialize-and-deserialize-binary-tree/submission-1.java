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

public class Codec {
    final static char delimiter = '@';

    private String getNum(String serialized, int[] pos) {
        StringBuilder returnVal = new StringBuilder();

        char c = serialized.charAt(++pos[0]);

        while (c != delimiter) {
            returnVal.append(c);
            c = serialized.charAt(++pos[0]);
        }
        return returnVal.toString();
    } 

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) {
            return "";
        }

        Queue<TreeNode> buf = new LinkedList<>();
        buf.add(root);

        StringBuilder encodedTree = new StringBuilder();

        while (!buf.isEmpty()) {
            TreeNode curr = buf.poll();

            encodedTree.append(delimiter);
            if (curr != null) {
                encodedTree.append(Integer.toString(curr.val));

                buf.add(curr.left);
                buf.add(curr.right);
            }
        }

        encodedTree.append(delimiter);
        return encodedTree.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == "") {
            return null;
        }

        int[] pos = new int[1];
        String num = getNum(data, pos);

        TreeNode root = new TreeNode(Integer.parseInt(num));
        Queue<TreeNode> buf = new LinkedList();
        buf.add(root);

        while(!buf.isEmpty()) {
            TreeNode curr = buf.poll();

            num = getNum(data, pos);

            if (!num.isEmpty()) {
                curr.left = new TreeNode(Integer.parseInt(num));
                buf.add(curr.left);
            }

            num = getNum(data, pos);
            if (!num.isEmpty()) {
                curr.right = new TreeNode(Integer.parseInt(num));
                buf.add(curr.right);
            }
        }

        return root;
    }
}
