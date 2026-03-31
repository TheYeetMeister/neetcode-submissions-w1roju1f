/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    private ListNode removeNode(ListNode prev, ListNode remove) {
        ListNode next = remove.next;

        if (prev != null) {
            prev.next = next;
        }

        return next;
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode curr = head;
        ArrayList<ListNode> listIndexes = new ArrayList<>();
        for (; curr != null; curr = curr.next) {
            listIndexes.add(curr);
        }

        int i = listIndexes.size() - n;

        if (i == 0) {
            return removeNode(null, listIndexes.get(0));
        } else {
            removeNode(listIndexes.get(i - 1), listIndexes.get(i));

            return head;
        }
    }
}
