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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tail = head;

        for (int i = 0; i < n && tail; ++i, tail = tail->next);

        if (!tail) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;

            return head;
        }

        ListNode* tailEnd = head;
        tail=tail->next;

        while (tail) {
            tail = tail -> next;
            tailEnd = tailEnd -> next;
        }

        ListNode* tmp = tailEnd;
        ListNode* tmpNext = tailEnd->next;
        ListNode* tmpLast = tmpNext->next;
        delete tmpNext;

        tmp->next = tmpLast;

        return head;
    }
};
