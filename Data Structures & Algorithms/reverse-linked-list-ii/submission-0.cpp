/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverseListSec(ListNode* head, int length) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 0; i < length; ++i) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Head should be the tail of the reversed section
        head->next = curr;

        // prev should be the head of the reversed section
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;

        for (int i = 1; i < left; ++i) {
            curr = curr->next;
        }

        ListNode* prevHead = reverseListSec(curr->next, right - left + 1);
        curr->next = prevHead;

        return dummy->next;
    }
};