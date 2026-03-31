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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;

        boolean carryOver = false;
        while (l1 != null && l2 != null) {
            int val = l1.val + l2.val;

            if (carryOver) {
                ++val;
                carryOver = false;
            } 

            if (val >= 10) {
                carryOver = true;
                val %= 10;
            }

            curr.next = new ListNode(val);
            curr = curr.next;
            l1 = l1.next;
            l2 = l2.next;
        }

        while (l1 != null) {
            int val = l1.val;

            if (carryOver) {
                ++val;
                carryOver = false;
            }

            if (val >= 10) {
                carryOver = true;
                val %= 10;
            }

            curr.next = new ListNode(val);
            curr = curr.next;
            l1 = l1.next;
        }

        while (l2 != null) {
            int val = l2.val;

            if (carryOver) {
                ++val;
                carryOver = false;
            }

            if (val >= 10) {
                carryOver = true;
                val %= 10;
            }

            curr.next = new ListNode(val);
            curr = curr.next;
            l2 = l2.next;
        }

        if (carryOver) {
            curr.next = new ListNode(1);
        }

        return dummy.next;
    }
}
