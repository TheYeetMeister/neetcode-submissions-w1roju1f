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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        bool noNodes;
        ListNode* dummyHead = new ListNode();
        ListNode* tail = dummyHead;

        int smallestNodeIndex;
        int smallestNodeVal;

        while (true) {
            noNodes = true;

            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] == nullptr) {
                    continue;
                }

                if (noNodes) {
                    noNodes = false;
                    smallestNodeIndex = i;
                    smallestNodeVal = lists[i]->val;
                } else if (smallestNodeVal > lists[i]->val) {
                    smallestNodeIndex = i;
                    smallestNodeVal = lists[i]->val;
                }
            }

            if (noNodes) {
                break;
            } else {
                tail->next = lists[smallestNodeIndex];
                tail = tail->next;
                lists[smallestNodeIndex] = lists[smallestNodeIndex]->next;
            }
        }

        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};
