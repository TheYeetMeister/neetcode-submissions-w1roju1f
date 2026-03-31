/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        unordered_map<Node*, Node*> nodeValAddresses;

        //creates the new linked list
        Node* newHead = new Node(head->val);
        nodeValAddresses[head] = newHead;
        Node* tail = newHead;
        Node* originalTail = head->next;

        while (originalTail) {
            tail->next = new Node(originalTail->val);
            tail = tail->next;
            nodeValAddresses[originalTail] = tail;
            originalTail = originalTail->next;
        }

        //creating the random pointers
        tail = newHead;
        originalTail = head;

        while(originalTail) {
            if (originalTail->random) {
                tail->random = nodeValAddresses[originalTail->random];
            }
            originalTail = originalTail->next;
            tail = tail->next;
        }

        return newHead;
    }
};
