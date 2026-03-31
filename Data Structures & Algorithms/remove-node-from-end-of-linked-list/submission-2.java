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
    private void removeNode(ListNode prev, ListNode remove) {
        ListNode next = remove.next;
        prev.next = next;
    }

    private int getListSize(ListNode head) {
        int count = 0;

        while (head != null) {
            ++count;
            head = head.next;
        }

        return count;
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        int target = getListSize(head) - n;

        if (target == 0) {
            return head.next;
        }

        ListNode prev = null;
        ListNode curr = head;
        
        for (int i = 0; i < target; ++i) {
            prev = curr;
            curr = curr.next;
        }

        removeNode(prev, curr);

        return head;
    }
}
