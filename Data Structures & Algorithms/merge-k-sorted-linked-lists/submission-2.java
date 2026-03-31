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
    private ListNode mergeTwo(ListNode a, ListNode b) {
        ListNode dummy = new ListNode();
        ListNode curr = dummy;

        while (a != null && b != null) {
            if (a.val < b.val) {
                curr.next = a;
                a = a.next;
            } else {
                curr.next = b;
                b = b.next;
            }

            curr = curr.next;
        }

        if (a != null) {
            curr.next = a;
        } else if (b != null) {
            curr.next = b;
        }


        return dummy.next;
    }
    public ListNode mergeKLists(ListNode[] lists) {
        int size = lists.length;

        if (size == 0) {
            return null;
        }

        while (size > 1) {
            int half = size / 2;

            for (int i = 0; i < half; ++i) {
                lists[i] = mergeTwo(lists[i], lists[size - i - 1]);
            }

            size = (size + 1) / 2;
        }

        return lists[0];
    }
}
