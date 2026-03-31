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
    private int getListSize(ListNode head) {
        int size = 0;

        while (head != null) {
            ++size;
            head = head.next;
        }

        return size;
    }

    private ListNode reverseHalfOfList(ListNode head, int size) {
        int end = size / 2;

        for (int i = 0; i < end; ++i) {
            head = head.next;
        }

        ListNode prev = null;
        ListNode curr = head;

        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    public void reorderList(ListNode head) {
        int size = getListSize(head);
        if (size < 3) {
            return;
        }

        ListNode tail = reverseHalfOfList(head, size);

        while (tail.next != null) {
            ListNode headNext = head.next;
            ListNode tailNext = tail.next;

            head.next = tail;
            tail.next = headNext;

            head = headNext;
            tail = tailNext;
        }
    }
}
