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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newHead = nullptr;
        ListNode* end = nullptr;

        while (list1 && list2) {
            ListNode* chosen ;
            if (list1->val < list2->val) {
                chosen = list1;
                list1 = list1->next;
            } else {
                chosen = list2;
                list2=list2->next;
            }

            if (newHead) {
                end->next = chosen;
                end = chosen;
            } else {
                newHead = chosen;
                end = chosen;
            }
        }

        ListNode* remaining = (list1) ? list1 : list2;

        if (end) {
            end->next = remaining;
        } else {
            newHead = remaining;
        }

        return newHead;
    }
};
