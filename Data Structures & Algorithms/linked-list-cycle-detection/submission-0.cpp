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
    bool hasCycle(ListNode* head) {
        ListNode* turtle = head;
        ListNode* hare = (head)? head->next: nullptr;

        while (turtle && hare) {
            if (turtle == hare) {
                return true;
            }

            turtle = turtle->next;

            hare = hare->next;

            if (!hare) {
                return false;
            } 

            hare = hare->next;
        }

        return false;
    }
};
