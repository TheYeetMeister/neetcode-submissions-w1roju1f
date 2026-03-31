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
    void reorderList(ListNode* head) {
        int size = 0;
        ListNode* tailHead = head;

        for (; tailHead; ++size, tailHead = tailHead->next);

        if (size < 2) {
            return;
        }

        tailHead = head;

        for (int i = 0; i < (size - 1) / 2; ++i) {
            tailHead = tailHead -> next;
        }

        ListNode* prev = tailHead;
        tailHead = tailHead->next;
        prev->next = nullptr;
        prev = nullptr;

        while(tailHead) {
            ListNode* next = tailHead->next;
            tailHead->next = prev;
            prev = tailHead;
            tailHead = next;
        }

        for (int i = 0; i < size / 2; ++i) {
            ListNode* headNext = head->next;
            ListNode* tailNext = prev->next;

            head->next = prev;
            prev->next = headNext;

            head = headNext;
            prev = tailNext;
        }
    }
};
