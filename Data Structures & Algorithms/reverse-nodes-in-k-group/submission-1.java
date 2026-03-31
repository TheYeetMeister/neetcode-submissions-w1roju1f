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
    private ListNode kthEndNode(ListNode start, int k) {
        while (start != null && k > 0) {
            --k;
            start = start.next;
        }

        return start;
    }

    private void reverseListNodes(ListNode start, ListNode end) {
        ListNode prev = null;
        ListNode curr = start;

        while (prev != end) {
            ListNode tmp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = tmp;
        }
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0, head);
        ListNode curr = dummy;
        while (true) {
            ListNode end = kthEndNode(curr, k);

            if (end == null) {
                return dummy.next;
            }

            // starts reverse procedure
            ListNode startReverse = curr.next;
            ListNode afterEnd = end.next;

            reverseListNodes(startReverse, end);
            //when the list is reversed the position of startReverse and end are flipped
            //so startReverse is the end of the reversed portion, and end is the start
            curr.next = end;
            startReverse.next = afterEnd;

            //start a node before checking the next k nodes
            //, so the end of the reversed list
            curr = startReverse;
        }
    }
}
