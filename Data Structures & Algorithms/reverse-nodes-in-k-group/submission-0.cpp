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
    ListNode* reverseKNodes(ListNode* head, int k, ListNode*& afterNode) {
        afterNode = head->next;

        head->next = nullptr;

        for (int i = 1; i < k && afterNode; ++i) {
            ListNode* next = afterNode->next;
            afterNode->next = head;
            head = afterNode;
            afterNode = next;
        }

        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        dummy.next = head;

        ListNode* currNode = &dummy;
        ListNode* nextPart;

        ListNode* newTail;
        ListNode* newHead;

        while (currNode && currNode->next) {
            ListNode* count = currNode->next;
            int i = 0;

            for (; i < k && count; ++i, count = count->next);

            if (i != k) {
                break;
            }

            newTail = currNode->next;
            newHead = reverseKNodes(currNode->next, k, nextPart);
            currNode->next = newHead;
            newTail->next = nextPart;
            currNode = newTail;
        }

        return dummy.next;
    }
};
