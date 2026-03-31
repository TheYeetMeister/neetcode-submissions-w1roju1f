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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryOver = 0;
        ListNode* l3Head = nullptr;
        ListNode* l3Tail = nullptr;

        while (l1 && l2) {
            int num = (carryOver + l1->val + l2->val) % 10;
            carryOver = (carryOver + l1->val + l2->val) / 10;

            if (!l3Head) {
                l3Head = new ListNode(num);
                l3Tail = l3Head;
            } else {
                l3Tail->next = new ListNode(num);
                l3Tail = l3Tail->next;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 || l2) {
            int val = (l1) ? l1->val: l2->val;
            int num = (carryOver + val) % 10;
            carryOver = (carryOver + val) / 10;

            if (!l3Head) {
                l3Head = new ListNode(num);
                l3Tail = l3Head;
            } else {
                l3Tail->next = new ListNode(num);
                l3Tail = l3Tail->next;
            }

            if (l1) {
                l1 = l1->next;
            } else {
                l2 = l2->next;
            }
        }

        if (carryOver) {
            l3Tail->next = new ListNode(carryOver);
        }

        return l3Head;
    }
};
