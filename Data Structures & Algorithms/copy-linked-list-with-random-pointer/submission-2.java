/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        HashMap<Node, Node> nodeCopy = new HashMap<>();

        Node curr = head;
        Node dummy = new Node(0);
        Node currNew = dummy;

        while (curr != null) {
            currNew.next = new Node(curr.val);
            currNew = currNew.next;

            nodeCopy.put(curr, currNew);

            curr = curr.next;
        }

        currNew = dummy.next;
        curr = head;

        while (curr != null) {
            if (curr.random != null) {
                currNew.random = nodeCopy.get(curr.random);
            }

            curr = curr.next;
            currNew = currNew.next;
        }

        return dummy.next;
    }
}
